/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 15:22:37 by mpinson           #+#    #+#             */
/*   Updated: 2017/07/21 15:22:46 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

unsigned char			*unsigned_strsub(unsigned char *s,
	unsigned int start, unsigned len)
{
	unsigned int			i;
	unsigned char			*str;

	if (!s)
		return (NULL);
	i = 0;
	if (!(str = (unsigned char *)malloc(sizeof(unsigned char) * len + 1)))
		return (NULL);
	while (i < len)
	{
		str[i] = s[start];
		start++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

static int				ft_get_len(uintmax_t n, int base)
{
	unsigned int i;

	i = 0;
	while (n != 0)
	{
		n = n / base;
		i++;
	}
	return (i);
}

static unsigned char	*ft_neg(unsigned int n, int base, unsigned int len)
{
	unsigned char		*str;
	unsigned char		*cmp;
	unsigned int		i;

	i = 1;
	cmp = (unsigned char *)"0123456789abcdef";
	if (!(str = (unsigned char *)malloc(sizeof(unsigned char) * (len + 2))))
		return (NULL);
	str[0] = '-';
	str[len + 2] = 0;
	while (len + 1)
	{
		str[len + 1] = cmp[n % base];
		n = n / base;
		len--;
	}
	if (str[1] == '0')
		str = unsigned_strsub(str, 2, unsigned_strlen(str) - 2);
	unsigned_strjoin((unsigned char *)"-", str);
	return (str);
}

static unsigned char	*init(unsigned int *neg, unsigned int *i)
{
	unsigned char *cmp;

	cmp = (unsigned char *)"0123456789abcdef";
	neg[0] = 1;
	i[0] = 0;
	return (cmp);
}

unsigned char			*unsigned_itoa_base2(unsigned int n,
	int base)
{
	unsigned int		tab[3];
	unsigned char		*str;
	unsigned char		*cmp;

	cmp = init(&tab[2], &tab[0]);
	tab[1] = ft_get_len(n, base);
	tab[2] = 1;
	if (n == 0)
		return (unsigned_strdup((unsigned char *)"0"));
	if (tab[2] && !(str = (unsigned char *)malloc(sizeof(unsigned char)
		* (tab[1] + 1))))
		return (NULL);
	else
		return (ft_neg(n, base, tab[1]));
	str[tab[1] + 1] = 0;
	while (tab[1] + 1)
	{
		str[tab[1]] = cmp[n % base];
		n = n / base;
		tab[1]--;
	}
	if (str[0] == '0')
		str = unsigned_strsub(str, 1, unsigned_strlen(str) - 1);
	return (str);
}
