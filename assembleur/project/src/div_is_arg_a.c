/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   div_is_arg_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 19:59:26 by apieropa          #+#    #+#             */
/*   Updated: 2017/07/27 19:59:27 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_bool	is_a_label(char *arg)
{
	if (is_str_only_made_of(arg, LABEL_CHARS, 0) == FALSE)
		return (FALSE);
	return (TRUE);
}

t_bool	is_arg_an_ind(char *arg)
{
	long int	nbr;

	if (ft_isnbr(arg))
	{
		nbr = ft_atol(arg);
		if (CHECK_INT_SIZE == TRUE && (nbr < -2147483648 || nbr > 2147483647))
			return (FALSE);
		else
			return (TRUE);
	}
	if (arg[0] == LABEL_CHAR && is_a_label(arg + 1) == TRUE)
		return (TRUE);
	return (FALSE);
}

t_bool	is_arg_a_dir(char *arg)
{
	long int	nbr;

	if (arg[0] != '%')
		return (FALSE);
	if (ft_isnbr(arg + 1) == TRUE)
	{
		nbr = ft_atol(arg + 1);
		if (CHECK_INT_SIZE == TRUE && (nbr < -2147483648 || nbr > 2147483647))
			return (FALSE);
		else
			return (TRUE);
	}
	if (arg[1] == LABEL_CHAR && is_a_label(arg + 2) == TRUE)
		return (TRUE);
	return (FALSE);
}

t_bool	is_arg_a_reg(char *arg)
{
	int		reg_num;

	if (arg[0] != 'r')
		return (FALSE);
	if (ft_isnbr(arg + 1) == FALSE)
		return (FALSE);
	reg_num = ft_atoi(arg + 1);
	if (reg_num < 0 || reg_num > REG_NUMBER)
		return (FALSE);
	return (TRUE);
}
