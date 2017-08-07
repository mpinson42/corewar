/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_ops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 15:07:51 by mpinson           #+#    #+#             */
/*   Updated: 2017/08/04 15:07:53 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

extern	char *g_mem;
extern	char *g_map_color;

char	*get_addr_in_mem(char *addr)
{
	size_t	diff;

	if (addr < g_mem)
	{
		diff = (g_mem - addr) % MEM_SIZE;
		return (g_mem + MEM_SIZE - diff);
	}
	else if (addr >= g_mem + MEM_SIZE)
	{
		diff = addr - g_mem;
		return (g_mem + (diff % MEM_SIZE));
	}
	else
		return (addr);
}

void	store_int16(t_op_arg arg, int16_t n, int id)
{
	size_t		diff;
	char		*addr;
	t_arg_type	type;

	addr = (char *)arg.addr;
	type = arg.type;
	diff = (addr - g_mem) % MEM_SIZE;
	if (type != IND_CODE || (addr >= g_mem && addr < g_mem + MEM_SIZE - 2))
	{
		*(int16_t *)addr = n;
		*(int16_t *)(g_map_color + diff) = 0x101 * (id + 1);
	}
	else
	{
		g_mem[MEM_SIZE - 1] = (char)(n >> 8);
		g_mem[0] = (char)(n & 0x00ff);
		g_map_color[MEM_SIZE - 1] = (char)(id + 1);
		g_map_color[0] = (char)(id + 1);
	}
}

void	store_int32(t_op_arg arg, int32_t n, int id)
{
	size_t		diff;
	char		*addr;
	t_arg_type	type;

	addr = (char *)arg.addr;
	type = arg.type;
	diff = (addr - g_mem) % MEM_SIZE;
	if (type != IND_CODE || (addr >= g_mem && addr < g_mem + MEM_SIZE - 4))
	{
		*(int32_t *)addr = n;
		*(int32_t *)(g_map_color + diff) = 0x1010101 * (id + 1);
	}
	else
	{
		g_mem[diff] = (char)(n >> 24);
		g_mem[(diff + 1) % MEM_SIZE] = (char)(n & 0x00ff0000 >> 16);
		g_mem[(diff + 2) % MEM_SIZE] = (char)(n & 0x0000ff00 >> 8);
		g_mem[(diff + 3) % MEM_SIZE] = (char)(n & 0x000000ff);
		g_map_color[diff] = (char)(id + 1);
		g_map_color[(diff + 1) % MEM_SIZE] = (char)(id + 1);
		g_map_color[(diff + 1) % MEM_SIZE] = (char)(id + 1);
		g_map_color[(diff + 1) % MEM_SIZE] = (char)(id + 1);
	}
}

int16_t	load_int16(t_op_arg arg)
{
	char		*addr;
	t_arg_type	type;

	addr = (char *)arg.addr;
	type = arg.type;
	if (type != IND_CODE || (addr >= g_mem && addr < g_mem + MEM_SIZE - 2))
		return (*(int16_t *)addr);
	else
		return (g_mem[MEM_SIZE - 1] << 8 | g_mem[0]);
}

int32_t	load_int32(t_op_arg arg)
{
	int32_t		ret;
	size_t		diff;
	char		*addr;
	t_arg_type	type;

	addr = (char *)arg.addr;
	type = arg.type;
	if (type != IND_CODE || (addr >= g_mem && addr < g_mem + MEM_SIZE - 4))
		return (*(int32_t *)addr);
	else
	{
		diff = addr - g_mem;
		ret = g_mem[diff] << 24
			| g_mem[(diff + 1) % MEM_SIZE] << 16
			| g_mem[(diff + 2) % MEM_SIZE] << 8
			| g_mem[(diff + 3) % MEM_SIZE];
		return (ret);
	}
}
