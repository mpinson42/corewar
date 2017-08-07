/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_get_instructions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 20:03:16 by apieropa          #+#    #+#             */
/*   Updated: 2017/07/27 20:03:17 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	get_instructions(char **lines, t_instr *instrs, t_header *header)
{
	uint	l;
	uint	i;

	l = 0;
	i = 0;
	while (lines[l] != NULL)
	{
		if (lines[l][0] == '\0')
			l++;
		else if (line_parsed_as_the_name_command(lines[l], header) == TRUE)
			l++;
		else if (line_parsed_as_the_comment_command(lines[l], header) == TRUE)
			l++;
		else if (line_parsed_as_a_label_line(lines[l], instrs + i) == TRUE)
			(void)(l++ + i++);
		else if (line_parsed_as_an_instruction_line(lines[l],
			instrs + i) == TRUE)
			(void)(l++ + i++);
		else
			failure_at_line("parsing error", l + 1);
	}
}
