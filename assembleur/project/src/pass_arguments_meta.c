/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass_arguments_meta.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 20:03:30 by apieropa          #+#    #+#             */
/*   Updated: 2017/07/27 20:03:31 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static char		invert_args_desc(char args_desc)
{
	char	inverted;

	inverted = 0;
	inverted |= ((args_desc >> 0) & 0x03) << 6;
	inverted |= ((args_desc >> 2) & 0x03) << 4;
	inverted |= ((args_desc >> 4) & 0x03) << 2;
	inverted |= ((args_desc >> 6) & 0x03) << 0;
	return (inverted);
}

static void		arguments_meta_pass_one_arg(t_instr *instr, uint ai)
{
	if (is_arg_a_reg(instr->args[ai].str) == TRUE)
	{
		instr->args[ai].type = T_REG;
		instr->args_desc_octet |= REG_CODE << (ai * 2);
		instr->args[ai].octet_nb = 1;
	}
	else if (is_arg_a_dir(instr->args[ai].str) == TRUE)
	{
		instr->args[ai].type = T_DIR;
		instr->args_desc_octet |= DIR_CODE << (ai * 2);
		instr->args[ai].octet_nb = instr->op->are_dirs_short ? 2 : 4;
	}
	else if (is_arg_an_ind(instr->args[ai].str) == TRUE)
	{
		instr->args[ai].type = T_IND;
		instr->args_desc_octet |= IND_CODE << (ai * 2);
		instr->args[ai].octet_nb = 2;
	}
	else
		failure("parsing error");
}

static void		arguments_meta_pass_one_instr(t_instr *instr)
{
	uint	ai;

	ai = 0;
	while (ai < instr->args_nb)
	{
		arguments_meta_pass_one_arg(instr, ai);
		ai++;
	}
	instr->args_desc_octet = invert_args_desc(instr->args_desc_octet);
}

void			arguments_meta_pass(t_instr *instrs)
{
	each_instr(instrs, &arguments_meta_pass_one_instr);
}
