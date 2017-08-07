/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 13:09:44 by mpinson           #+#    #+#             */
/*   Updated: 2017/08/04 13:09:46 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

extern char *g_mem;
extern char *g_map_pc;

void	op_and(t_op_arg *args, t_process *champ, t_champ *champs)
{
	(void)champs;
	*(args[2].addr) = load_int32(args[0]) & load_int32(args[1]);
	if (!*(args[2].addr))
		champ->success = 1;
}

void	op_or(t_op_arg *args, t_process *champ, t_champ *champs)
{
	(void)champs;
	*(args[2].addr) = load_int32(args[0]) | load_int32(args[1]);
	if (!*(args[2].addr))
		champ->success = 1;
}

void	op_xor(t_op_arg *args, t_process *champ, t_champ *champs)
{
	(void)champs;
	*(args[2].addr) = load_int32(args[0]) ^ load_int32(args[1]);
	if (!*(args[2].addr))
		champ->success = 1;
}

void	op_zjmp(t_op_arg *args, t_process *champ, t_champ *champs)
{
	(void)champs;
	if (DEBUG)
	{
		ft_printf_fd(2, "%d", (int16_t)swap_int32(*args[0].addr));
	}
	if (champ->carry)
	{
		*(g_map_pc + (champ->pc - g_mem)) -= 1;
		champ->pc = get_addr_in_mem(champ->pc +
			((int16_t)swap_int32(*args[0].addr) % IDX_MOD));
		*(g_map_pc + (champ->pc - g_mem)) += 1;
		if (DEBUG)
			ft_printf_fd(2, " OK");
	}
	else if (DEBUG)
		ft_printf_fd(2, " FAILED");
}

void	op_ldi(t_op_arg *args, t_process *champ, t_champ *champs)
{
	(void)champs;
	*(args[2].addr) = *(int *)get_addr_in_mem(champ->pc +
		(((swap_int32(load_int32(args[0])) % IDX_MOD) +
			(swap_int32(load_int32(args[1])) % IDX_MOD)) % IDX_MOD));
}
