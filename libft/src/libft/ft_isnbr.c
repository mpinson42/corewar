/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/18 20:39:41 by apieropa          #+#    #+#             */
/*   Updated: 2015/03/25 18:00:51 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool		ft_isnbr(const char *s)
{
	int		i;

	if (!(s[0] == '-' || s[0] == '+' || ft_isdigit(s[0]) != 0))
		return (FALSE);
	i = 1;
	while (s[i] != '\0')
	{
		if (ft_isdigit(s[i]) == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
