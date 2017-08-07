/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sol <sol@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 11:19:23 by apieropa          #+#    #+#             */
/*   Updated: 2015/03/06 17:31:11 by sol              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdint.h>
#include "libft.h"
#include "ft_printf_types.h"
#include "ft_printf.h"

ssize_t		ft_printf_handle_int(char **format, va_list *args, t_ptfa *arg)
{
	intmax_t				nbr;

	(void)format;
	nbr = ft_printf_apply_modifier_int(args, arg);
	return (ft_printf_handle_signed(nbr, arg, "0123456789", NULL));
}
