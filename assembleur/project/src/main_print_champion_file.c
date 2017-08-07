/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_print_champion_file.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 20:03:21 by apieropa          #+#    #+#             */
/*   Updated: 2017/07/27 20:03:23 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	open_champion_file(char *filename)
{
	int		fd;
	char	*new_name;
	uint	new_name_len;

	new_name_len = ft_strlen(filename) + 2;
	if ((new_name = ft_strnew(new_name_len + 1)) == NULL)
		failure(ERR_MALLOC);
	ft_strcpy(new_name, filename);
	ft_strcpy(new_name + new_name_len - 3, "cor");
	fd = open(new_name, FILE_OPTIONS, FILE_RIGHTS);
	if (fd == -1)
		failure("couldn't create champion file");
	ft_printf("Writing output program to %s\n", new_name);
	free(new_name);
	return (fd);
}

static void	print_arg(t_arg arg, int fd)
{
	char	c[4];

	if (arg.octet_nb == 1)
	{
		c[0] = arg.value;
		write(fd, &c, 1);
	}
	if (arg.octet_nb == 2)
	{
		c[0] = (arg.value >> 8) & 0xff;
		c[1] = (arg.value >> 0) & 0xff;
		write(fd, &c, 2);
	}
	if (arg.octet_nb == 4)
	{
		c[0] = (arg.value >> 24) & 0xff;
		c[1] = (arg.value >> 16) & 0xff;
		c[2] = (arg.value >> 8) & 0xff;
		c[3] = (arg.value >> 0) & 0xff;
		write(fd, &c, 4);
	}
}

static void	print_instructions(t_instr *instrs, int fd)
{
	uint	i;
	uint	ai;

	i = 0;
	while (instrs[i].line != NULL)
	{
		write(fd, &instrs[i].op->opcode, 1);
		if (instrs[i].op->has_args_desc_octet)
			write(fd, &instrs[i].args_desc_octet, 1);
		ai = 0;
		while (ai < instrs[i].args_nb)
		{
			print_arg(instrs[i].args[ai], fd);
			ai++;
		}
		i++;
	}
}

void		print_champion_to_file(t_header *header,
	t_instr *instrs, char *filename)
{
	int		fd;

	fd = open_champion_file(filename);
	write(fd, (char *)header, sizeof(t_header));
	print_instructions(instrs, fd);
}
