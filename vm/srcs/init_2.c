/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 12:22:39 by mpinson           #+#    #+#             */
/*   Updated: 2017/08/05 12:22:42 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

extern	char	*g_mem;
extern	char	*g_map_color;
extern	char	*g_map_pc;
extern	int		g_nb_process;

void			create_champ(t_data *data,
		t_champ *champs, int index, char *file)
{
	if (data->nbr_champs == MAX_PLAYERS)
		failure("Too many champions");
	else if (index < 0)
		index = get_first_champ_index(champs);
	else if (index >= MAX_PLAYERS || champs[index].file)
		failure("Wrong champion's index");
	champs[index].file = ft_strdup(file);
	champs[index].is_alive = 1;
	champs[index].is_dead = 0;
	champs[index].id = index;
	champs[index].nb_process = 0;
	data->nbr_champs++;
}

int				catch_argv2(t_data *data, t_champ *champs, char **argv, int *i)
{
	if (!ft_strcmp(argv[*i], "-dump"))
	{
		if (!argv[++*i] || !isnumberstr(argv[*i]))
			failure_usage();
		else
		{
			data->dump = 1;
			data->dump_cycle = ft_atoi(argv[*i]);
		}
	}
	else if (!ft_strcmp(argv[i[0]], "-n"))
	{
		if (!argv[*i + 1] || !isnumberstr(argv[*i + 1]) || !argv[*i + 2])
			failure_usage();
		else
		{
			create_champ(data, champs, ft_atoi(argv[*i + 1]), argv[*i + 2]);
			*i += 2;
		}
	}
	return (0);
}

void			catch_argv(t_data *data, t_champ *champs, char **argv)
{
	int		i;

	i = 0;
	while (argv[++i])
	{
		if (!ft_strcmp(argv[i], "-dump") || !ft_strcmp(argv[i], "-n"))
			catch_argv2(data, champs, argv, &i);
		else if (!ft_strcmp(argv[i], "-visu"))
		{
			if (!argv[++i] || !isnumberstr(argv[i]))
				failure_usage();
			else if ((data->is_there_visu = ft_atoi(argv[i])) <= 0)
				failure_usage();
			else
				ft_printf_fd(2, "Visu opt: %d\n", data->is_there_visu);
		}
		else
			create_champ(data, champs, -1, argv[i]);
	}
	if (!data->nbr_champs)
		failure_usage();
}

void			load_process2(t_load *l,
		t_champ *champs, t_data *data, char *mem)
{
	if ((unsigned int)l->ret <= sizeof(t_header))
		failure_file(champs[l->i].file, " is too small to be a champion");
	champs[l->i].header = *(t_header *)l->buffer;
	if (swap_uint32(champs[l->i].header.magic) != COREWAR_EXEC_MAGIC)
		failure_file(champs[l->i].file, " has an invalid header");
	else if (swap_uint32(champs[l->i].header.prog_size) > CHAMP_MAX_SIZE)
		failure_file(champs[l->i].file, " has a too large code");
	else if (l->ret - sizeof(t_header) !=
			swap_uint32(champs[l->i].header.prog_size))
		failure_file(champs[l->i].file,
				" has a code size that differ from what its header says");
	ft_printf_fd(1, "load_champ %s %p %d/%d \n",
			champs[l->i].file, (void*)mem, l->i, data->nbr_champs);
	ft_memcpy(champs[l->i].name,
			champs[l->i].header.prog_name, PROG_NAME_LENGTH + 1);
	ft_memcpy(champs[l->i].comment,
			champs[l->i].header.comment, COMMENT_LENGTH + 1);
	ft_memcpy(mem, l->buffer + sizeof(t_header),
			l->ret - sizeof(t_header));
	ft_printf_fd(2, "Mem: %ld %ld\n", mem - g_mem,
			mem - g_mem + champs[l->i].header.prog_size);
	l->i2 = -1;
}

t_process_list	*load_process(char *mem, t_champ *champs, t_data *data)
{
	t_load l;

	l.i = -1;
	ft_putstr("Introducing contestants...\n");
	l.process_list = NULL;
	while (++l.i < MAX_PLAYERS)
	{
		if (!champs[l.i].file)
			continue ;
		if ((l.fd = open(champs[l.i].file, O_RDONLY)) < 0)
			failure("cant open champion file for reading");
		if ((l.ret = read(l.fd, l.buffer,
						sizeof(t_header) + CHAMP_MAX_SIZE)) > 0)
		{
			load_process2(&l, champs, data, mem);
			while (++l.i2 < (int)swap_uint32(champs[l.i].header.prog_size))
				*(g_map_color + (mem - g_mem) + l.i2) = (char)(l.i + 1);
			l.process_list = add_process_to_begin(l.process_list,
					l.i, mem, champs);
			mem += (MEM_SIZE / data->nbr_champs);
		}
		else
			failure_file(champs[l.i].file, " Can't read source file");
	}
	return (l.process_list);
}
