/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_chrs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sol <sol@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/11 15:12:15 by apieropa          #+#    #+#             */
/*   Updated: 2015/03/05 18:24:09 by sol              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_base_chrs(int nb, char *base)
{
	int		len;

	len = ft_strlen(base);
	if (nb / len == 0)
	{
		ft_putstr(nb < 0 ? "-" : "");
		ft_putchar(base[ABS(nb)]);
	}
	else
	{
		ft_putnbr_base_chrs(nb / len, base);
		ft_putnbr_base_chrs(ABS(nb % len), base);
	}
}
