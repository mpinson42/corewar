/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sol <sol@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 19:46:09 by apieropa          #+#    #+#             */
/*   Updated: 2015/03/05 16:20:56 by sol              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_nbrlen_base(int nb, int base)
{
	int		len;
	int		cpy;

	if (nb == 0)
		return (1);
	len = 0;
	cpy = nb;
	while (cpy != 0)
	{
		cpy /= base;
		len++;
	}
	return (nb > 0 ? len : len + 1);
}
