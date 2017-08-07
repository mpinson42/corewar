/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sol <sol@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 15:20:54 by apieropa          #+#    #+#             */
/*   Updated: 2015/03/06 18:08:06 by sol              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

char		*ft_itoa(int n)
{
	int		cpy;
	char	*buff;
	int		len;
	int		i;

	if (n == INT_MIN && INT_MIN == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == INT_MIN && INT_MIN == -32768)
		return (ft_strdup("-32768"));
	len = ft_nbrlen(n);
	if ((buff = ft_strnew(len)) == NULL)
		return (NULL);
	cpy = n;
	len -= n >= 0 ? 0 : 1;
	i = 0;
	while (i < len)
	{
		buff[i] = ABS(cpy % 10) + '0';
		cpy /= 10;
		i++;
	}
	buff[i] = (n < 0 ? '-' : 0);
	return (ft_strrev(buff));
}
