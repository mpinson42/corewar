/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_is_an_instruction_line.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 20:01:14 by apieropa          #+#    #+#             */
/*   Updated: 2017/07/27 20:01:16 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cor.h"

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

static t_bool	line_begins_by_an_opcode(char *line)
{
	static t_op		*instrs;
	static t_bool	init = FALSE;
	uint			i;
	uint			len;

	if (init == FALSE && TRUE + 0 * (init = TRUE))
		instrs = op_tab();
	i = 0;
	while (instrs[i].instr != NULL)
	{
		len = ft_strlen(instrs[i].instr);
		if (ft_strncmp(line, instrs[i].instr, len) == 0 && line[len] == ' ')
			return (TRUE);
		i++;
	}
	return (FALSE);
}

t_bool			line_is_an_instruction_line(char *line)
{
	int		i;
	char	*args;
	char	**args_tab;
	char	*instr;

	i = 1;
	if (line_begins_by_an_opcode(line) == FALSE)
		return (FALSE);
	if ((args = ft_strchr(line, ' ')) == NULL)
		return (FALSE);
	instr = ft_strncpy(ft_strnew(args - line), line, args - line);
	args++;
	args_tab = ft_strsplit(args, SEPARATOR_CHAR);
	str_array_map(args_tab, &str_strip_leading_whitespaces);
	if (are_args_of_instr_ok(instr, args_tab) == FALSE)
		return (FALSE);
	ft_strdel(&instr);
	str_array_del(&args_tab);
	return (TRUE);
}
