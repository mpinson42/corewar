/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sol <sol@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 14:42:47 by apieropa          #+#    #+#             */
/*   Updated: 2016/11/28 15:35:29 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	char				*str;

	if ((str = (char *)malloc(sizeof(char) * (size + 1))) == NULL)
		return (NULL);
	ft_memset(str, 0, size + 1);
	return (str);
}
