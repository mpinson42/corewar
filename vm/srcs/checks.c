/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveniat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/06 02:43:28 by pveniat           #+#    #+#             */
/*   Updated: 2017/08/06 02:43:30 by pveniat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

extern char	*g_mem;
extern char	*g_map_pc;

void				end_op_check(t_loop_data *ld, t_data *data)
{
	if (ld->op.id != 9 || !ld->process->carry)
	{
		*(g_map_pc + (ld->process->pc - g_mem)) -= 1;
		ld->process->pc = get_addr_in_mem(ld->pc + ld->pc_delta);
		*(g_map_pc + (ld->process->pc - g_mem)) += 1;
	}
	if (ld->op.carry_mod && ld->process->success)
		ld->process->carry = 1;
	else if (ld->op.carry_mod && !ld->ret)
		ld->process->carry = 0;
	if (ld->op.id == 1)
	{
		data->nbr_live++;
		data->last_live = ld->process->id;
	}
}

t_process_list		*fork_check(t_process_list *next_process_list,
	t_process *process, t_champ *champs)
{
	if (process->fork)
	{
		next_process_list = add_process_to_begin(next_process_list,
			process->id, process->fork, champs);
		ft_memcpy(next_process_list->champ.regs, process->regs,
			REG_NUMBER * REG_SIZE);
		next_process_list->champ.carry = process->carry;
		next_process_list->champ.is_alive = process->is_alive;
	}
	return (next_process_list);
}

t_process_list		*are_alive_check(t_data *data,
	t_process_list *process_list, t_champ *champs)
{
	t_process_list	*head;

	head = process_list;
	while (process_list)
	{
		win_end_check(data, champs, process_list);
		if (!process_list->champ.is_alive)
			process_list = kill_process(data, process_list, &head, champs);
		else
		{
			process_list->champ.is_alive = 0;
			process_list = process_list->next;
		}
	}
	if (data->nbr_live >= data->max_lives)
		data->cycle_to_die -= data->cycle_delta;
	else
		data->checks++;
	if (data->checks >= data->max_checks)
	{
		data->cycle_to_die--;
		data->checks = 0;
	}
	data->nbr_live = 0;
	return (head);
}

t_process_list		*end_cycle_check(t_data *data,
	t_process_list *process_list, t_champ *champs)
{
	data->cycle++;
	data->total_cycles++;
	if (data->cycle == data->cycle_to_die)
	{
		process_list = are_alive_check(data, process_list, champs);
		data->cycle = 0;
	}
	return (process_list);
}
