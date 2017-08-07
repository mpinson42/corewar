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

void	ft_add(t_champ *c, t_vm *vm, int fd)
{
	ft_putstr_fd("add ", fd);
	ft_putchar_fd('r', fd);
	ft_putnbr_fd(vm->map[c->reg[0] + 2], fd);
	ft_putchar_fd(',', fd);
	ft_putchar_fd('r', fd);
	ft_putnbr_fd(vm->map[c->reg[0] + 3], fd);
	ft_putchar_fd(',', fd);
	ft_putchar_fd('r', fd);
	ft_putnbr_fd(vm->map[c->reg[0] + 4], fd);
	ft_putchar_fd('\n', fd);
	c->reg[0] += 5;
}

void	ft_sub(t_champ *c, t_vm *vm, int fd)
{
	ft_putstr_fd("sub ", fd);
	ft_putchar_fd('r', fd);
	ft_putnbr_fd(vm->map[c->reg[0] + 2], fd);
	ft_putchar_fd(',', fd);
	ft_putchar_fd('r', fd);
	ft_putnbr_fd(vm->map[c->reg[0] + 3], fd);
	ft_putchar_fd(',', fd);
	ft_putchar_fd('r', fd);
	ft_putnbr_fd(vm->map[c->reg[0] + 4], fd);
	ft_putchar_fd('\n', fd);
	c->reg[0] += 5;
}

void	ft_aff(t_champ *c, t_vm *vm, int fd)
{
	if (vm->map[c->reg[0] + 1] != 64)
		return ;
	ft_putstr_fd("aff r", fd);
	ft_putnbr_fd(vm->map[c->reg[0] + 2], fd);
	ft_putchar_fd('\n', fd);
	vm->map_pc[c->reg[0]]--;
	c->reg[0] += 3;
	vm->map_pc[c->reg[0]]++;
}

void	ft_fork(t_champ *c, t_vm *vm, int fd)
{
	unsigned char	str[4];
	int				i;

	write(fd, "fork %", 6);
	str[0] = 0;
	str[1] = 0;
	str[2] = vm->map[c->reg[0] + 2];
	str[3] = vm->map[c->reg[0] + 1];
	i = *(short*)&str[2];
	ft_putnbr_fd(i, fd);
	write(fd, "\n", 1);
	c->reg[0] += 3;
}

void	ft_lfork(t_champ *c, t_vm *vm, int fd)
{
	unsigned char	str[4];
	int				i;

	write(fd, "lfork %", 7);
	str[0] = 0;
	str[1] = 0;
	str[2] = vm->map[c->reg[0] + 2];
	str[3] = vm->map[c->reg[0] + 1];
	i = *(short*)&str[2];
	ft_putnbr_fd(i, fd);
	write(fd, "\n", 1);
	c->reg[0] += 3;
}
