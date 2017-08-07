/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 15:22:37 by mpinson           #+#    #+#             */
/*   Updated: 2017/07/21 15:22:46 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_and2(t_champ *c, t_vm *vm, int fd, unsigned int *oct)
{
	unsigned char	str[4];

	if (vm->map[c->reg[0] + 1] == 116)
	{
		ft_putchar_fd('r', fd);
		ft_putnbr_fd(vm->map[c->reg[0] + 2], fd);
		ft_putstr_fd(",%", fd);
		str[2] = vm->map[c->reg[0] + 3];
		str[3] = vm->map[c->reg[0] + 4];
		ft_putnbr_fd(*(short*)&str[2], fd);
		ft_putstr_fd(",r", fd);
		ft_putnbr_fd(vm->map[c->reg[0] + 5], fd);
		oct[0] = 5;
	}
	if (vm->map[c->reg[0] + 1] == 84)
	{
		ft_putchar_fd('r', fd);
		ft_putnbr_fd(vm->map[c->reg[0] + 2], fd);
		ft_putstr_fd(",r", fd);
		ft_putnbr_fd(vm->map[c->reg[0] + 3], fd);
		ft_putstr_fd(",r", fd);
		ft_putnbr_fd(vm->map[c->reg[0] + 4], fd);
		oct[0] = 4;
	}
}

void	ft_and3(t_champ *c, t_vm *vm, int fd, unsigned int *oct)
{
	unsigned char	str[4];

	if (vm->map[c->reg[0] + 1] == 180)
	{
		str[0] = vm->map[c->reg[0] + 2];
		str[1] = vm->map[c->reg[0] + 3];
		str[2] = vm->map[c->reg[0] + 4];
		str[3] = vm->map[c->reg[0] + 5];
		ft_putchar_fd('%', fd);
		ft_putnbr_fd(ft_conv_int(str), fd);
		ft_putchar_fd(',', fd);
		str[2] = vm->map[c->reg[0] + 7];
		str[3] = vm->map[c->reg[0] + 6];
		ft_putnbr_fd(*(short*)&str[2], fd);
		ft_putstr_fd(",r", fd);
		ft_putnbr_fd(vm->map[c->reg[0] + 8], fd);
		oct[0] = 8;
	}
}

void	ft_and4(t_champ *c, t_vm *vm, int fd, unsigned int *oct)
{
	unsigned char	str[4];

	if (vm->map[c->reg[0] + 1] == 164)
	{
		str[0] = vm->map[c->reg[0] + 2];
		str[1] = vm->map[c->reg[0] + 3];
		str[2] = vm->map[c->reg[0] + 4];
		str[3] = vm->map[c->reg[0] + 5];
		ft_putchar_fd('%', fd);
		ft_putnbr_fd(ft_conv_int(str), fd);
		ft_putchar_fd(',', fd);
		str[0] = vm->map[c->reg[0] + 6];
		str[1] = vm->map[c->reg[0] + 7];
		str[2] = vm->map[c->reg[0] + 8];
		str[3] = vm->map[c->reg[0] + 9];
		ft_putchar_fd('%', fd);
		ft_putnbr_fd(ft_conv_int(str), fd);
		ft_putstr_fd(",r", fd);
		ft_putnbr_fd(vm->map[c->reg[0] + 10], fd);
		oct[0] = 10;
	}
}

void	ft_and5(t_champ *c, t_vm *vm, int fd, unsigned int *oct)
{
	unsigned char	str[4];

	if (vm->map[c->reg[0] + 1] == 148)
	{
		str[0] = vm->map[c->reg[0] + 2];
		str[1] = vm->map[c->reg[0] + 3];
		str[2] = vm->map[c->reg[0] + 4];
		str[3] = vm->map[c->reg[0] + 5];
		ft_putchar_fd('%', fd);
		ft_putnbr_fd(ft_conv_int(str), fd);
		ft_putstr_fd(",r", fd);
		ft_putnbr_fd(vm->map[c->reg[0] + 6], fd);
		ft_putstr_fd(",r", fd);
		ft_putnbr_fd(vm->map[c->reg[0] + 7], fd);
		oct[0] = 7;
	}
}

void	ft_and6(t_champ *c, t_vm *vm, int fd, unsigned int *oct)
{
	unsigned char	str[4];

	if (vm->map[c->reg[0] + 1] == 228)
	{
		str[2] = vm->map[c->reg[0] + 3];
		str[3] = vm->map[c->reg[0] + 2];
		ft_putchar_fd('%', fd);
		ft_putnbr_fd(*(short*)&str[2], fd);
		ft_putstr_fd(",%", fd);
		str[0] = vm->map[c->reg[0] + 4];
		str[1] = vm->map[c->reg[0] + 5];
		str[2] = vm->map[c->reg[0] + 6];
		str[3] = vm->map[c->reg[0] + 7];
		ft_putnbr_fd(ft_conv_int(str), fd);
		ft_putstr_fd(",r", fd);
		ft_putnbr_fd(vm->map[c->reg[0] + 8], fd);
		oct[0] = 8;
	}
	ft_and2(c, vm, fd, oct);
	ft_and3(c, vm, fd, oct);
	ft_and4(c, vm, fd, oct);
	ft_and5(c, vm, fd, oct);
}
