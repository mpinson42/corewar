/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 15:23:58 by mpinson           #+#    #+#             */
/*   Updated: 2017/07/21 16:11:15 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include <stdio.h>

int		ft_check_arg(t_vm *vm, int ac, char **av)
{
	int i;

	(void)ac;
	vm->joueur[0] = av[1];
	i = 0;
	while (i < 4)
	{
		if (vm->joueur[i])
		{
			if (vm->joueur[i][ft_strlen(vm->joueur[i]) - 1] != 'r' ||
				vm->joueur[i][ft_strlen(vm->joueur[i]) - 2] != 'o' ||
				vm->joueur[i][ft_strlen(vm->joueur[i]) - 3] != 'c' ||
				vm->joueur[i][ft_strlen(vm->joueur[i]) - 4] != '.')
			{
				ft_putstr("is not .cor\n");
				return (-1);
			}
		}
		i++;
	}
	return (0);
}

int		ft_init_champ(t_vm *vm)
{
	int i;
	int y;

	i = 0;
	y = 0;
	while (i < 4)
	{
		if (vm->joueur[i])
		{
			vm->champ[y].nb_joueur = -(i + 1);
			vm->champ[y].name = vm->joueur[i];
			vm->champ[y].reg[1] = -(i + 1);
			vm->champ[y].ici = 1;
			vm->champ[y].carry = 1;
			y++;
		}
		i++;
	}
	return (0);
}

int		ft_init_map2(t_vm *vm, int i, int fd, unsigned char str[4 * 1024])
{
	int lec;

	if (vm->champ[0].leng > 4 * 1024 / 6 ||
		ft_cher_leng_file(vm->champ[0].name) < 128 + 4 + 8 + 2048 + 3)
	{
		ft_putstr("mem too larg\n");
		return (-1);
	}
	ft_bzero(&str, 4 * 1024);
	read(fd, &str, 2048 + 4);
	vm->champ[0].commante = ft_strdup2(str);
	ft_bzero(&str, 4 * 1024);
	if (vm->champ[0].leng != ft_chr_leng(vm->champ[0].name))
	{
		ft_putstr("c est pas le meme taille\n");
		return (-1);
	}
	read(fd, &vm->champ[0].code, vm->champ[0].leng);
	lec = -1;
	i = -1;
	while (++lec < vm->champ[0].leng || !++i)
		vm->map[i] = vm->champ[0].code[lec];
	close(fd);
	return (0);
}

int		ft_init_map(t_vm *vm)
{
	int				fd;
	int				i;
	unsigned char	str[4 * 1024];

	i = 0;
	ft_bzero(&str, 4 * 1024);
	if ((fd = open(vm->champ[0].name, O_RDONLY)) == -1)
	{
		ft_putstr("error open failed\n");
		return (-1);
	}
	read(fd, &str, 4);
	if (str[0] != 0x00 || str[1] != 0xea || str[2] != 0x83 || str[3] != 0xf3)
	{
		ft_putstr("error nb magic\n");
		return (-1);
	}
	ft_bzero(&str, 4 * 1024);
	read(fd, &str, 128 + 4);
	vm->champ[0].vrai_name = ft_strdup2(str);
	read(fd, &str, 4);
	vm->champ[0].leng = ft_conv_int(str);
	if (ft_init_map2(vm, i, fd, str) == -1)
		return (-1);
	return (0);
}

int		main(int ac, char **av)
{
	t_vm vm;

	if (ac != 2)
		return (0);
	ft_bzero(&vm, sizeof(vm));
	if (ft_check_arg(&vm, ac, av) == -1)
		return (-1);
	ft_init_champ(&vm);
	if (ft_init_map(&vm) == -1)
		return (-1);
	ft_go_figth(&vm);
}
