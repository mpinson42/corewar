/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wstr.c                                      :+:      :+:    :+:   */
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

static size_t	ft_printf_wstrlen(wchar_t *str)
{
	size_t i;

	i = 0;
	while (*str)
	{
		if (*str <= 0x7F)
			i++;
		else if (*str <= 0x7FF)
			i += 2;
		else if (*str <= 0xFFFF)
			i += 3;
		else if (*str <= 0x10FFFF)
			i += 4;
		str++;
	}
	return (i);
}

ssize_t			ft_printf_handle_wstr(char **format, va_list *args, t_ptfa *arg)
{
	wchar_t	*str;
	size_t	strlen;

	(void)format;
	str = va_arg(*args, wchar_t*);
	if (str == NULL)
		str = L"(null)";
	strlen = ft_printf_wstrlen(str);
	if (arg->has_precision && arg->precision < strlen)
		strlen = arg->precision;
	if (arg->has_minwidth && !arg->right_pad && arg->minwidth > strlen)
		ft_printf_print_padding(arg->minwidth - strlen, ' ', arg->fd);
	ft_putnwstr(str, strlen);
	if (arg->has_minwidth && arg->right_pad && arg->minwidth > strlen)
		ft_printf_print_padding(arg->minwidth - strlen, ' ', arg->fd);
	return (arg->has_minwidth ? MAX(strlen, arg->minwidth) : strlen);
}
