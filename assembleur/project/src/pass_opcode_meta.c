/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass_opcode_meta.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 20:03:38 by apieropa          #+#    #+#             */
/*   Updated: 2017/07/27 20:03:39 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	opcode_meta_pass_one_instr(t_instr *instr)
{
	instr->op = op_from_instr(instr->instr);
}

void		opcode_meta_pass(t_instr *instrs)
{
	each_instr(instrs, &opcode_meta_pass_one_instr);
}
