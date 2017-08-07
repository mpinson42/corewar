/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 16:57:11 by apieropa          #+#    #+#             */
/*   Updated: 2014/09/28 12:56:22 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcat(char *s1, const char *s2)
{
	int		i;
	int		offset;

	offset = ft_strlen(s1);
	i = 0;
	while (s2[i] != '\0')
	{
		s1[offset + i] = s2[i];
		i++;
	}
	s1[offset + i] = '\0';
	return (s1);
}
