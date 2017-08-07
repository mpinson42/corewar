/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_parsed_as.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 20:01:39 by apieropa          #+#    #+#             */
/*   Updated: 2017/07/27 20:01:40 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_bool		line_parsed_as_the_name_command(char *line, t_header *header)
{
	char	*value;
	uint	value_len;

	if (does_str_starts_with(line, NAME_CMD_STRING))
	{
		value = ft_strchr(line, ' ');
		value++;
		value_len = ft_strlen(value) - 2;
		ft_strncpy(header->prog_name, value + 1, value_len);
		return (TRUE);
	}
	return (FALSE);
}

t_bool		line_parsed_as_the_comment_command(char *line, t_header *header)
{
	char	*value;
	uint	value_len;

	if (does_str_starts_with(line, COMMENT_CMD_STRING))
	{
		value = ft_strchr(line, ' ');
		value++;
		value_len = ft_strlen(value) - 2;
		ft_strncpy(header->comment, value + 1, value_len);
		return (TRUE);
	}
	return (FALSE);
}

static void	line_parsed_as_an_instruction_line_store_args(t_instr *instr,
	char *args_str)
{
	char	**args;
	uint	i;

	i = 0;
	while (args_str[i] == ' ')
		args_str++;
	args = ft_strsplit(args_str, SEPARATOR_CHAR);
	str_array_map(args, &str_strip_leading_whitespaces);
	str_array_map(args, &str_strip_trailing_whitespaces);
	instr->args_nb = str_array_length(args);
	i = 0;
	while (i < instr->args_nb)
	{
		instr->args[i].str = args[i];
		i++;
	}
	free(args);
}

t_bool		line_parsed_as_an_instruction_line(char *line, t_instr *instr)
{
	char	*args_str;

	if (line_begins_by_an_opcode(line) == FALSE)
		return (FALSE);
	if (instr->line == NULL)
		instr->line = line;
	args_str = ft_strchr(line, ' ');
	if ((instr->instr = ft_strnew(args_str - line + 1)) == NULL)
		failure(ERR_MALLOC);
	instr->instr = ft_strncpy(instr->instr, line, args_str - line);
	line_parsed_as_an_instruction_line_store_args(instr, args_str);
	return (TRUE);
}

t_bool		line_parsed_as_a_label_line(char *line, t_instr *instr)
{
	char *label_char;
	char *instr_str;

	label_char = ft_strchr(line, LABEL_CHAR);
	if (label_char == NULL || label_char == line)
		return (FALSE);
	if (is_str_only_made_of(line, LABEL_CHARS, label_char - line) == FALSE)
		return (FALSE);
	instr->has_label = TRUE;
	if ((instr->label_name = ft_strnew(label_char - line + 1)) == NULL)
		failure(ERR_MALLOC);
	instr->label_name = ft_strncpy(instr->label_name, line, label_char - line);
	instr_str = label_char + 1;
	while (*instr_str != '\0' && *instr_str == ' ')
		instr_str++;
	instr->line = line;
	return (line_parsed_as_an_instruction_line(instr_str, instr));
}
