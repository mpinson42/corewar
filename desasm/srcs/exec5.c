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

int		ft_ld2(t_champ *c, t_vm *vm, int fd, unsigned char str[4])
{
	if (vm->map[c->reg[0] + 1] == 208)
	{
		str[2] = vm->map[c->reg[0] + 3];
		str[3] = vm->map[c->reg[0] + 2];
		ft_putchar_fd('%', fd);
		ft_putnbr_fd(*(short*)&str[2], fd);
		ft_putstr_fd(",r", fd);
		ft_putnbr_fd(vm->map[c->reg[0] + 4], fd);
		return (4);
	}
	else if (vm->map[c->reg[0] + 1] == 144)
	{
		str[0] = vm->map[c->reg[0] + 2];
		str[1] = vm->map[c->reg[0] + 3];
		str[2] = vm->map[c->reg[0] + 4];
		str[3] = vm->map[c->reg[0] + 5];
		ft_putchar_fd('%', fd);
		ft_putnbr_fd(ft_conv_int(str), fd);
		ft_putstr_fd(",r", fd);
		ft_putnbr_fd(vm->map[c->reg[0] + 6], fd);
		return (6);
	}
	return (0);
}

void	ft_ld(t_champ *c, t_vm *vm, int fd)
{
	unsigned int	oct;
	unsigned char	str[4];

	ft_putstr_fd("ld ", fd);
	oct = ft_ld2(c, vm, fd, str);
	ft_putstr_fd("\n", fd);
	vm->map_pc[c->reg[0]]--;
	c->reg[0] += oct + 1;
	vm->map_pc[c->reg[0]]++;
}

void	ft_lld(t_champ *c, t_vm *vm, int fd)
{
	unsigned int	oct;
	unsigned char	str[4];

	ft_putstr_fd("lld ", fd);
	oct = ft_ld2(c, vm, fd, str);
	ft_putchar_fd('\n', fd);
	c->reg[0] += oct + 1;
}

int		ft_st2(t_champ *c, t_vm *vm, int fd, unsigned char str[4])
{
	if (vm->map[c->reg[0] + 1] == 80)
	{
		ft_putstr_fd("r", fd);
		ft_putnbr_fd(vm->map[c->reg[0] + 2], fd);
		ft_putstr_fd(",", fd);
		ft_putstr_fd("r", fd);
		ft_putnbr_fd(vm->map[c->reg[0] + 3], fd);
		return (3);
	}
	if (vm->map[c->reg[0] + 1] == 112)
	{
		ft_putstr_fd("r", fd);
		ft_putnbr_fd(vm->map[c->reg[0] + 2], fd);
		ft_putstr_fd(",", fd);
		str[2] = vm->map[c->reg[0] + 4];
		str[3] = vm->map[c->reg[0] + 3];
		ft_putnbr_fd(*(short*)&str[2], fd);
		return (4);
	}
	return (0);
}

void	ft_st(t_champ *c, t_vm *vm, int fd)
{
	unsigned int	oct;
	unsigned char	str[4];

	ft_putstr_fd("st ", fd);
	oct = ft_st2(c, vm, fd, str);
	ft_putstr_fd("\n", fd);
	vm->map_pc[c->reg[0]]--;
	c->reg[0] += oct + 1;
	vm->map_pc[c->reg[0]]++;
}
