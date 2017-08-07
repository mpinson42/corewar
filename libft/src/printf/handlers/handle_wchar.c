/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sol <sol@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 11:19:23 by apieropa          #+#    #+#             */
/*   Updated: 2015/03/06 17:31:11 by sol              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <wchar.h>
#include "libft.h"
#include "ft_printf.h"
#include "ft_printf_types.h"

ssize_t		ft_printf_handle_wchar(char **format, va_list *args, t_ptfa *arg)
{
	wchar_t		chr;
	unsigned	chr_len;

	(void)format;
	chr = (wchar_t)va_arg(*args, wint_t);
	if (chr <= 0x7F)
		chr_len = 1;
	else if (chr <= 0x7FF)
		chr_len = 2;
	else if (chr <= 0xFFFF)
		chr_len = 3;
	else if (chr <= 0x10FFFF)
		chr_len = 4;
	else
		chr_len = 0;
	if (arg->has_minwidth && !arg->right_pad)
		ft_printf_print_padding(arg->minwidth - 1, ' ', arg->fd);
	ft_putwchar_fd(chr, arg->fd);
	if (arg->has_minwidth && arg->right_pad)
		ft_printf_print_padding(arg->minwidth - 1, ' ', arg->fd);
	return (arg->has_minwidth ? MAX(chr_len, arg->minwidth) : chr_len);
}
