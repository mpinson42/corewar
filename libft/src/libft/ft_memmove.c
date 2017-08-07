/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 18:41:47 by apieropa          #+#    #+#             */
/*   Updated: 2014/09/28 12:48:16 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *s1, const void *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return ((void *)s1);
	if (s1 < s2)
		return (ft_memcpy(s1, s2, n));
	i = n - 1;
	while (i != 0)
	{
		((char *)s1)[i] = ((char *)s2)[i];
		i--;
	}
	((char *)s1)[0] = ((char *)s2)[0];
	return ((void *)s1);
}
