/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_padding.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sol <sol@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 11:19:23 by apieropa          #+#    #+#             */
/*   Updated: 2015/03/06 17:31:11 by sol              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printf_print_padding(int width, char padchar, int fd)
{
	while (width--)
		ft_putchar_fd(padchar, fd);
}
