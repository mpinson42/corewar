/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 12:05:10 by apieropa          #+#    #+#             */
/*   Updated: 2015/03/27 16:33:09 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		len_src;
	size_t		len_dst;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (size == 0)
		return (len_src);
	i = 0;
	while (src[i] != '\0' && len_dst + i < size - 1)
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	dst[len_dst + i] = '\0';
	if (size < len_dst)
		return (size + len_src);
	return (len_dst + len_src);
}
