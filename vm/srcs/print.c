/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 13:18:08 by mpinson           #+#    #+#             */
/*   Updated: 2017/08/04 14:58:04 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

extern	char *g_mem;
extern	char *g_map_color;
extern	char *g_map_pc;

void			debut_affiche(int *ret, int *len, int *i2, int *count)
{
	int i;

	i = -1;
	ret[0] = 1;
	len[0] = 0;
	i2[0] = -1;
	count[0] = 0;
	usleep(50000);
	write(1, "\033[0;0H", 6);
	while (++i < 250 + 1)
		ft_printf("-");
	ft_printf("|\n| ");
	i = -1;
	while (++i < 250 - 1)
		ft_printf(" ");
	i = -1;
	ft_printf("|\n| ");
	while (++i < 3 * 65 - 1)
		ft_printf("_");
	ft_printf("                           ");
	ft_printf("                            |\n| |");
}

void			fin_affiche(void)
{
	int i;

	ft_printf("|                            ");
	ft_printf("                           |\n| |");
	i = -1;
	while (++i < 3 * 65 - 2)
		ft_printf("-");
	ft_printf("                         ");
	ft_printf("                              |\n|");
	i = -1;
	while (++i < 250)
		ft_printf(" ");
	ft_printf("|\n");
	i = -1;
	while (++i < 250 + 2)
		ft_printf("-");
	ft_printf("\n");
}

void			ft_color(int len, t_champ *champs)
{
	if (g_map_color[len] == champs[0].id + 1)
		ft_printf("\033[0;32m");
	else if (g_map_color[len] == champs[1].id + 1)
		ft_printf("\033[0;34m");
	else if (g_map_color[len] == champs[2].id + 1)
		ft_printf("\033[0;31m");
	else if (g_map_color[len] == champs[3].id + 1)
		ft_printf("\033[0;35m");
	else
		ft_printf("\033[0m");
	if (g_map_pc[len] >= 1)
		ft_printf("\033[7m");
	ft_printf("%0.2x ", (unsigned char)g_mem[len]);
}

void			print_champ(int count, t_champ *champs, t_data *data)
{
	if (count >= 2 && count <= 5)
		print_champ1(count, champs);
	else if (count >= 7 && count <= 10)
		print_champ2(count, champs);
	else if (count >= 12 && count <= 15)
		print_champ3(count, champs);
	else if (count >= 17 && count <= 20)
		print_champ4(count, champs);
	else
		print_data(count, champs, data);
}

void			ft_affiche_map(t_data *data, t_champ *champs)
{
	int len;
	int ret;
	int i;
	int count;

	debut_affiche(&ret, &len, &i, &count);
	while (len < 4 * 1024)
	{
		if (ret == 65)
		{
			ret = 1;
			count++;
			print_champ(count, champs, data);
		}
		ft_color(len, champs);
		ret++;
		len++;
	}
	fin_affiche();
}
