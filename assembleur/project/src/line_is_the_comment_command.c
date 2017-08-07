/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_is_the_comment_command.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 20:01:20 by apieropa          #+#    #+#             */
/*   Updated: 2017/07/27 20:01:21 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cor.h"

/*
** Ligne 20: 8 pour la longueur de `.comment`
** Ligne 23: +2 pour les `"` entourant la str
*/

t_bool	line_is_the_comment_command(char *line)
{
	char			*comment_value;
	static t_bool	already_have_a_comment = FALSE;

	if (str_starts_with(line, COMMENT_CMD_STRING) != TRUE)
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
