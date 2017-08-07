/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   div_failures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 19:59:19 by apieropa          #+#    #+#             */
/*   Updated: 2017/07/27 19:59:20 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		failure(char *error_message)
{
	ft_putstr_fd("asm error: ", 2);
	ft_putendl_fd(error_message, 2);
	exit(-1);
}

int		failure_at_line(char *error_message, uint linum)
{
	ft_printf_fd(2, "asm error: %s at line %u\n", error_message, linum);
	exit(-1);
}

int		failure_label(char *label)
{
	ft_printf_fd(2, "reference to a label that doesnt exists (%s)\n", label);
	exit(-1);
}
