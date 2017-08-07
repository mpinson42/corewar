/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_is_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 20:00:46 by apieropa          #+#    #+#             */
/*   Updated: 2017/07/27 20:00:47 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_bool		line_is_a_label_line(char *line)
{
	char	*label_char;
	char	*instr;

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

/*
** != 5 pour la longueur de `.name`
** + 2 pour les `"` entourant la str
*/

t_bool		line_is_the_name_command(char *line)
{
	char			*name_value;
	static t_bool	already_have_a_name = FALSE;

	if (does_str_starts_with(line, NAME_CMD_STRING) != TRUE)
		return (FALSE);
	if (already_have_a_name == TRUE)
		failure("command '.name' found twice");
	else
		already_have_a_name = TRUE;
	name_value = ft_strchr(line, ' ');
	if (name_value == NULL || name_value - line != 5)
		failure("command '.name' incorrectly formatted");
	name_value++;
	if (ft_strlen(name_value) > PROG_NAME_LENGTH + 2)
		failure("value for the command '.name' too long");
	if (is_string_value_well_formatted(name_value) == FALSE)
		failure("command '.name' incorrectly formatted");
	return (TRUE);
}

/*
** != 8 pour la longueur de `.comment`
** + 2 pour les `"` entourant la str
*/

t_bool		line_is_the_comment_command(char *line)
{
	char			*comment_value;
	static t_bool	already_have_a_comment = FALSE;

	if (does_str_starts_with(line, COMMENT_CMD_STRING) != TRUE)
		return (FALSE);
	if (already_have_a_comment == TRUE)
		failure("command '.comment' found twice");
	else
		already_have_a_comment = TRUE;
	comment_value = ft_strchr(line, ' ');
	if (comment_value == NULL || comment_value - line != 8)
		failure("command '.comment' incorrectly formatted");
	comment_value++;
	if (ft_strlen(comment_value) > COMMENT_LENGTH + 2)
		failure("value for the command '.comment' too long");
	if (is_string_value_well_formatted(comment_value) == FALSE)
		failure("command '.comment' incorrectly formatted");
	return (TRUE);
}
