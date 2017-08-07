/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmatch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sol <sol@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 08:50:10 by apieropa          #+#    #+#             */
/*   Updated: 2015/03/04 14:37:59 by sol              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			nmatch(char *str, char *regex)
{
	int		i;
	int		len;
	int		ret;

	if (str[0] == '\0' && regex[0] == '\0')
		return (1);
	if (regex[0] == '*' && regex[1] == '\0')
		return (1);
	if (str[0] == regex[0])
		return (nmatch(str + 1, regex + 1));
	if (regex[0] == '*')
	{
		len = ft_strlen(str);
		ret = 0;
		i = 0;
		while (i < len + 1)
		{
			ret += nmatch(str + i, regex + 1);
			i++;
		}
		return (ret);
	}
	return (0);
}
