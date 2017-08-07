/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_is_a_label_line.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 20:01:07 by apieropa          #+#    #+#             */
/*   Updated: 2017/07/27 20:01:09 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cor.h"

t_bool			line_is_a_label_line(char *line)
{
	char *label_char;
	char *instr;

	label_char = ft_strchr(line, LABEL_CHAR);
	if (label_char == NULL || label_char == line)
		return (FALSE);
	if (is_str_only_made_of(line, LABEL_CHARS, label_char - line) == FALSE)
		return (FALSE);
	instr = label_char + 1;
	while (*instr != '\0' && *instr == ' ')
		instr++;
	return (line_is_an_instruction_line(instr));
}
