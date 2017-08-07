/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 13:09:27 by mpinson           #+#    #+#             */
/*   Updated: 2017/08/04 13:09:35 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_live(t_op_arg *args, t_process *champ, t_champ *champs)
{
	(void)champs;
	champ->last_live = (-swap_int32(*(args[0].addr)) - 1) % MAX_PLAYERS;
	champ->is_alive = 1;
}

void	op_ld(t_op_arg *args, t_process *champ, t_champ *champs)
{
	*(args[1].addr) = load_int32(args[0]);
	if (!*(args[1].addr))
		champ->success = 1;
	(void)champs;
}

void	op_st(t_op_arg *args, t_process *champ, t_champ *champs)
{
	store_int32(args[1], *(args[0].addr), champ->id);
	if (*(args[0].addr) == (int)2332100867)
		ft_printf_fd(2, "st 2332100867 champ %d val1 %d type %d\n", champ->id,
			*(args[1].addr), args[1].type);
	else if (*(args[0].addr) == (int)33969163)
		ft_printf_fd(2, "st 33969163 champ %d val1 %d type %d\n", champ->id,
			*(args[1].addr), args[1].type);
	(void)champs;
}

void	op_add(t_op_arg *args, t_process *champ, t_champ *champs)
{
	(void)champs;
	*(args[2].addr) = *(args[0].addr) + *(args[1].addr);
	if (!*(args[2].addr))
		champ->success = 1;
}

void	op_sub(t_op_arg *args, t_process *champ, t_champ *champs)
{
	(void)champs;
	*(args[2].addr) = *(args[0].addr) - *(args[1].addr);
	if (!*(args[2].addr))
		champ->success = 1;
}
