/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse.c                                  :+:      :+:    :+:   */
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

char	*ft_printf_parse_flags(char **format, t_ptfa *arg)
{
	if (**format == '#' || **format == '0' || **format == '-' ||
		**format == '+' || **format == ' ')
	{
		if (**format == '#')
			arg->alternate_form = 1;
		else if (**format == '0')
			arg->zero_padding = 1;
		else if (**format == '-')
			arg->right_pad = 1;
		else if (**format == '+')
			arg->force_sign = 1;
		else if (**format == ' ')
			arg->force_blank = 1;
		(*format)++;
		if (arg->right_pad)
			arg->zero_padding = 0;
		return (ft_printf_parse_flags(format, arg));
	}
	else
		return (*format);
}

char	*ft_printf_parse_width(char **format, va_list *list, t_ptfa *arg)
{
	int	width;

	arg->minwidth = 0;
	while (**format == '*' || ft_isdigit(**format))
	{
		if (**format == '*')
		{
			(*format)++;
			if ((width = va_arg(*list, int)) < 0)
				arg->right_pad = 1;
			arg->has_minwidth = 1;
			arg->minwidth = ABS(width);
		}
		else
		{
			arg->has_minwidth = 1;
			arg->minwidth = 0;
			while (ft_isdigit(**format))
				arg->minwidth = arg->minwidth * 10 + (*(*format)++ - '0');
		}
	}
	return (*format);
}

char	*ft_printf_parse_precision(char **format, va_list *list, t_ptfa *arg)
{
	int precision;

	if (**format == '.')
	{
		(*format)++;
		if (**format == '*')
		{
			(*format)++;
			if ((precision = va_arg(*list, int)) >= 0)
			{
				arg->has_precision = 1;
				arg->precision = precision;
			}
			return (*format);
		}
		else
		{
			while (ft_isdigit(**format))
				arg->precision = arg->precision * 10 + (*(*format)++ - '0');
			arg->has_precision = 1;
			return (*format);
		}
	}
	else
		return (*format);
}

char	*ft_printf_parse_modifier(char **format, t_ptfa *arg)
{
	if (**format == 'h' && *(*format + 1) == 'h')
	{
		arg->modifier = hh;
		return (*format += 2);
	}
	else if (**format == 'l' && *(*format + 1) == 'l')
	{
		arg->modifier = ll;
		return (*format += 2);
	}
	else if (**format == 'h' || **format == 'l' ||
		**format == 'j' || **format == 'z')
	{
		if (**format == 'h')
			arg->modifier = h;
		else if (**format == 'l')
			arg->modifier = l;
		else if (**format == 'j')
			arg->modifier = j;
		else if (**format == 'z')
			arg->modifier = z;
		return ((*format)++);
	}
	else
		return (*format);
}
