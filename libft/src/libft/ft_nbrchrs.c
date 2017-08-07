/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrchrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sol <sol@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 08:04:08 by apieropa          #+#    #+#             */
/*   Updated: 2015/03/04 12:12:49 by sol              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_nbrchrs(const char *str, char *chrs)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	while (str[i] != '\0')
	{
		if (ft_strchr(chrs, str[i]) != NULL)
			nb++;
		i++;
	}
	return (nb);
}
