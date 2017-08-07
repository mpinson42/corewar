/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_binary.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sol <sol@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 11:19:23 by apieropa          #+#    #+#             */
/*   Updated: 2015/03/06 17:31:11 by sol              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdint.h>
#include "ft_printf_types.h"
#include "ft_printf.h"

ssize_t		ft_printf_handle_binary(char **format, va_list *args, t_ptfa *arg)
{
	uintmax_t	nbr;

	(void)format;
	arg->conversion = 'b';
	nbr = ft_printf_apply_modifier_uint(args, arg);
	return (ft_printf_handle_unsigned(nbr, arg, "01", "0b"));
}
