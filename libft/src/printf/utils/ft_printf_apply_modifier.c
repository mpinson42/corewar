/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_apply_modifier.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sol <sol@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 11:19:23 by apieropa          #+#    #+#             */
/*   Updated: 2015/03/06 17:31:11 by sol              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <sys/types.h>
#include <stdarg.h>
#include "ft_printf.h"
#include "ft_printf_types.h"

uintmax_t	ft_printf_apply_modifier_uint(va_list *args, t_ptfa *arg)
{
	uintmax_t	nbr;

	nbr = va_arg(*args, uintmax_t);
	if (arg->modifier == hh)
		nbr = (unsigned char)nbr;
	else if (arg->modifier == h)
		nbr = (unsigned short int)nbr;
	else if (arg->modifier == l)
		nbr = (unsigned long int)nbr;
	else if (arg->modifier == ll)
		nbr = (unsigned long long int)nbr;
	else if (arg->modifier == j)
		nbr = (uintmax_t)nbr;
	else if (arg->modifier == z)
		nbr = (size_t)nbr;
	else
		nbr = (unsigned int)nbr;
	return (nbr);
}

intmax_t	ft_printf_apply_modifier_int(va_list *args, t_ptfa *arg)
{
	intmax_t	nbr;

	nbr = va_arg(*args, intmax_t);
	if (arg->modifier == hh)
		nbr = (char)nbr;
	else if (arg->modifier == h)
		nbr = (short int)nbr;
	else if (arg->modifier == l)
		nbr = (long int)nbr;
	else if (arg->modifier == ll)
		nbr = (long long int)nbr;
	else if (arg->modifier == j)
		nbr = (intmax_t)nbr;
	else if (arg->modifier == z)
		nbr = (size_t)nbr;
	else
		nbr = (int)nbr;
	return (nbr);
}
