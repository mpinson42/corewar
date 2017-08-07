/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_handler_arr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sol <sol@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 11:19:23 by apieropa          #+#    #+#             */
/*   Updated: 2015/03/06 17:31:11 by sol              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static void	ft_printf_handlers_init(t_ptfh *handlers)
{
	handlers['%'] = &ft_printf_handle_escape;
	handlers['s'] = &ft_printf_handle_str;
	handlers['S'] = &ft_printf_handle_wstr;
	handlers['p'] = &ft_printf_handle_ptr;
	handlers['d'] = &ft_printf_handle_int;
	handlers['D'] = &ft_printf_handle_long;
	handlers['i'] = &ft_printf_handle_int;
	handlers['o'] = &ft_printf_handle_octal;
	handlers['O'] = &ft_printf_handle_long;
	handlers['u'] = &ft_printf_handle_uint;
	handlers['U'] = &ft_printf_handle_long;
	handlers['x'] = &ft_printf_handle_hex;
	handlers['X'] = &ft_printf_handle_hex;
	handlers['c'] = &ft_printf_handle_char;
	handlers['C'] = &ft_printf_handle_wchar;
	handlers['b'] = &ft_printf_handle_binary;
}

t_ptfh		ft_printf_get_handler(char c)
{
	static t_bool	inited = FALSE;
	static t_ptfh	handlers[sizeof(unsigned char)] = {0};
	t_ptfh			handler;

	if (inited == FALSE && 1 + 0 * (inited = TRUE))
		ft_printf_handlers_init(handlers);
	if ((handler = handlers[(int)c]) == NULL)
		return (ft_printf_handle_null);
	return (handlers[(int)c]);
}
