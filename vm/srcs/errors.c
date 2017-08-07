/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 15:12:25 by mpinson           #+#    #+#             */
/*   Updated: 2017/08/04 15:12:31 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	failure_usage(void)
{
	ft_putstr_fd(USAGE, 2);
	ft_putendl_fd(USAGE2, 2);
	exit(EXIT_FAILURE);
}

void	failure(char *message)
{
	ft_putstr_fd("corewar: ", 2);
	ft_putendl_fd(message, 2);
	exit(EXIT_FAILURE);
}

void	failure_malloc(void)
{
	ft_putstr_fd("corewar: ", 2);
	ft_putendl_fd("memory allocation error (malloc 3)", 2);
	exit(EXIT_FAILURE);
}

void	failure_file(char *file, char *error)
{
	ft_putstr_fd("Error: File ", 2);
	ft_putstr_fd(file, 2);
	ft_putendl_fd(error, 2);
	exit(EXIT_FAILURE);
}
