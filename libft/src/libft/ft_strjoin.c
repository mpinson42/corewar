/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 17:45:06 by apieropa          #+#    #+#             */
/*   Updated: 2014/09/28 12:56:14 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(const char *s1, const char *s2)
{
	int		len;
	char	*s3;

	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	if ((s3 = ft_strnew(len)) == NULL)
		return (NULL);
	ft_strcpy((char *)s3, (char *)s1);
	ft_strcat((char *)s3, (char *)s2);
	return (s3);
}
