/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 15:23:42 by mpinson           #+#    #+#             */
/*   Updated: 2017/07/21 15:23:46 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int						check3(unsigned char *str, int base)
{
	int	i;
	int nb;

	nb = 0;
	i = 0;
	while (ft_isdigit(str[i]) || (str[i] >= 97 && str[i] <= 122) ||
			(str[i] >= 65 && str[i] <= 90))
	{
		nb = nb * base;
		if (str[i] >= 48 && str[i] <= 57)
		{
			nb = nb + (str[i] - 48);
		}
		else if (str[i] >= 97 && str[i] <= 122)
			nb = nb + (str[i] - 97 + 10);
		else if (str[i] >= 65 && str[i] <= 90)
			nb = nb + (str[i] - 65 + 10);
		i++;
	}
	return (nb);
}

int						unsigned_atoi_base(unsigned char *str, int base)
{
	int i;
	int neg;

	i = 0;
	neg = 1;
	while (str[i] == '\n' || str[i] == '\v' || str[i] == '\t' || str[i] == '\r'
			|| str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	return (check3(&str[i], base) * neg);
}

unsigned int			unsigned_strlen(unsigned char *s)
{
	int i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

unsigned char			*unsigned_strjoin(unsigned char *s1, unsigned char *s2)
{
	unsigned char	*str;
	int				i;
	unsigned char	*temp_str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = (unsigned_strlen(s1) + unsigned_strlen(s2));
	if (!(str = (unsigned char *)malloc(sizeof(*str) * (i + 1))))
		return (NULL);
	temp_str = str;
	while (*s1 != '\0')
		*temp_str++ = *s1++;
	while (*s2 != '\0')
		*temp_str++ = *s2++;
	*temp_str++ = '\0';
	return (str);
}

unsigned char			*unsigned_strdup(unsigned char *src)
{
	unsigned char	*str;
	size_t			i;

	if (src == NULL)
		return (NULL);
	i = 0;
	if (!(str = (unsigned char*)malloc(sizeof(unsigned char) *
		unsigned_strlen(src) + 1)))
		return (NULL);
	while (i < unsigned_strlen(src))
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
