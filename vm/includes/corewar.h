/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/29 15:29:46 by apieropa          #+#    #+#             */
/*   Updated: 2017/07/29 15:29:47 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdint.h>
# include "defines.h"
# include "structures.h"

typedef void	(*t_op_function)(t_op_arg *, t_process *, t_champ *);

void			failure_usage(void);
void			failure(char *message);
void			failure_malloc(void);
void			failure_file(char *file, char *error);

void			catch_argv(t_data *data, t_champ *champs, char **argv);
t_data			*init_data(void);
t_process_list	*add_process_to_begin(t_process_list *list, int id, char *pc,
	t_champ *champs);
t_process_list	*load_process(char *mem, t_champ *champs, t_data *data);

void			print_mem(char *mem);
int				get_first_champ_index(t_champ *champs);

uint16_t		swap_uint16(uint16_t val);
int16_t			swap_int16(int16_t val);
uint32_t		swap_uint32(uint32_t val);
int32_t			swap_int32(int32_t val);

char			*get_addr_in_mem(char *addr);
void			store_int16(t_op_arg arg, int16_t n, int id);
void			store_int32(t_op_arg arg, int32_t n, int id);
int16_t			load_int16(t_op_arg arg);
int32_t			load_int32(t_op_arg arg);

int				isnumberstr(char *s);
t_process_list	*kill_process(t_data *data, t_process_list *process_to_kill,
	t_process_list **head, t_champ *champs);
void			win_end_check(t_data *data, t_champ *champs,
	t_process_list *process_list);
void			exit_success(void);

void			end_op_check(t_loop_data *ld, t_data *data);
t_process_list	*fork_check(t_process_list *next_process_list,
	t_process *process, t_champ *champs);
t_process_list	*are_alive_check(t_data *data,
	t_process_list *process_list, t_champ *champs);
t_process_list	*end_cycle_check(t_data *data, t_process_list *process_list,
	t_champ *champs);

void			get_all_op_args(t_loop_data *ld);

void			op_live(t_op_arg *args, t_process *champ, t_champ *champs);
void			op_ld(t_op_arg *args, t_process *champ, t_champ *champs);
void			op_st(t_op_arg *args, t_process *champ, t_champ *champs);
void			op_add(t_op_arg *args, t_process *champ, t_champ *champs);
void			op_sub(t_op_arg *args, t_process *champ, t_champ *champs);
void			op_and(t_op_arg *args, t_process *champ, t_champ *champs);
void			op_or(t_op_arg *args, t_process *champ, t_champ *champs);
void			op_xor(t_op_arg *args, t_process *champ, t_champ *champs);
void			op_zjmp(t_op_arg *args, t_process *champ, t_champ *champs);
void			op_ldi(t_op_arg *args, t_process *champ, t_champ *champs);
void			op_sti(t_op_arg *args, t_process *champ, t_champ *champs);
void			op_fork(t_op_arg *args, t_process *champ, t_champ *champs);
void			op_lld(t_op_arg *args, t_process *champ, t_champ *champs);
void			op_lldi(t_op_arg *args, t_process *champ, t_champ *champs);
void			op_lfork(t_op_arg *args, t_process *champ, t_champ *champs);
void			op_aff(t_op_arg *args, t_process *champ, t_champ *champs);

void			ft_affiche_map(t_data *data, t_champ *champs);
void			print_champ1(int count, t_champ *champs);
void			print_champ2(int count, t_champ *champs);
void			print_champ3(int count, t_champ *champs);
void			print_champ4(int count, t_champ *champs);
void			print_data(int count, t_champ *champs, t_data *data);

#endif
