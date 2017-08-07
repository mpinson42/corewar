/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 11:52:19 by apieropa          #+#    #+#             */
/*   Updated: 2015/03/27 18:02:53 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (nb / 10 == 0)
	{
		ft_putstr(nb < 0 ? "-" : "");
		ft_putchar(ABS(nb) + '0');
	}
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(ABS(nb % 10));
	}
}
