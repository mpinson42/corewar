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

void	ft_ldi2(t_champ *c, t_vm *vm, int fd, unsigned int *oct)
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
	if (vm->map[c->reg[0] + 1] == 100)
	{
		ft_putchar_fd('r', fd);
		ft_putnbr_fd(vm->map[c->reg[0] + 2], fd);
		ft_putchar_fd(',', fd);
		str[2] = vm->map[c->reg[0] + 4];
		str[3] = vm->map[c->reg[0] + 3];
		ft_putnbr_fd(*(short*)&str[2], fd);
		ft_putstr_fd(",r", fd);
		ft_putnbr_fd(vm->map[c->reg[0] + 5], fd);
		oct[0] = 5;
	}
}

void	ft_ldi3(t_champ *c, t_vm *vm, int fd, unsigned int *oct)
{
	unsigned char	str[4];

	if (vm->map[c->reg[0] + 1] == 148)
	{
		str[2] = vm->map[c->reg[0] + 3];
		str[3] = vm->map[c->reg[0] + 2];
		ft_putnbr_fd(*(short*)&str[2], fd);
		ft_putstr_fd(",r", fd);
		ft_putnbr_fd(vm->map[c->reg[0] + 4], fd);
		ft_putstr_fd(",r", fd);
		ft_putnbr_fd(vm->map[c->reg[0] + 5], fd);
		oct[0] = 5;
	}
	if (vm->map[c->reg[0] + 1] == 212)
	{
		ft_putchar_fd('%', fd);
		str[2] = vm->map[c->reg[0] + 3];
		str[3] = vm->map[c->reg[0] + 2];
		ft_putnbr_fd(*(short*)&str[2], fd);
		ft_putstr_fd(",r", fd);
		ft_putnbr_fd(vm->map[c->reg[0] + 4], fd);
		ft_putstr_fd(",r", fd);
		ft_putnbr_fd(vm->map[c->reg[0] + 5], fd);
		oct[0] = 5;
	}
}

void	ft_ldi4(t_champ *c, t_vm *vm, int fd, unsigned int *oct)
{
	unsigned char	str[4];

	if (vm->map[c->reg[0] + 1] == 164)
	{
		str[2] = vm->map[c->reg[0] + 3];
		str[3] = vm->map[c->reg[0] + 2];
		ft_putnbr_fd(*(short*)&str[2], fd);
		ft_putstr_fd(",%", fd);
		str[2] = vm->map[c->reg[0] + 5];
		str[3] = vm->map[c->reg[0] + 4];
		ft_putnbr_fd(*(short*)&str[2], fd);
		ft_putstr_fd(",r", fd);
		ft_putnbr_fd(vm->map[c->reg[0] + 6], fd);
		oct[0] = 6;
	}
	ft_ldi2(c, vm, fd, oct);
	ft_ldi3(c, vm, fd, oct);
}

void	ft_ldi(t_champ *c, t_vm *vm, int fd)
{
	unsigned int	oct;
	unsigned char	str[4];

	ft_putstr_fd("ldi ", fd);
	ft_ldi4(c, vm, fd, &oct);
	if (vm->map[c->reg[0] + 1] == 228)
	{
		ft_putchar_fd('%', fd);
		str[2] = vm->map[c->reg[0] + 3];
		str[3] = vm->map[c->reg[0] + 2];
		ft_putnbr_fd(*(short*)&str[2], fd);
		ft_putstr_fd(",%", fd);
		str[2] = vm->map[c->reg[0] + 5];
		str[3] = vm->map[c->reg[0] + 4];
		ft_putnbr_fd(*(short*)&str[2], fd);
		ft_putchar_fd(',', fd);
		ft_putnbr_fd(vm->map[c->reg[0] + 6], fd);
		oct = 6;
	}
	ft_putstr_fd("\n", fd);
	vm->map_pc[c->reg[0]]--;
	c->reg[0] += oct + 1;
	while (c->reg[0] > 2 * 2048)
		c->reg[0] -= 2 * 2048;
	vm->map_pc[c->reg[0]]++;
}

void	ft_lldi(t_champ *c, t_vm *vm, int fd)
{
	unsigned int	oct;
	unsigned char	str[4];

	str[0] = 0;
	str[1] = 0;
	ft_putstr_fd("lldi ", fd);
	ft_ldi4(c, vm, fd, &oct);
	if (vm->map[c->reg[0] + 1] == 228)
	{
		ft_putchar_fd('%', fd);
		str[2] = vm->map[c->reg[0] + 3];
		str[3] = vm->map[c->reg[0] + 2];
		ft_putnbr_fd(*(short*)&str[2], fd);
		ft_putstr_fd(",%", fd);
		str[2] = vm->map[c->reg[0] + 5];
		str[3] = vm->map[c->reg[0] + 4];
		ft_putnbr_fd(*(short*)&str[2], fd);
		ft_putchar_fd(',', fd);
		ft_putnbr_fd(vm->map[c->reg[0] + 6], fd);
		oct = 6;
	}
	ft_putchar_fd('\n', fd);
	c->reg[0] += oct + 1;
	vm->map_pc[c->reg[0]]++;
}
