/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_is_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 20:00:58 by apieropa          #+#    #+#             */
/*   Updated: 2017/07/27 20:00:59 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static t_bool	is_arg_of_instr_ok(char *arg, t_arg_type types)
{
	if (types & T_REG && is_arg_a_reg(arg) == TRUE)
		return (TRUE);
	if (types & T_DIR && is_arg_a_dir(arg) == TRUE)
		return (TRUE);
	if (types & T_IND && is_arg_an_ind(arg) == TRUE)
		return (TRUE);
	return (FALSE);
}

static t_bool	are_args_of_instr_ok(char *instr, char **args)
{
	t_op	*op;
	uint	args_nb;
	uint	i;

	op = op_from_instr(instr);
	args_nb = str_array_length(args);
	if (op == NULL)
		return (FALSE);
	if (args_nb != op->args_nb)
		return (FALSE);
	i = 0;
	while (i < op->args_nb)
	{
		if (is_arg_of_instr_ok(args[i], op->args_types[i]) == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

t_bool			line_is_an_instruction_line(char *line)
{
	char	*args;
	char	**args_tab;
	char	*instr;

	if (line_begins_by_an_opcode(line) == FALSE)
		return (FALSE);
	if ((args = ft_strchr(line, ' ')) == NULL)
		return (FALSE);
	if ((instr = ft_strnew(args - line)) == NULL)
		failure(ERR_MALLOC);
	instr = ft_strncpy(instr, line, args - line);
	args++;
	args_tab = ft_strsplit(args, SEPARATOR_CHAR);
	str_array_map(args_tab, &str_strip_leading_whitespaces);
	str_array_map(args_tab, &str_strip_trailing_whitespaces);
	if (are_args_of_instr_ok(instr, args_tab) == FALSE)
		return (FALSE);
	ft_strdel(&instr);
	str_array_del(&args_tab);
	return (TRUE);
}
