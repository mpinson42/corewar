/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 12:22:48 by apieropa          #+#    #+#             */
/*   Updated: 2015/03/27 18:57:43 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Modes:
**  - 's' space:  prints every element with ' ' between
**  - 'l' list:   prints every element with ' -> ' between
**  - 'n' none:   prints every element with nothing between
**  - 'd' debug:  like list plus prefix data with type
*/

#include "libft.h"

static void		ft_lstdump_one(t_iny type, void *data, t_bool prefix)
{
	if (prefix == TRUE)
	{
		ft_putchar(type);
		ft_putchar(':');
	}
	if (type == 'i')
		ft_putnbr(*(int*)data);
	else if (type == 'c')
		ft_putchar(*(char*)data);
	else if (type == 's')
		ft_putstr(*(char**)data);
}

void			ft_lstdump(t_list *alst, t_iny mode)
{
	t_list		*clst;
	char		*between;

	if (mode == 'd' || mode == 'l')
		between = " -> ";
	else if (mode == 's')
		between = " ";
	else if (mode == 'n')
		between = "";
	clst = alst;
	while (clst != NULL)
	{
		if (clst->content_size == sizeof(int))
			ft_lstdump_one('i', clst->content, mode == 'd');
		else if (clst->content_size == sizeof(char))
			ft_lstdump_one('c', clst->content, mode == 'd');
		else if (clst->content_size % sizeof(char*) == 0)
			ft_lstdump_one('s', clst->content, mode == 'd');
		ft_putstr(clst->next != NULL ? between : "");
		clst = clst->next;
	}
	ft_putstr(alst == NULL ? "(null)" : "");
}
