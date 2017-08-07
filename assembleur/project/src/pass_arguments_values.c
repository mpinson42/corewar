/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass_arguments_values.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 20:03:34 by apieropa          #+#    #+#             */
/*   Updated: 2017/07/27 20:03:35 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		arguments_values_pass_one_arg(t_arg *arg,
	uint instr_addr, t_instr *instrs)
{
	if (arg->type == T_REG)
	{
		arg->value = ft_atoi(arg->str + 1);
	}
	if (arg->type == T_IND)
	{
		if (arg->str[0] == LABEL_CHAR)
			arg->value = label_address(arg->str + 1, instrs) - instr_addr;
		else
			arg->value = ft_atoi(arg->str);
	}
	if (arg->type == T_DIR)
	{
		if (arg->str[1] == LABEL_CHAR)
			arg->value = label_address(arg->str + 2, instrs) - instr_addr;
		else
			arg->value = ft_atoi(arg->str + 1);
	}
}

static void		arguments_values_pass_one_instr(t_instr *instr, t_instr *instrs)
{
	uint	ai;

	ai = 0;
	while (ai < instr->args_nb)
	{
		arguments_values_pass_one_arg(instr->args + ai, instr->address, instrs);
		ai++;
	}
}

void			arguments_values_pass(t_instr *instrs)
{
	uint	i;

	i = 0;
	while (instrs[i].line != NULL)
	{
		arguments_values_pass_one_instr(instrs + i, instrs);
		i++;
	}
}
