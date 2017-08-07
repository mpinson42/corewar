/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sol <sol@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/05 15:14:16 by apieropa          #+#    #+#             */
/*   Updated: 2015/03/01 15:04:32 by sol              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstadd_end(t_list **alst, t_list *new)
{
	t_list		*clst;

	if (*alst == NULL)
	{
		*alst = new;
		return ;
	}
	clst = *alst;
	while (clst->next != NULL)
		clst = clst->next;
	clst->next = new;
}
