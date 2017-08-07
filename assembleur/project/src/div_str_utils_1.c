/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   div_str_utils_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 19:59:47 by apieropa          #+#    #+#             */
/*   Updated: 2017/07/27 19:59:49 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_bool	does_str_starts_with(char *str, char *begin_str)
{
	if (ft_strncmp(str, begin_str, ft_strlen(begin_str)) != 0)
		return (FALSE);
	return (TRUE);
}

t_bool	does_str_ends_with(char *str, char *end_str)
{
	uint	len;

	len = ft_strlen(str);
	if (len <= ft_strlen(end_str))
		return (FALSE);
	if (ft_strcmp(str + len - 2, end_str) != 0)
		return (FALSE);
	return (TRUE);
}

t_bool	is_string_value_well_formatted(char *str)
{
	uint	i;
	uint	len;

	len = ft_strlen(str);
	if (len < 2)
		return (FALSE);
	if (str[0] != '"' || str[len - 1] != '"')
		return (FALSE);
	i = 0;
	while (str[i] != '\0')
	{
		if (i != len - 2 && str[i + 1] == '"' && str[i] != '\\')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

t_bool	is_str_only_made_of(char *str, char *chrs, uint limit)
{
	uint	i;
	uint	j;
	uint	len;

	len = ft_strlen(str);
	if (limit != 0)
		len = limit;
	i = 0;
	while (i < len)
	{
		j = 0;
		while (chrs[j] != '\0')
		{
			if (str[i] == chrs[j])
				break ;
			j++;
		}
		if (str[i] != chrs[j])
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void	str_array_map(char **array, void (*f)(char*))
{
	uint	i;

	i = 0;
	while (array[i] != NULL)
	{
		(*f)(array[i]);
		i++;
	}
}
