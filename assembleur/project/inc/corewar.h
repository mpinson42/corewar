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

#ifndef COREWAR_H
# define COREWAR_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include "libft.h"
# include "structs.h"
# include "op.h"

/*
** ## Main Execution
*/
void	get_champion_lines(char *filename, char **lines);
void	check_champion_lines(char **lines);
void	get_instructions(char **lines, t_instr *instrs, t_header *header);
void	get_champion_program(char **lines, t_instr *instrs, t_header *header);
void	print_champion_to_file(t_header *header,
	t_instr *instrs, char *filename);

/*
** ## Check lines
*/
t_bool	line_is_the_name_command(char *line);
t_bool	line_is_the_comment_command(char *line);
t_bool	line_is_a_label_line(char *line);
t_bool	line_is_an_instruction_line(char *line);
t_bool	line_begins_by_an_opcode(char *line);

/*
** ## Parsing lines into header or instructions
*/
t_bool	line_parsed_as_the_name_command(char *line, t_header *header);
t_bool	line_parsed_as_the_comment_command(char *line, t_header *header);
t_bool	line_parsed_as_an_instruction_line(char *line, t_instr *instr);
t_bool	line_parsed_as_a_label_line(char *line, t_instr *instr);

/*
** ## Completing instructions
*/
void	opcode_meta_pass(t_instr *instrs);
void	arguments_meta_pass(t_instr *instrs);
void	addresses_pass(t_instr *instrs, t_header *header);
void	arguments_values_pass(t_instr *instrs);

/*
** ## Utils
*/

/*
** ### String functions
*/
void	str_tabs_to_spaces(char *line);
void	str_strip_leading_whitespaces(char *line);
void	str_strip_trailling_comments(char *line);
void	str_strip_trailing_whitespaces(char *line);
void	str_compress_whitespaces(char *line);
void	str_array_map(char **array, void (*f)(char*));
t_bool	does_str_starts_with(char *str, char *begin_str);
t_bool	does_str_ends_with(char *str, char *end_str);
t_bool	is_string_value_well_formatted(char *name_value);
t_bool	is_str_only_made_of(char *str, char *chrs, uint limit);

/*
** ### Div
*/
t_bool	is_a_label(char *arg);
t_bool	is_arg_an_ind(char *arg);
t_bool	is_arg_a_dir(char *arg);
t_bool	is_arg_a_reg(char *arg);

t_op	*op_tab(void);
t_op	*op_from_instr(char *instr);

int		failure(char *error_message);
int		failure_at_line(char *error_message, uint linum);
int		failure_label(char *label);

int		invert_endianness_o4(int value);
void	each_instr(t_instr *instrs, void (*f)(t_instr *instr));
int		label_address(char *label, t_instr *instrs);

#endif
