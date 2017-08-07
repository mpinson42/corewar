/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sol <sol@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 11:19:23 by apieropa          #+#    #+#             */
/*   Updated: 2015/03/06 17:31:11 by sol              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	ft_atol(const char *str)
{
	uint		i;
	long int	nbr;
	t_iny		sign;

	if (str[0] == '\0')
		return (0);
	i = 0;
	while (ft_strchr(" \n\t\v\f\r", str[i]) != 0)
		i++;
	sign = (str[i] == '-' ? -1 : 1);
	i += (str[i] == '-' || str[i] == '+' ? 1 : 0);
	nbr = 0;
	while ((str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	return (nbr * sign);
}
