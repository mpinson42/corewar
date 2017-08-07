/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   div_str_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 19:59:56 by apieropa          #+#    #+#             */
/*   Updated: 2017/07/27 19:59:57 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	str_tabs_to_spaces(char *line)
{
	int		i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '\t')
			line[i] = ' ';
		i++;
	}
}

void	str_strip_leading_whitespaces(char *line)
{
	uint	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (i == 0)
		return ;
	ft_strcpy(line, line + i);
}

void	str_strip_trailling_comments(char *line)
{
	char	*comment_char_addr;

	comment_char_addr = ft_strchr(line, COMMENT_CHAR);
	if (comment_char_addr == NULL)
		return ;
	*comment_char_addr = '\0';
}

void	str_strip_trailing_whitespaces(char *line)
{
	uint	len;
	uint	pos;

	len = ft_strlen(line);
	if (len == 0)
		return ;
	len--;
	pos = len;
	while (line[pos] == ' ')
		pos--;
	if (pos == len)
		return ;
	line[pos + 1] = '\0';
}

void	str_compress_whitespaces(char *line)
{
	uint	i;

	i = 0;
	while (line[i] != '\0' && line[i] != '"')
	{
		if (line[i] == ' ' && line[i + 1] == ' ')
		{
			ft_strcpy(line + i, line + i + 1);
			i = 0;
		}
		else
			i++;
	}
}
