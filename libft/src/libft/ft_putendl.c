/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 03:55:49 by apieropa          #+#    #+#             */
/*   Updated: 2014/09/28 12:52:08 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void		ft_putendl(const char *s)
{
	write(STDOUT_FILENO, s, ft_strlen(s));
	write(STDOUT_FILENO, "\n", 1);
}
