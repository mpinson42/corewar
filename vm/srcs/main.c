/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveniat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/06 02:47:40 by pveniat           #+#    #+#             */
/*   Updated: 2017/08/06 02:47:42 by pveniat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

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

char				*g_mem;
char				*g_map_color;
char				*g_map_pc;
int					g_nb_process;

t_op_function		g_op_functions[16] =
{
	op_live,
	op_ld,
	op_st,
	op_add,
	op_sub,
	op_and,
	op_or,
	op_xor,
	op_zjmp,
	op_ldi,
	op_sti,
	op_fork,
	op_lld,
	op_lldi,
	op_lfork,
	op_aff
};

void			try_exec_op(t_data *data, t_loop_data *ld, t_champ *champs)
{
	if ((int)*ld->pc >= 1 && (int)*ld->pc <= 16)
	{
		ld->op = g_op_tab[ld->process->waiting_op - 1];
		ld->pc++;
		get_all_op_args(ld);
		if (!ld->ret)
		{
			if (DEBUG == 1)
				ft_printf_fd(2, "P %4d | %s ", g_nb_process -
					ld->process_nbr, ld->op.op_name);
			g_op_functions[ld->op.id - 1](ld->args, ld->process, champs);
		}
		end_op_check(ld, data);
		ld->next_process_list = fork_check(ld->next_process_list,
			ld->process, champs);
	}
	else
	{
		*(g_map_pc + (ld->process->pc - g_mem)) -= 1;
		ld->process->pc = get_addr_in_mem(++ld->process->pc);
		*(g_map_pc + (ld->process->pc - g_mem)) += 1;
	}
	ld->process->waiting_op = -1;
}

void			try_exec_process(t_data *data, t_champ *champs,
	t_loop_data *ld)
{
	if (ld->process->waiting_op == -1
		&& (int)*ld->process->pc >= 1 && (int)*ld->process->pc <= 16)
	{
		ld->op = g_op_tab[(int)*ld->process->pc - 1];
		ld->process->cycles_wait = ld->op.turns_cost - 1;
		ld->process->waiting_op = ld->op.id;
	}
	if (!ld->process->cycles_wait || *(ld->process->pc) <= 0
		|| *(ld->process->pc) > 16)
	{
		ld->pc = ld->process->pc;
		ft_printf_fd(2, "pc a : %d ", *ld->pc);
		try_exec_op(data, ld, champs);
		if (DEBUG == 1)
			ft_printf_fd(2, " pc: %04x\n", ld->process->pc - g_mem);
	}
	else
		ld->process->cycles_wait--;
}

t_process_list	*loop_champ(t_data *data, t_process_list *process_list,
	t_champ *champs)
{
	t_loop_data		ld;

	ld.process_nbr = 0;
	ld.next_process_list = process_list;
	if (DEBUG == 1)
		ft_printf_fd(2, "It is now cycle %d : %d processes\n",
			data->total_cycles, g_nb_process);
	while (process_list)
	{
		ld.process = &process_list->champ;
		ld.pc_delta = 0;
		ld.process->success = 0;
		ld.process->fork = NULL;
		try_exec_process(data, champs, &ld);
		process_list = process_list->next;
		ld.process_nbr++;
	}
	return (ld.next_process_list);
}

void			loop(t_data *data, char *mem, t_process_list *champ_list,
	t_champ *champs)
{
	while (champ_list)
	{
		if (data->dump && data->total_cycles - 1 == data->dump_cycle)
		{
			print_mem(mem);
			exit_success();
		}
		champ_list = loop_champ(data, champ_list, champs);
		if (data->is_there_visu && data->total_cycles >= data->is_there_visu)
		{
			ft_affiche_map(data, champs);
		}
		champ_list = end_cycle_check(data, champ_list, champs);
	}
}

int				main(int argc, char **argv)
{
	t_data			*data;
	char			*mem;
	t_process_list	*process_list;
	t_champ			champs[MAX_PLAYERS];

	(void)argc;
	g_nb_process = 0;
	ft_bzero(champs, sizeof(t_champ) * MAX_PLAYERS);
	data = init_data();
	if ((mem = ft_memalloc(MEM_SIZE)) == NULL)
		failure_malloc();
	g_mem = mem;
	if ((g_map_color = ft_memalloc(MEM_SIZE)) == NULL)
		failure_malloc();
	if ((g_map_pc = ft_memalloc(MEM_SIZE)) == NULL)
		failure_malloc();
	catch_argv(data, champs, argv);
	process_list = load_process(mem, champs, data);
	loop(data, mem, process_list, champs);
	free(mem);
	return (0);
}
