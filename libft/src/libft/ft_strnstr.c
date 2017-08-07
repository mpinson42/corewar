/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 16:50:01 by apieropa          #+#    #+#             */
/*   Updated: 2015/03/27 17:40:19 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	len_s2;

	len_s2 = ft_strlen(s2);
	if (n < len_s2)
		return (NULL);
	i = 0;
	while (s1[i] != '\0' && i + len_s2 <= n)
	{
		if (ft_strncmp(s1 + i, s2, len_s2) == 0)
			return ((char *)s1 + i);
		i++;
	}
	return (NULL);
}
