/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_check_champion_lines.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 20:02:07 by apieropa          #+#    #+#             */
/*   Updated: 2017/07/27 20:02:08 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	check_champion_lines(char **lines)
{
	int		l;

	l = -1;
	while ((42 + 0 * (l++)) && lines[l] != NULL)
	{
		str_tabs_to_spaces(lines[l]);
		str_strip_leading_whitespaces(lines[l]);
		str_strip_trailling_comments(lines[l]);
		str_strip_trailing_whitespaces(lines[l]);
		str_compress_whitespaces(lines[l]);
		if (lines[l][0] == '\0')
			continue ;
		if (line_is_the_name_command(lines[l]) == TRUE)
			continue ;
		if (line_is_the_comment_command(lines[l]) == TRUE)
			continue ;
		if (line_is_a_label_line(lines[l]) == TRUE)
			continue ;
		if (line_is_an_instruction_line(lines[l]) == TRUE)
			continue ;
		failure_at_line("parsing error", l + 1);
	}
	if (l >= MAX_FILE_LINES)
		failure("file too big to process (change MAX_FILE_LINES)");
}
