/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 13:14:28 by mpinson           #+#    #+#             */
/*   Updated: 2017/08/04 13:14:29 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

extern char *g_mem;

void	op_sti(t_op_arg *args, t_process *champ, t_champ *champs)
{
	(void)champs;
	(void)champ;
	store_int32((t_op_arg){(int *)get_addr_in_mem(champ->pc +
		((int16_t)(swap_int32(load_int32(args[1])) +
			swap_int32(load_int32(args[2]))) % IDX_MOD)),
	IND_CODE}, *(args[0].addr), champ->id);
	ft_printf_fd(2, "%d + %d", swap_int32(load_int32(args[1])),
		swap_int32(load_int32(args[2])));
	if (DEBUG == 1)
		ft_printf_fd(2, " (with pc and mod %d) ", get_addr_in_mem(champ->pc +
		(((swap_int32(load_int32(args[1])) % IDX_MOD) +
			(swap_int32(load_int32(args[2])) % IDX_MOD)) % IDX_MOD)) - g_mem);
}
