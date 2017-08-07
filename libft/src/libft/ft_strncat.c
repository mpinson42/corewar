/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 10:07:02 by apieropa          #+#    #+#             */
/*   Updated: 2014/09/28 13:49:14 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		offset;

	offset = ft_strlen(s1);
	i = 0;
	while (s2[i] != '\0' && i < n)
	{
		s1[offset + i] = s2[i];
		i++;
	}
	s1[offset + i] = '\0';
	return (s1);
}
