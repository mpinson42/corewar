/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   div_div.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 19:59:12 by apieropa          #+#    #+#             */
/*   Updated: 2017/07/27 19:59:14 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		invert_endianness_o4(int value)
{
	int	nvalue;

	nvalue = 0;
	nvalue = nvalue | (value >> 24 & 0xff) << 0;
	nvalue = nvalue | (value >> 16 & 0xff) << 8;
	nvalue = nvalue | (value >> 8 & 0xff) << 16;
	nvalue = nvalue | (value >> 0 & 0xff) << 24;
	return (nvalue);
}

void	each_instr(t_instr *instrs, void (*f)(t_instr *instr))
{
	uint	i;

	i = 0;
	while (instrs[i].line != NULL)
	{
		(*f)(instrs + i);
		i++;
	}
}

int		label_address(char *label, t_instr *instrs)
{
	uint	i;

	i = 0;
	while (instrs[i].line != NULL)
	{
		if (instrs[i].has_label == TRUE)
		{
			if (ft_strcmp(instrs[i].label_name, label) == 0)
				return (instrs[i].address);
		}
		i++;
	}
	return (failure_label(label));
}
