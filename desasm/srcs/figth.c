/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figth.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 15:29:06 by mpinson           #+#    #+#             */
/*   Updated: 2017/07/21 15:29:08 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_live(t_champ *c, t_vm *vm, int fd)
{
	unsigned char	str[4];
	unsigned int	i;

	i = 0;
	write(fd, "live %", 6);
	str[0] = vm->map[c->reg[0] + 1];
	str[1] = vm->map[c->reg[0] + 2];
	str[2] = vm->map[c->reg[0] + 3];
	str[3] = vm->map[c->reg[0] + 4];
	ft_putnbr_fd(ft_conv_int(str), fd);
	write(fd, "\n", 1);
	c->reg[0] += 5;
}

void	ft_zjmp(t_champ *c, t_vm *vm, int fd)
{
	unsigned char	str[4];
	int				i;

	write(fd, "zjmp %", 6);
	str[0] = 0;
	str[1] = 0;
	str[2] = vm->map[c->reg[0] + 2];
	str[3] = vm->map[c->reg[0] + 1];
	i = *(short*)&str[2];
	ft_putnbr_fd(i, fd);
	write(fd, "\n", 1);
	c->reg[0] += 3;
}

void	ft_suit2(t_champ *c, t_vm *vm, int fd)
{
	if (vm->map[c->reg[0]] == 10)
		ft_ldi(c, vm, fd);
	else if (vm->map[c->reg[0]] == 11)
		ft_sti(c, vm, fd);
	else if (vm->map[c->reg[0]] == 12)
		ft_fork(c, vm, fd);
	else if (vm->map[c->reg[0]] == 13)
		ft_lld(c, vm, fd);
	else if (vm->map[c->reg[0]] == 14)
		ft_lldi(c, vm, fd);
	else if (vm->map[c->reg[0]] == 15)
		ft_lfork(c, vm, fd);
	else if (vm->map[c->reg[0]] == 16)
		ft_aff(c, vm, fd);
	else
		c->reg[0]++;
}

void	ft_suit_exec(t_champ *c, t_vm *vm, int fd)
{
	if (vm->map[c->reg[0]] == 1)
		ft_live(c, vm, fd);
	else if (vm->map[c->reg[0]] == 2)
		ft_ld(c, vm, fd);
	else if (vm->map[c->reg[0]] == 3)
		ft_st(c, vm, fd);
	else if (vm->map[c->reg[0]] == 4)
		ft_add(c, vm, fd);
	else if (vm->map[c->reg[0]] == 5)
		ft_sub(c, vm, fd);
	else if (vm->map[c->reg[0]] == 6)
		ft_and(c, vm, fd);
	else if (vm->map[c->reg[0]] == 7)
		ft_or(c, vm, fd);
	else if (vm->map[c->reg[0]] == 8)
		ft_xor(c, vm, fd);
	else if (vm->map[c->reg[0]] == 9)
		ft_zjmp(c, vm, fd);
	else
		ft_suit2(c, vm, fd);
}

void	ft_go_figth(t_vm *vm)
{
	int j;
	int fd2;

	fd2 = open("decompil.s",
		O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	ft_putstr_fd(".name \"", fd2);
	ft_putstr_fd(vm->champ[0].vrai_name, fd2);
	ft_putstr_fd("\"\n.comment \"", fd2);
	ft_putstr_fd(vm->champ[0].commante, fd2);
	ft_putstr_fd("\"\n\n", fd2);
	while (vm->champ[0].reg[0] < vm->champ[0].leng)
	{
		j = 0;
		ft_suit_exec(&vm->champ[0], vm, fd2);
		vm->cycle++;
	}
}
