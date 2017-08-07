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

void	ft_and7(t_champ *c, t_vm *vm, int fd, unsigned int *oct)
{
	unsigned char	str[4];

	if (vm->map[c->reg[0] + 1] == 244)
	{
		str[2] = vm->map[c->reg[0] + 2];
		str[3] = vm->map[c->reg[0] + 3];
		ft_putchar_fd('%', fd);
		ft_putnbr_fd(*(short*)&str[2], fd);
		ft_putstr_fd(",%", fd);
		str[2] = vm->map[c->reg[0] + 4];
		str[3] = vm->map[c->reg[0] + 5];
		ft_putnbr_fd(*(short*)&str[2], fd);
		ft_putstr_fd(",r", fd);
		ft_putnbr_fd(vm->map[c->reg[0] + 6], fd);
		oct[0] = 6;
	}
}

void	ft_and8(t_champ *c, t_vm *vm, int fd, unsigned int *oct)
{
	unsigned char	str[4];

	if (vm->map[c->reg[0] + 1] == 100)
	{
		ft_putchar_fd('r', fd);
		ft_putnbr_fd(vm->map[c->reg[0] + 2], fd);
		ft_putstr_fd(",%", fd);
		str[0] = vm->map[c->reg[0] + 3];
		str[1] = vm->map[c->reg[0] + 4];
		str[2] = vm->map[c->reg[0] + 5];
		str[3] = vm->map[c->reg[0] + 6];
		ft_putnbr_fd(ft_conv_int(str), fd);
		ft_putstr_fd(",r", fd);
		ft_putnbr_fd(vm->map[c->reg[0] + 7], fd);
		oct[0] = 7;
	}
}

void	ft_and(t_champ *c, t_vm *vm, int fd)
{
	unsigned int	oct;
	unsigned char	str[4];

	ft_putstr_fd("and ", fd);
	if (vm->map[c->reg[0] + 1] == 212)
	{
		str[2] = vm->map[c->reg[0] + 2];
		str[3] = vm->map[c->reg[0] + 3];
		ft_putchar_fd('%', fd);
		ft_putnbr_fd(*(short*)&str[2], fd);
		ft_putstr_fd(",r", fd);
		ft_putnbr_fd(vm->map[c->reg[0] + 4], fd);
		ft_putstr_fd(",r", fd);
		ft_putnbr_fd(vm->map[c->reg[0] + 5], fd);
		oct = 5;
	}
	ft_and6(c, vm, fd, &oct);
	ft_and7(c, vm, fd, &oct);
	ft_and8(c, vm, fd, &oct);
	ft_putchar_fd('\n', fd);
	c->reg[0] += oct + 1;
	while (c->reg[0] > 2 * 2048)
		c->reg[0] -= 2 * 2048;
}

void	ft_or(t_champ *c, t_vm *vm, int fd)
{
	unsigned int	oct;
	unsigned char	str[4];

	ft_putstr_fd("or ", fd);
	if (vm->map[c->reg[0] + 1] == 212)
	{
		str[2] = vm->map[c->reg[0] + 2];
		str[3] = vm->map[c->reg[0] + 3];
		ft_putchar_fd('%', fd);
		ft_putnbr_fd(*(short*)&str[2], fd);
		ft_putstr_fd(",r", fd);
		ft_putnbr_fd(vm->map[c->reg[0] + 4], fd);
		ft_putstr_fd(",r", fd);
		ft_putnbr_fd(vm->map[c->reg[0] + 5], fd);
		oct = 5;
	}
	ft_and6(c, vm, fd, &oct);
	ft_and7(c, vm, fd, &oct);
	ft_and8(c, vm, fd, &oct);
	ft_putchar_fd('\n', fd);
	c->reg[0] += oct + 1;
	while (c->reg[0] > 2 * 2048)
		c->reg[0] -= 2 * 2048;
}

void	ft_xor(t_champ *c, t_vm *vm, int fd)
{
	unsigned int	oct;
	unsigned char	str[4];

	ft_putstr_fd("xor ", fd);
	if (vm->map[c->reg[0] + 1] == 212)
	{
		str[2] = vm->map[c->reg[0] + 2];
		str[3] = vm->map[c->reg[0] + 3];
		ft_putchar_fd('%', fd);
		ft_putnbr_fd(*(short*)&str[2], fd);
		ft_putstr_fd(",r", fd);
		ft_putnbr_fd(vm->map[c->reg[0] + 4], fd);
		ft_putstr_fd(",r", fd);
		ft_putnbr_fd(vm->map[c->reg[0] + 5], fd);
		oct = 5;
	}
	ft_and6(c, vm, fd, &oct);
	ft_and7(c, vm, fd, &oct);
	ft_and8(c, vm, fd, &oct);
	ft_putchar_fd('\n', fd);
	c->reg[0] += oct + 1;
	while (c->reg[0] > 2 * 2048)
		c->reg[0] -= 2 * 2048;
}
