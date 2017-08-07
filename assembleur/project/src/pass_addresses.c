/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass_addresses.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 20:03:25 by apieropa          #+#    #+#             */
/*   Updated: 2017/07/27 20:03:27 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	addresses_pass_one_arg(uint i, uint ai, t_instr *instrs)
{
	if (ai == 0)
		instrs[i].args[0].address = instrs[i].address + 1;
	if (ai == 0 && instrs[i].op->has_args_desc_octet)
		instrs[i].args[0].address += 1;
	if (ai + 1 < instrs[i].args_nb)
		instrs[i].args[ai + 1].address = instrs[i].args[ai].address;
	if (ai + 1 < instrs[i].args_nb)
		instrs[i].args[ai + 1].address += instrs[i].args[ai].octet_nb;
}

void		addresses_pass(t_instr *instrs, t_header *header)
{
	uint	i;
	uint	ai;
	uint	last_position;

	i = 0;
	while (instrs[i].line != NULL)
	{
		ai = 0;
		while (ai < instrs[i].args_nb)
		{
			addresses_pass_one_arg(i, ai, instrs);
			last_position = instrs[i].args[ai].address;
			last_position += instrs[i].args[ai].octet_nb;
			ai++;
		}
		if (instrs[i + 1].line != NULL)
			instrs[i + 1].address = last_position;
		i++;
	}
	header->prog_size = last_position;
	if (CHECK_CHAMP_SIZE == TRUE && header->prog_size > CHAMP_MAX_SIZE)
		failure("champ size exeeds limitation of CHAMP_MAX_SIZE");
}
