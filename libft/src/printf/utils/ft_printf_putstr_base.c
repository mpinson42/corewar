/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putstr_base.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sol <sol@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 11:19:23 by apieropa          #+#    #+#             */
/*   Updated: 2015/03/06 17:31:11 by sol              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "libft.h"

void		ft_printf_putnbr_base(intmax_t nb, char *base, int fd)
{
	long int	len;

	len = ft_strlen(base);
	if (nb / len == 0)
		ft_putchar_fd(base[ABS(nb)], fd);
	else
	{
		ft_printf_putnbr_base(nb / len, base, fd);
		ft_printf_putnbr_base(ABS((intmax_t)(nb % len)), base, fd);
	}
}

void		ft_printf_putnbr_base_unsigned(uintmax_t nb, char *base, int fd)
{
	int		len;

	len = ft_strlen(base);
	if (nb / len == 0)
		ft_putchar_fd(base[nb], fd);
	else
	{
		ft_printf_putnbr_base_unsigned(nb / len, base, fd);
		ft_printf_putnbr_base_unsigned((uintmax_t)(nb % len), base, fd);
	}
}
