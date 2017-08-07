/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 15:23:29 by mpinson           #+#    #+#             */
/*   Updated: 2017/07/21 15:23:35 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include <stdio.h>

int		ft_conv_int(unsigned char *str)
{
	unsigned char	*oct[4];
	int				i;
	int				b;

	i = 0;
	b = 0;
	oct[0] = unsigned_itoa_base2(str[0], 2);
	oct[1] = unsigned_itoa_base2(str[1], 2);
	oct[2] = unsigned_itoa_base2(str[2], 2);
	oct[3] = unsigned_itoa_base2(str[3], 2);
	while (i < 4)
	{
		b = unsigned_strlen(oct[i]);
		while (b < 8)
		{
			oct[i] = unsigned_strjoin((unsigned char *)"0", oct[i]);
			b++;
		}
		i++;
	}
	b = unsigned_atoi_base(unsigned_strjoin(
				unsigned_strjoin(unsigned_strjoin(oct[0], oct[1]),
					oct[2]), oct[3]), 2);
	return (b);
}

void	ft_conv2(unsigned int nb, unsigned char (*str)[4])
{
	unsigned char			*tmp;
	unsigned char			*bite[4];

	tmp = unsigned_itoa_base2(nb, 2);
	while (unsigned_strlen(tmp) < 32)
		tmp = unsigned_strjoin((unsigned char*)"0", tmp);
	bite[0] = unsigned_strsub(tmp, 32 - 8, 8);
	bite[1] = unsigned_strsub(tmp, 32 - 16, 8);
	bite[2] = unsigned_strsub(tmp, 32 - 24, 8);
	bite[3] = unsigned_strsub(tmp, 0, 32 - 24);
	str[0][3] = unsigned_atoi_base(bite[0], 2);
	str[0][2] = unsigned_atoi_base(bite[1], 2);
	str[0][1] = unsigned_atoi_base(bite[2], 2);
	str[0][0] = unsigned_atoi_base(bite[3], 2);
}

int		ft_chr_leng(char *str)
{
	char	str2[4096];
	int		fd;
	int		i;

	i = 0;
	if ((fd = open(str, O_RDONLY)) == -1)
	{
		ft_putstr("error open failed\n");
		return (-1);
	}
	read(fd, str2, 4 + (128 + 4) + 4 + (2048 + 4));
	while (read(fd, str2, 1))
		i++;
	close(fd);
	return (i);
}

int		ft_cher_leng_file(char *str)
{
	char	str2[4096];
	int		fd;
	int		i;

	i = 0;
	if ((fd = open(str, O_RDONLY)) == -1)
	{
		ft_putstr("error open failed\n");
		return (-1);
	}
	while (read(fd, str2, 1))
		i++;
	close(fd);
	return (i);
}
