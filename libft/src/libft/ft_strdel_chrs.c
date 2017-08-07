/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel_chrs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sol <sol@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 18:21:00 by apieropa          #+#    #+#             */
/*   Updated: 2015/03/04 12:18:52 by sol              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdel_chrs(char *str, char *chrs)
{
	int		i;
	int		j;
	char	*nstr;

	nstr = ft_strnew(ft_strlen(str) - ft_nbrchrs(str, chrs));
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (ft_strchr(chrs, str[i]) == NULL)
		{
			nstr[j] = str[i];
			j++;
		}
		i++;
	}
	return (nstr);
}
