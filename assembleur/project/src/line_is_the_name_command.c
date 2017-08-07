/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_is_the_name_command.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 20:01:31 by apieropa          #+#    #+#             */
/*   Updated: 2017/07/27 20:01:33 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cor.h"

/*
** Ligne 20: 5 pour la longueur de `.name`
** Ligne 23: +2 pour les `"` entourant la str
*/

t_bool	line_is_the_name_command(char *line)
{
	char			*name_value;
	static t_bool	already_have_a_name = FALSE;

	if (str_starts_with(line, NAME_CMD_STRING) != TRUE)
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
