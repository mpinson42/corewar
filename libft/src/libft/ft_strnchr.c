/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 15:03:02 by apieropa          #+#    #+#             */
/*   Updated: 2015/03/27 20:07:05 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnchr(const char *s, int c, size_t n)
{
	int		i;

	i = 0;
	while (n > 0)
	{
		while (s[i] != (char)c && s[i] != '\0')
			i++;
		if (s[i] == '\0')
			return (NULL);
		n--;
		if (n != 0)
			i++;
	}
	return (s[i] == (char)c && s[i] != '\0' ? (char *)&(s[i]) : NULL);
}
