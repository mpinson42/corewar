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

void	ft_sti2(t_champ *c, t_vm *vm, int fd, unsigned int *oct)
{
	unsigned char	str[4];

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
	if (vm->map[c->reg[0] + 1] == 116)
	{
		ft_putchar_fd('r', fd);
		ft_putnbr_fd(vm->map[c->reg[0] + 2], fd);
		ft_putstr_fd(",%", fd);
		str[2] = vm->map[c->reg[0] + 4];
		str[3] = vm->map[c->reg[0] + 3];
		ft_putnbr_fd(*(short*)&str[2], fd);
		ft_putstr_fd(",r", fd);
		ft_putnbr_fd(vm->map[c->reg[0] + 5], fd);
		oct[0] = 5;
	}
}

void	ft_sti3(t_champ *c, t_vm *vm, int fd, unsigned int *oct)
{
	unsigned char	str[4];

	if (vm->map[c->reg[0] + 1] == 88)
	{
		ft_putchar_fd('r', fd);
		ft_putnbr_fd(vm->map[c->reg[0] + 2], fd);
		ft_putstr_fd(",r", fd);
		ft_putnbr_fd(vm->map[c->reg[0] + 3], fd);
		ft_putchar_fd(',', fd);
		str[2] = vm->map[c->reg[0] + 5];
		str[3] = vm->map[c->reg[0] + 4];
		ft_putnbr_fd(*(short*)&str[2], fd);
		oct[0] = 5;
	}
}

void	ft_sti5(t_champ *c, t_vm *vm, int fd, unsigned int *oct)
{
	unsigned char	str[4];

	if (vm->map[c->reg[0] + 1] == 120)
	{
		ft_putchar_fd('r', fd);
		ft_putnbr_fd(vm->map[c->reg[0] + 2], fd);
		ft_putstr_fd(",%", fd);
		str[2] = vm->map[c->reg[0] + 4];
		str[3] = vm->map[c->reg[0] + 3];
		ft_putnbr_fd(*(short*)&str[2], fd);
		ft_putchar_fd(',', fd);
		str[2] = vm->map[c->reg[0] + 6];
		str[3] = vm->map[c->reg[0] + 5];
		ft_putnbr_fd(*(short*)&str[2], fd);
		oct[0] = 6;
	}
}

void	ft_sti4(t_champ *c, t_vm *vm, int fd, unsigned int *oct)
{
	unsigned char	str[4];

	if (vm->map[c->reg[0] + 1] == 100)
	{
		ft_putchar_fd('r', fd);
		ft_putnbr_fd(vm->map[c->reg[0] + 2], fd);
		ft_putstr_fd(",%", fd);
		str[2] = vm->map[c->reg[0] + 4];
		str[3] = vm->map[c->reg[0] + 3];
		ft_putnbr_fd(*(short*)&str[2], fd);
		ft_putstr_fd(",r", fd);
		ft_putnbr_fd(vm->map[c->reg[0] + 5], fd);
		oct[0] = 5;
	}
	ft_sti2(c, vm, fd, oct);
	ft_sti3(c, vm, fd, oct);
	ft_sti5(c, vm, fd, oct);
}

void	ft_sti(t_champ *c, t_vm *vm, int fd)
{
	unsigned int	oct;
	unsigned char	str[4];

	oct = 0;
	write(fd, "sti ", 4);
	ft_sti4(c, vm, fd, &oct);
	if (vm->map[c->reg[0] + 1] == 104)
	{
		ft_putchar_fd('r', fd);
		ft_putnbr_fd(vm->map[c->reg[0] + 2], fd);
		ft_putchar_fd(',', fd);
		str[2] = vm->map[c->reg[0] + 4];
		str[3] = vm->map[c->reg[0] + 3];
		ft_putnbr_fd(*(short*)&str[2], fd);
		ft_putchar_fd(',', fd);
		str[2] = vm->map[c->reg[0] + 6];
		str[3] = vm->map[c->reg[0] + 5];
		ft_putchar_fd('%', fd);
		ft_putnbr_fd(*(short*)&str[2], fd);
		oct = 6;
	}
	ft_putchar_fd('\n', fd);
	c->reg[0] += oct + 1;
}
