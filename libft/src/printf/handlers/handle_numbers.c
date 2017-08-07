/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_unsigned.c                                  :+:      :+:    :+:   */
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
#include "ft_printf.h"
#include "ft_printf_types.h"

static void		ft_printf_putnbr_signed(intmax_t nbr,
	t_ptfa *arg, char *base, char *prefix)
{
	int		nbrlen;
	int		padding;

	nbrlen = ft_printf_nbrlen(nbr, base);
	padding = ft_printf_full_nbrlen(nbr, arg, base, prefix) - nbrlen;
	if (nbr < 0)
		ft_putchar_fd('-', arg->fd);
	else if (arg->force_sign || arg->force_blank)
		ft_putchar_fd(arg->force_sign ? '+' : ' ', arg->fd);
	if (nbr < 0 || arg->force_sign || arg->force_blank)
		padding--;
	if (arg->conversion == 'p')
		padding -= ft_strlen(prefix);
	if (arg->conversion == 'p')
		ft_putstr_fd(prefix, arg->fd);
	if (arg->conversion == 'x' && (arg->alternate_form && nbr != 0))
		padding -= ft_strlen(prefix);
	if (arg->conversion == 'x' && (arg->alternate_form && nbr != 0))
		ft_putstr_fd(prefix, arg->fd);
	if (padding > 0)
		ft_printf_print_padding(padding, '0', arg->fd);
	if (!(nbr == 0 && arg->has_precision && arg->precision == 0 && \
		arg->conversion != 'o'))
		ft_printf_putnbr_base(nbr, base, arg->fd);
}

static void		ft_printf_putnbr_unsigned(uintmax_t nbr,
	t_ptfa *arg, char *base, char *prefix)
{
	int		nbrlen;
	int		padding;

	nbrlen = ft_printf_nbrlen_unsigned(nbr, base);
	padding = ft_printf_full_nbrlen_unsigned(nbr, arg, base, prefix) - nbrlen;
	if (arg->conversion == 'p')
		padding -= ft_strlen(prefix);
	if (arg->conversion == 'p')
		ft_putstr_fd(prefix, arg->fd);
	if (arg->conversion == 'x' && (arg->alternate_form && nbr != 0))
		padding -= ft_strlen(prefix);
	if (arg->conversion == 'x' && (arg->alternate_form && nbr != 0))
		ft_putstr_fd(prefix, arg->fd);
	if (padding > 0)
		ft_printf_print_padding(padding, '0', arg->fd);
	if (!(nbr == 0 && arg->has_precision && arg->precision == 0 && \
		arg->conversion != 'o'))
		ft_printf_putnbr_base_unsigned(nbr, base, arg->fd);
}

ssize_t			ft_printf_handle_signed(intmax_t nbr, t_ptfa *arg,
	char *base, char *prefix)
{
	uint	full_nbrlen;
	uint	width;

	if (arg->has_precision)
		arg->zero_padding = 0;
	full_nbrlen = ft_printf_full_nbrlen(nbr, arg, base, prefix);
	width = full_nbrlen;
	if (arg->has_minwidth && arg->minwidth > full_nbrlen)
		width = arg->minwidth;
	if (!arg->right_pad && width > full_nbrlen)
		ft_printf_print_padding(width - full_nbrlen, ' ', arg->fd);
	if (nbr == 0 && arg->has_precision && arg->precision == 0)
		return (arg->has_minwidth ? arg->minwidth : 0);
	ft_printf_putnbr_signed(nbr, arg, base, prefix);
	if (arg->right_pad && width > full_nbrlen)
		ft_printf_print_padding(width - full_nbrlen, ' ', arg->fd);
	return (width);
}

ssize_t			ft_printf_handle_unsigned(uintmax_t nbr, t_ptfa *arg,
	char *base, char *prefix)
{
	uint	full_nbrlen;
	uint	width;

	if (arg->has_precision)
		arg->zero_padding = 0;
	full_nbrlen = ft_printf_full_nbrlen_unsigned(nbr, arg, base, prefix);
	width = full_nbrlen;
	if (arg->has_minwidth && arg->minwidth > full_nbrlen)
		width = arg->minwidth;
	if (!arg->right_pad && width > full_nbrlen)
		ft_printf_print_padding(width - full_nbrlen, ' ', arg->fd);
	if (nbr == 0 && arg->has_precision && arg->precision == 0 && \
		arg->alternate_form == 0)
		return (arg->has_minwidth ? arg->minwidth : 0);
	ft_printf_putnbr_unsigned(nbr, arg, base, prefix);
	if (arg->right_pad && width > full_nbrlen)
		ft_printf_print_padding(width - full_nbrlen, ' ', arg->fd);
	return (width);
}
