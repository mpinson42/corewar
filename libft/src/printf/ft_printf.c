/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
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

static ssize_t	ft_printf_handle(char **format,
	va_list *args, t_ptfa *arg)
{
	ssize_t		ret;
	t_ptfh		handler;

	if ((*(++*format)) == '\0')
		return (0);
	if ((ft_printf_parse_flags(format, arg)) == NULL)
		return (-1);
	if ((ft_printf_parse_width(format, args, arg)) == NULL)
		return (-1);
	if ((ft_printf_parse_precision(format, args, arg)) == NULL)
		return (-1);
	if ((ft_printf_parse_modifier(format, arg)) == NULL)
		return (-1);
	if (**format == '\0')
		return (0);
	handler = ft_printf_get_handler(**format);
	arg->zero_padding = (arg->has_precision ? 0 : arg->zero_padding);
	ret = handler(format, args, arg);
	(*format)++;
	return (ret);
}

int				ft_printf_exec_arg(const char *format,
	va_list *args, size_t tot_len, int fd)
{
	t_ptfa	arg;
	ssize_t	hdr_len;

	ft_bzero(&arg, sizeof(arg));
	arg.fd = fd;
	if ((hdr_len = ft_printf_handle((char**)&format, args, &arg)) == -1)
		return (-1);
	else
		return (ft_printf_core(format, args, tot_len + hdr_len, fd));
}

int				ft_printf_core(const char *format,
	va_list *args, size_t tot_len, int fd)
{
	char	*nfmt;

	nfmt = ft_strchr(format, '%');
	if (*format == '\0')
		return (tot_len);
	if (nfmt == NULL)
	{
		ft_putstr_fd(format, fd);
		return (tot_len + ft_strlen(format));
	}
	else if (nfmt > format)
	{
		write(fd, format, nfmt - format);
		return (ft_printf_core(nfmt, args, tot_len + (nfmt - format), fd));
	}
	else
		return (ft_printf_exec_arg(format, args, tot_len, fd));
}

int				ft_printf(const char *format, ...)
{
	va_list	args;
	int		ret;

	va_start(args, format);
	ret = ft_printf_core(format, &args, 0, STDOUT_FILENO);
	va_end(args);
	return (ret);
}

int				ft_printf_fd(int fd, const char *format, ...)
{
	va_list	args;
	int		ret;

	va_start(args, format);
	ret = ft_printf_core(format, &args, 0, fd);
	va_end(args);
	return (ret);
}
