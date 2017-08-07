/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sol <sol@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 04:47:19 by apieropa          #+#    #+#             */
/*   Updated: 2015/03/06 18:48:26 by sol              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t	i;
	void	*str;

	if (size == 0)
		return (NULL);
	if ((str = malloc(size)) == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		((char *)str)[i] = '\0';
		i++;
	}
	return (str);
}
