/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dump_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sol <sol@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 11:15:01 by apieropa          #+#    #+#             */
/*   Updated: 2015/03/03 17:56:10 by sol              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_dump_str(char *str, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		if (str[i] == '\0')
			ft_putstr("\\0");
		else if (str[i] == '\n')
			ft_putstr("\\n");
		else if (str[i] == '\t')
			ft_putstr("\\t");
		else if (str[i] == ' ')
			ft_putstr("'sp'");
		else if (str[i] == '\\')
			ft_putstr("\\");
		else
			ft_putchar(str[i]);
		i++;
	}
}
