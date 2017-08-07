/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/29 15:29:46 by apieropa          #+#    #+#             */
/*   Updated: 2017/07/29 15:29:47 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include "defines.h"

typedef char					t_arg_type;

typedef struct					s_data
{
	int							nbr_champs;
	int							cycle_to_die;
	int							cycle_delta;
	int							max_lives;
	int							nbr_live;
	int							max_checks;
	int							cycle;
	int							total_cycles;
	int							checks;
	int							dump;
	int							dump_cycle;
	int							last_live;
	int							is_there_visu;
}								t_data;

typedef struct					s_process
{
	char						name[PROG_NAME_LENGTH + 1];
	char						regs[REG_NUMBER][REG_SIZE];
	char						*start_pc;
	char						*pc;
	int							id;
	int							success;
	char						*fork;
	int							carry;
	int							is_alive;
	int							cycles_wait;
	int							last_live;
	int							live;
	char						waiting_op;
}								t_process;

typedef struct					s_process_list
{
	t_process					champ;
	struct s_process_list		*prev;
	struct s_process_list		*next;
}								t_process_list;

typedef struct					s_header
{
	unsigned int				magic;
	char						prog_name[PROG_NAME_LENGTH + 1];
	unsigned int				prog_size;
	char						comment[COMMENT_LENGTH + 1];
}								t_header;

typedef struct					s_champ
{
	char						*file;
	int							id;
	t_header					header;
	char						name[PROG_NAME_LENGTH + 1];
	char						comment[COMMENT_LENGTH + 1];
	int							is_alive;
	int							is_dead;
	int							live;
	int							last_live;
	int							nb_process;
}								t_champ;

typedef struct					s_op
{
	char						op_name[6];
	int							nbr_arg;
	t_arg_type					args_type[3];
	int							id;
	int							turns_cost;
	char						comment[COMMENT_LENGTH + 1];
	int							octal_code;
	int							carry_mod;
	int							label_size;
}								t_op;

typedef struct					s_op_arg
{
	int							*addr;
	int							type;
}								t_op_arg;

typedef union					u_swap_value
{
	int							i;
	int16_t						i16;
	int32_t						i32;
}								t_swap_value;

typedef struct					s_load
{
	int							i;
	int							i2;
	int							fd;
	int							ret;
	t_process_list				*process_list;
	char						buffer[sizeof(t_header) + CHAMP_MAX_SIZE + 1];
}								t_load;

typedef struct					s_loop_data
{
	t_process_list				*next_process_list;
	t_process					*process;
	char						*pc;
	int							pc_delta;
	t_op						op;
	t_arg_type					arg_type;
	t_op_arg					args[4];
	int							tmp_arg[4];
	int							ret;
	int							process_nbr;
}								t_loop_data;

#endif
