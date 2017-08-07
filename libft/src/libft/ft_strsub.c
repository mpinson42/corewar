/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 17:10:40 by apieropa          #+#    #+#             */
/*   Updated: 2014/09/28 12:57:29 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(const char *s, size_t start, size_t len)
{
	char	*str;

	if ((str = ft_strnew(len)) == NULL)
		return (NULL);
	ft_strncpy(str, (char *)s + start, len);
	return (str);
}
