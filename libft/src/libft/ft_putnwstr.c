/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnwstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sol <sol@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 11:19:23 by apieropa          #+#    #+#             */
/*   Updated: 2015/03/06 17:31:11 by sol              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnwstr(const wchar_t *str, size_t len)
{
	size_t	i;

	i = 0;
	while (*str && i < len)
	{
		if (*str <= 0x7F)
			i++;
		else if (*str <= 0x7FF)
			i += 2;
		else if (*str <= 0xFFFF)
			i += 3;
		else if (*str <= 0x10FFFF)
			i += 4;
		if (i <= len)
			ft_putwchar(*str++);
	}
}
