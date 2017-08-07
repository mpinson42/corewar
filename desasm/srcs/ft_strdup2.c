/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 15:22:37 by mpinson           #+#    #+#             */
/*   Updated: 2017/07/21 15:22:46 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

char	*ft_strdup2(unsigned char *src)
{
	char	*str;
	size_t	i;
	size_t	y;

	if (src == NULL)
		return (NULL);
	i = 0;
	y = 0;
	while (src[y])
		y++;
	if (!(str = (char*)malloc(sizeof(char) * y + 1)))
		return (NULL);
	while (i < y)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
