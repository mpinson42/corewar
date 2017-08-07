/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_get_champion_lines.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 20:03:09 by apieropa          #+#    #+#             */
/*   Updated: 2017/07/27 20:03:11 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	get_champion_lines(char *filename, char **lines)
{
	int		fd;
	uint	line_number;
	int		gnl_ret;

	if (does_str_ends_with(filename, ".s") == FALSE)
		failure("champion file is not .s");
	if ((fd = open(filename, O_RDONLY)) == -1)
		failure("could not open champion file for reading");
	line_number = 0;
	while (42)
	{
		gnl_ret = get_next_line(fd, &lines[line_number]);
		if (gnl_ret == -1)
			failure("read(2) error while reading champion file");
		if (gnl_ret == 0)
			break ;
		line_number++;
	}
	line_number++;
	lines[line_number] = NULL;
	close(fd);
}
