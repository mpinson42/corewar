/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sol <sol@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 11:19:23 by apieropa          #+#    #+#             */
/*   Updated: 2015/03/06 17:31:11 by sol              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"
#include "ft_printf_types.h"

ssize_t		ft_printf_handle_str(char **format, va_list *args, t_ptfa *arg)
{
	char	*str;
	size_t	strlen;

	arg->conversion = 's';
	if (arg->modifier == l)
		return (ft_printf_handle_wstr(format, args, arg));
	else
	{
		str = va_arg(*args, char*);
		if (str == NULL)
			str = "(null)";
		strlen = ft_strlen(str);
		if (arg->has_precision && arg->precision < strlen)
			strlen = arg->precision;
		if (arg->has_minwidth && !arg->right_pad && arg->minwidth > strlen)
			ft_printf_print_padding(arg->minwidth - strlen, \
				arg->zero_padding ? '0' : ' ', arg->fd);
		write(arg->fd, str, strlen);
		if (arg->has_minwidth && arg->right_pad && arg->minwidth > strlen)
			ft_printf_print_padding(arg->minwidth - strlen, \
				arg->zero_padding ? '0' : ' ', arg->fd);
		return (arg->has_minwidth ? MAX(strlen, arg->minwidth) : strlen);
	}
}
