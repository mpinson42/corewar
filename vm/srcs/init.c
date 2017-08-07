/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 15:30:19 by mpinson           #+#    #+#             */
/*   Updated: 2017/08/04 16:03:16 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

extern	char	*g_mem;
extern	char	*g_map_color;
extern	char	*g_map_pc;
extern	int		g_nb_process;

static t_op			g_op_tab[17] =
{
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0, 4},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 1, 4},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0, 4},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 1, 0},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 1, 0},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 1, 4},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 1, 4},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 1, 4},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 0, 2},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 0, 2},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 0, 2},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 0, 2},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 1, 4},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 1, 2},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 0, 2},
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0, 0},
	{"", 0, {0}, 0, 0, "", 0, 0, 0}
};

t_data			*init_data(void)
{
	t_data	*data;

	if ((data = malloc(sizeof(t_data))) == NULL)
		failure_malloc();
	data->cycle_to_die = CYCLE_TO_DIE;
	data->cycle_delta = CYCLE_DELTA;
	data->max_lives = NBR_LIVE;
	data->nbr_live = 0;
	data->max_checks = MAX_CHECKS;
	data->cycle = 1;
	data->total_cycles = 1;
	data->checks = 0;
	data->dump = 0;
	data->dump_cycle = 0;
	data->nbr_champs = 0;
	data->last_live = 0;
	data->is_there_visu = 0;
	return (data);
}

void			fin_process_to_begin(t_process_list *new_node,
		char *pc, t_process_list *list)
{
	new_node->prev = NULL;
	new_node->next = list;
	if (new_node->next)
		new_node->next->prev = new_node;
	*(g_map_pc + (pc - g_mem)) = 1;
}

t_process_list	*add_process_to_begin(t_process_list *list,
		int id, char *pc, t_champ *champs)
{
	t_process_list	*new_node;
	t_op			op;

	g_nb_process++;
	if ((new_node = ft_memalloc(sizeof(t_process_list))) == NULL)
		failure_malloc();
	champs[id].nb_process++;
	new_node->champ.id = id;
	new_node->champ.pc = pc;
	new_node->champ.is_alive = 0;
	new_node->champ.start_pc = pc;
	new_node->champ.carry = 0;
	if ((int)*pc >= 1 && (int)*pc <= 16)
	{
		op = g_op_tab[(int)*pc - 1];
		new_node->champ.cycles_wait = op.turns_cost - 1;
		new_node->champ.waiting_op = op.id;
	}
	ft_bzero(new_node->champ.regs, REG_NUMBER * REG_SIZE);
	*((int *)&(new_node->champ.regs[0])) = swap_int32(-id - 1);
	fin_process_to_begin(new_node, pc, list);
	return (new_node);
}

int				get_first_champ_index(t_champ *champs)
{
	int		i;

	i = 0;
	while (champs[i].file)
		i++;
	return (i);
}
