/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sol <sol@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 11:19:23 by apieropa          #+#    #+#             */
/*   Updated: 2015/03/06 17:31:11 by sol              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "ft_printf_types.h"
#include "ft_printf.h"

ssize_t		ft_printf_handle_char(char **format, va_list *args, t_ptfa *arg)
{
	(void)format;
	arg->conversion = 'c';
	if (arg->modifier == l)
		return (ft_printf_handle_wchar(format, args, arg));
	else
	{
		if (arg->has_minwidth && !arg->right_pad)
			ft_printf_print_padding(arg->minwidth - 1, \
				arg->zero_padding ? '0' : ' ', arg->fd);
		ft_putchar_fd(va_arg(*args, int), arg->fd);
		if (arg->has_minwidth && arg->right_pad)
			ft_printf_print_padding(arg->minwidth - 1, \
				arg->zero_padding ? '0' : ' ', arg->fd);
		return (arg->has_minwidth ? MAX(arg->minwidth, 1) : 1);
	}
}
