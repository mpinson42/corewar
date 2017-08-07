/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 15:23:17 by apieropa          #+#    #+#             */
/*   Updated: 2014/09/28 12:56:11 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*s2;
	int		len;

	len = ft_strlen((char *)s);
	s2 = ft_strnew(len);
	i = 0;
	while (i < len)
	{
		s2[i] = (*f)(i, s[i]);
		i++;
	}
	return (s2);
}
