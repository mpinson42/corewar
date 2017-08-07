/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveniat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/06 02:23:01 by pveniat           #+#    #+#             */
/*   Updated: 2017/08/06 02:23:07 by pveniat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

extern char	*g_mem;
extern char	*g_map_pc;
extern char	*g_map_color;
extern int	g_nb_process;

t_process_list	*kill_process(t_data *data, t_process_list *process_to_kill,
	t_process_list **head, t_champ *champs)
{
	t_process_list *next;

	(void)data;
	ft_printf_fd(2, "Kill process\n");
	g_nb_process--;
	champs[process_to_kill->champ.id].nb_process--;
	if (process_to_kill->next == NULL && process_to_kill->prev == NULL)
	{
		*head = NULL;
		free(process_to_kill);
		return (NULL);
	}
	next = process_to_kill->next;
	if (process_to_kill->prev != NULL)
		process_to_kill->prev->next = next;
	else
		*head = next;
	if (next != NULL)
		next->prev = process_to_kill->prev;
	free(process_to_kill);
	return (next);
}

void			win_end_check(t_data *data, t_champ *champs,
	t_process_list *process_list)
{
	if (process_list->prev == NULL && process_list->next == NULL)
	{
		write(1, "le joueur ", 10);
		ft_putnbr(data->last_live);
		write(1, "(", 1);
		ft_putstr(champs[data->last_live].name);
		write(1, ") a gagne\n", 10);
		if (data->dump)
			print_mem(g_mem);
		exit_success();
	}
}

void			exit_success(void)
{
	free(g_map_pc);
	free(g_map_color);
	exit(EXIT_SUCCESS);
}
