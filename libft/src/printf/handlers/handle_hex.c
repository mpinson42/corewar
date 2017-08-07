/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sol <sol@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 11:19:23 by apieropa          #+#    #+#             */
/*   Updated: 2015/03/06 17:31:11 by sol              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"
#include "ft_printf_types.h"
#include "ft_printf.h"

ssize_t		ft_printf_handle_hex(char **format, va_list *args, t_ptfa *arg)
{
	uintmax_t	nbr;

	(void)format;
	arg->conversion = 'x';
	nbr = ft_printf_apply_modifier_uint(args, arg);
	if (**format == 'X')
		return (ft_printf_handle_unsigned(nbr, arg, "0123456789ABCDEF", "0X"));
	else
		return (ft_printf_handle_unsigned(nbr, arg, "0123456789abcdef", "0x"));
}
