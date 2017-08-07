/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sol <sol@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/11 15:12:15 by apieropa          #+#    #+#             */
/*   Updated: 2015/03/05 17:59:44 by sol              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_base(int nb, int base)
{
	if (nb / base == 0)
	{
		ft_putstr(nb < 0 ? "-" : "");
		ft_putchar(ABS(nb) + '0');
	}
	else
	{
		ft_putnbr_base(nb / base, base);
		ft_putnbr_base(ABS(nb % base), base);
	}
}
