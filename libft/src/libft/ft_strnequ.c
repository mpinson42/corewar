/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 16:16:01 by apieropa          #+#    #+#             */
/*   Updated: 2014/09/28 14:34:59 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strnequ(const char *s1, const char *s2, size_t n)
{
	size_t		i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && i < n)
		i++;
	return ((s1[i] == '\0' && s2[i] == '\0') || i == n ? 1 : 0);
}
