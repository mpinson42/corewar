/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 20:01:57 by apieropa          #+#    #+#             */
/*   Updated: 2017/07/27 20:01:59 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		initialize(char ***lines, t_header *header, t_instr **instrs)
{
	if ((*lines = (char**)malloc(sizeof(char*) * (MAX_FILE_LINES + 1))) == NULL)
		failure(ERR_MALLOC);
	ft_bzero(*lines, sizeof(char*) * (MAX_FILE_LINES + 1));
	ft_bzero(instrs, sizeof(t_instr) * (MAX_FILE_LINES + 1));
	ft_bzero(header, sizeof(t_header));
	header->magic = COREWAR_EXEC_MAGIC;
}

static void		deallocate(char ***lines, t_instr *instrs)
{
	uint	i;
	uint	ai;

	i = 0;
	while (instrs[i].line != NULL)
	{
		free(instrs[i].instr);
		if (instrs[i].has_label == TRUE)
			free(instrs[i].label_name);
		ai = 0;
		while (ai < instrs[i].args_nb)
		{
			free(instrs[i].args[ai].str);
			ai++;
		}
		i++;
	}
	str_array_del(lines);
}

void			ft_putstr2(char *str)
{
	int i;

	i = 0;
	while (i < (int)ft_strlen(str))
	{
		if (str[i] == 'd' || str[i] == '8' || str[i] == 'b'
			|| str[i] == '9' || str[i] == 'P')
			write(1, "\033[1;33m", 8);
		else if (str[i] == 'O')
			write(1, "\033[0;31m", 8);
		else if (str[i] == '=')
			write(1, "\033[1;34m", 8);
		else
			write(1, "\033[1;31m", 8);
		ft_putchar(str[i]);
		i++;
	}
}

void			ft_bonus(void)
{
	ft_putstr2("      O\n");
	ft_putstr("   ,-.\033[1;30m|____________________\n");
	ft_putstr("\033[1;30mO==+-|(>-------- --  -    \033[0;31m .>\n\033[0;m");
	ft_putstr(" \033[1;31m  '- \033[1;30m|\"\"\"\"");
	ft_putstr("\"\"\"\033[1;33md88b\033[0;31m\"\"\"\"\"\"\"\"\"\n\033[0;m");
	ft_putstr2("    | O     d8P 88b\n");
	ft_putstr2("    |  \\    88= ,=88\n");
	ft_putstr2("    |   )   9b _. 88b\n");
	ft_putstr2("    '._ '.   8'--\'888\n");
	ft_putstr2("     |    \\--\'\\   '-8___\n");
	ft_putstr2("      \\'-.              \\\n");
	ft_putstr2("       '. \\ -       _ / <\n");
	ft_putstr2("         \\ '---   ___/|_-\\\n");
	ft_putstr2("          |._      _. |_-|\n");
	ft_putstr2("          \\  _     _  /.-\\\n");
	ft_putstr2("           | -! . !- ||   |\n");
	ft_putstr2("           \\ \"| ! |\" /\\   |\n");
	ft_putstr("    \033[0;31m        =oO)X(Oo=\033[1;31m  \\  /\n");
	ft_putstr2("            888888888   < \\\n");
	ft_putstr2("           d888888888b  \\_/\n");
	ft_putstr2("           88888888888\n");
	ft_putstr("\033[0;m");
}

int				main(int ac, char **av)
{
	char		**lines;
	t_header	header;
	t_instr		instrs[MAX_FILE_LINES + 1];

	if (ac != 2)
		failure("wrong number of arguments");
	initialize(&lines, &header, (t_instr **)&instrs);
	get_champion_lines(av[1], lines);
	check_champion_lines(lines);
	get_champion_program(lines, instrs, &header);
	ft_bonus();
	print_champion_to_file(&header, instrs, av[1]);
	deallocate(&lines, instrs);
	return (0);
}
