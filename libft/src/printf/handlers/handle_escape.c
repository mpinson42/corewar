/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_escape.c                                    :+:      :+:    :+:   */
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

ssize_t		ft_printf_handle_escape(char **format, va_list *args, t_ptfa *arg)
{
	ssize_t	strlen;

	(void)format;
	(void)args;
	arg->conversion = 'e';
	strlen = 1;
	if (arg->has_minwidth && !arg->right_pad && arg->minwidth > strlen)
		ft_printf_print_padding(arg->minwidth - strlen, \
			arg->zero_padding ? '0' : ' ', arg->fd);
	ft_putchar_fd('%', arg->fd);
	if (arg->has_minwidth && arg->right_pad && arg->minwidth > strlen)
		ft_printf_print_padding(arg->minwidth - strlen, ' ', arg->fd);
	return (arg->has_minwidth ? MAX(strlen, arg->minwidth) : strlen);
}
