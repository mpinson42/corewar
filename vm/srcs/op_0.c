/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_0.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 13:09:15 by mpinson           #+#    #+#             */
/*   Updated: 2017/08/04 13:09:23 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

extern char *g_mem;
extern char *g_map_pc;

void	op_fork(t_op_arg *args, t_process *champ, t_champ *champs)
{
	champ->fork = get_addr_in_mem(champ->pc +
		((int16_t)swap_int32(*args[0].addr) % IDX_MOD));
	(void)champs;
}

void	op_lld(t_op_arg *args, t_process *champ, t_champ *champs)
{
	if (args[0].type == IND_CODE)
		*(args[1].addr) = load_int16(args[0]) << 16;
	else
		*(args[1].addr) = load_int32(args[0]);
	if (!*(args[1].addr))
		champ->success = 1;
	(void)champ;
	(void)champs;
}

void	op_lldi(t_op_arg *args, t_process *champ, t_champ *champs)
{
	*(args[2].addr) = *(int *)get_addr_in_mem(champ->pc +
		(int16_t)(swap_int32(load_int32(args[0])) +
			swap_int32(load_int32(args[1]))));
	if (!*(args[2].addr))
		champ->success = 1;
	(void)champs;
}

void	op_lfork(t_op_arg *args, t_process *champ, t_champ *champs)
{
	champ->fork = get_addr_in_mem(champ->pc +
		(int16_t)swap_int32(*args[0].addr));
	(void)champs;
}

void	op_aff(t_op_arg *args, t_process *champ, t_champ *champs)
{
	(void)champ;
	(void)champs;
	ft_putchar(*(args[0].addr) % 256);
}
