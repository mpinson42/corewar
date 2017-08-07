/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 15:42:40 by apieropa          #+#    #+#             */
/*   Updated: 2015/03/27 16:55:24 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		len_s2;

	len_s2 = ft_strlen(s2);
	if (s2[0] == '\0')
		return ((char *)s1);
	i = 0;
	while (s1[i] != '\0')
	{
		if (ft_strncmp(s1 + i, s2, len_s2) == 0)
			return ((char *)s1 + i);
		i++;
	}
	return (NULL);
}
