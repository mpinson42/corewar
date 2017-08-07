/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mem_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 15:07:15 by mpinson           #+#    #+#             */
/*   Updated: 2017/08/04 15:07:16 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			buff_nbr_hexa(unsigned int n, int depth, char *hexa)
{
	char	*val;

	val = "0123456789abcdef";
	if (n / 16 != 0)
	{
		buff_nbr_hexa(n / 16, depth - 1, hexa);
		hexa[depth] = val[n % 16];
	}
	else
		hexa[depth] = val[n % 16];
}

void			print_mem(char *mem)
{
	size_t		i;
	char		hexa[10];

	i = 0;
	while (i < MEM_SIZE)
	{
		ft_strcpy(hexa, "0x0000 : ");
		if (!(i % 64))
		{
			buff_nbr_hexa(i, 5, hexa);
			write(1, hexa, 9);
		}
		ft_printf_fd(1, "%.2x", (unsigned char)mem[i]);
		if (!((i + 1) % 64))
			write(1, " \n", 2);
		else
			write(1, " ", 1);
		i++;
	}
}
