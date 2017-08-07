/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbrlen.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sol <sol@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 11:19:23 by apieropa          #+#    #+#             */
/*   Updated: 2015/03/06 17:31:11 by sol              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <inttypes.h>
#include <sys/types.h>
#include "libft.h"
#include "ft_printf_types.h"

uint		ft_printf_nbrlen(intmax_t nbr, char *base)
{
	long int	baselen;
	uint		i;

	baselen = ft_strlen(base);
	i = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr /= baselen;
		i++;
	}
	return (i);
}

uint		ft_printf_nbrlen_unsigned(uintmax_t nbr, char *base)
{
	size_t		base_nbr;
	uint		i;

	base_nbr = ft_strlen(base);
	i = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr /= base_nbr;
		i++;
	}
	return (i);
}

uint		ft_printf_full_nbrlen(intmax_t nbr,
	t_ptfa *arg, char *base, char *prefix)
{
	uint		i;

	i = ft_printf_nbrlen(nbr, base);
	if (arg->has_precision)
		i = MAX(arg->precision, i);
	if (arg->conversion == 'p' || (arg->alternate_form && nbr != 0))
		i += ft_strlen(prefix);
	if (arg->force_sign == 1 || arg->force_blank == 1 || nbr < 0)
		i++;
	if (arg->zero_padding && arg->has_minwidth && arg->minwidth >= i)
		i = arg->minwidth;
	if (nbr == 0 && arg->has_precision && arg->precision == 0)
		i = 0;
	if (nbr == 0 && arg->conversion == 'o' && arg->alternate_form == 1)
		i = 1;
	return (i);
}

uint		ft_printf_full_nbrlen_unsigned(uintmax_t nbr,
	t_ptfa *arg, char *base, char *prefix)
{
	uint		i;

	i = ft_printf_nbrlen_unsigned(nbr, base);
	if (arg->has_precision)
		i = MAX(arg->precision, i);
	if (arg->conversion == 'p' || (arg->alternate_form && nbr != 0))
		i += ft_strlen(prefix);
	if (arg->zero_padding && arg->has_minwidth && arg->minwidth >= i)
		i = arg->minwidth;
	if (nbr == 0 && arg->has_precision && arg->precision == 0)
		i = 0;
	if (nbr == 0 && arg->conversion == 'o' && arg->alternate_form == 1)
		i = 1;
	return (i);
}
