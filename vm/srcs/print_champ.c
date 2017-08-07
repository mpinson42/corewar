/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_champ.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 15:06:56 by mpinson           #+#    #+#             */
/*   Updated: 2017/08/04 15:06:58 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			print_champ1(int count, t_champ *champs)
{
	if (count == 2 && champs[0].id)
		ft_printf("\033[0m|       player %-*d|\n| |", 41, champs[0].id);
	else if (count == 2)
		ft_printf("\033[0m|       %-*s|\n| |", 48, "player NAN :");
	else if (count == 3 && champs[0].name[0])
		ft_printf("\033[0m|       player %-*d|\n| |", 41, champs[0].id);
	else if (count == 3 && !champs[0].name[0])
		ft_printf("\033[0m|       %-*s|\n| |", 48, "NAN");
	else if (count == 4 && !champs[0].last_live)
		ft_printf("\033[0m|           %-*s|\n| |", 44, "last live : NAN");
	else if (count == 4 && champs[0].last_live)
		ft_printf("\033[0m|           %-*s: %-*d|\n| |", 24, "last live",
				18, champs[0].last_live);
	else if (count == 5 && !champs[0].live)
		ft_printf("\033[0m|           %-*s|\n| |", 44, "last live : NAN");
	else if (count == 5 && champs[0].live)
		ft_printf("\033[0m|           %-*s%-*d|\n| |", 23,
				"Lives in current period : ", 18, champs[0].live);
}

void			print_champ2(int count, t_champ *champs)
{
	if (count == 7 && champs[1].id)
		ft_printf("\033[0m|       player %-*d|\n| |", 41, champs[1].id);
	else if (count == 7)
		ft_printf("\033[0m|       %-*s|\n| |", 48, "player NAN :");
	else if (count == 8 && champs[1].name[0])
		ft_printf("\033[0m|       \033[0;34m%-*.48s\033[0;m|\n| |", 48,
				champs[1].name);
	else if (count == 8 && !champs[1].name[0])
		ft_printf("\033[0m|       %-*s|\n| |", 48, "NAN");
	else if (count == 9 && !champs[1].last_live)
		ft_printf("\033[0m|           %-*s|\n| |", 44, "last live : NAN");
	else if (count == 9 && champs[1].last_live)
		ft_printf("\033[0m|           %-*s: %-*d|\n| |", 24, "last live",
				18, champs[1].last_live);
	else if (count == 10 && !champs[1].live)
		ft_printf("\033[0m|           %-*s|\n| |", 44, "last live : NAN");
	else if (count == 10 && champs[1].live)
		ft_printf("\033[0m|           %-*s%-*d|\n| |", 23,
				"Lives in current period : ", 18, champs[1].live);
}

void			print_champ3(int count, t_champ *champs)
{
	if (count == 12 && champs[2].id)
		ft_printf("\033[0m|       player %-*d|\n| |", 41, champs[2].id);
	else if (count == 12)
		ft_printf("\033[0m|       %-*s|\n| |", 48, "player NAN :");
	else if (count == 13 && champs[2].name[0])
		ft_printf("\033[0m|       player %-*d|\n| |", 41, champs[2].id);
	else if (count == 13 && !champs[2].name[0])
		ft_printf("\033[0m|       %-*s|\n| |", 48, "NAN");
	else if (count == 14 && !champs[2].last_live)
		ft_printf("\033[0m|           %-*s|\n| |", 44, "last live : NAN");
	else if (count == 14 && champs[2].last_live)
		ft_printf("\033[0m|           %-*s: %-*d|\n| |", 24, "last live",
				18, champs[2].last_live);
	else if (count == 15 && !champs[2].live)
		ft_printf("\033[0m|           %-*s|\n| |", 44, "last live : NAN");
	else if (count == 15 && champs[2].live)
		ft_printf("\033[0m|           %-*s%-*d|\n| |", 23,
				"Lives in current period : ", 18, champs[2].live);
}

void			print_champ4(int count, t_champ *champs)
{
	if (count == 17 && champs[3].id)
		ft_printf("\033[0m|       player %-*d|\n| |", 41, champs[3].id);
	else if (count == 17)
		ft_printf("\033[0m|       %-*s|\n| |", 48, "player NAN :");
	else if (count == 18 && champs[3].name[0])
		ft_printf("\033[0m|       player %-*d|\n| |", 41, champs[1].id);
	else if (count == 18 && !champs[3].name[0])
		ft_printf("\033[0m|       %-*s|\n| |", 48, "NAN");
	else if (count == 19 && !champs[3].last_live)
		ft_printf("\033[0m|           %-*s|\n| |", 44, "last live : NAN");
	else if (count == 19 && champs[3].last_live)
		ft_printf("\033[0m|           %-*s: %-*d|\n| |", 24, "last live",
				18, champs[3].last_live);
	else if (count == 20 && !champs[3].live)
		ft_printf("\033[0m|           %-*s|\n| |", 44, "last live : NAN");
	else if (count == 20 && champs[3].live)
		ft_printf("\033[0m|           %-*s%-*d|\n| |", 23,
				"Lives in current period : ", 18, champs[3].live);
}

void			print_data(int count, t_champ *champs, t_data *data)
{
	if (count == 22)
		ft_printf("\033[0m|       Cycle : %-*d|\n| |", 40,
				data->total_cycles);
	else if (count == 24)
		ft_printf("\033[0m|       Prossesus : %-*d|\n| |", 36,
				champs[0].nb_process + champs[1].nb_process +
				champs[2].nb_process + champs[3].nb_process);
	else if (count == 26)
		ft_printf("\033[0m|       CYCLE_TO_DIE : %-*d|\n| |", 33,
				data->cycle_to_die);
	else if (count == 28)
		ft_printf("\033[0m|       CYCLE_DELTA : %-*d|\n| |", 34,
				data->cycle_delta);
	else if (count == 29)
		ft_printf("\033[0m|       CYCLE_DELTA : %-*d|\n| |", 34,
				data->cycle_delta);
	else
	{
		ft_printf("\033[0m|                                 ");
		ft_printf("                      |\n| |");
	}
}
