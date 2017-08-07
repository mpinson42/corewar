/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 04:34:03 by apieropa          #+#    #+#             */
/*   Updated: 2015/03/27 18:04:04 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_fd(int nb, int fd)
{
	if (nb == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (nb / 10 == 0)
	{
		ft_putstr_fd(nb < 0 ? "-" : "", fd);
		ft_putchar_fd(ABS(nb) + '0', fd);
	}
	else
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putnbr_fd(ABS(nb % 10), fd);
	}
}
