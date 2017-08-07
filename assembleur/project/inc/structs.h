/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 19:50:07 by apieropa          #+#    #+#             */
/*   Updated: 2017/07/27 19:50:09 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "libft.h"
# include "op.h"

typedef char		t_arg_type;

typedef struct		s_header
{
	uint			magic;
	char			prog_name[PROG_NAME_LENGTH + 1];
	uint			prog_size;
	char			comment[COMMENT_LENGTH + 1];
}					t_header;

typedef struct		s_op
{
	char			*instr;
	uint			args_nb;
	t_arg_type		args_types[3];
	t_iny			opcode;
	uint			nb_cycles;
	char			*description;
	char			has_args_desc_octet;
	t_iny			are_dirs_short;
}					t_op;

typedef struct		s_arg
{
	t_arg_type		type;
	uint			octet_nb;
	char			*str;
	uint			address;
	int				value;
}					t_arg;

typedef struct		s_instr
{
	char			*line;
	t_op			*op;
	char			*instr;
	int				address;
	t_bool			has_label;
	char			*label_name;
	char			args_desc_octet;
	uint			args_nb;
	t_arg			args[3];
}					t_instr;

#endif
