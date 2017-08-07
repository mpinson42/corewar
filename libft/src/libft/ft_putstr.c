/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 11:51:50 by apieropa          #+#    #+#             */
/*   Updated: 2015/03/27 20:08:10 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void		ft_putstr(const char *str)
{
	int		len;

	len = ft_strlen(str);
	if (len == 0)
		return ;
	write(STDOUT_FILENO, str, len);
}
