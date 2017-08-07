/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sol <sol@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 15:57:42 by apieropa          #+#    #+#             */
/*   Updated: 2015/03/02 13:37:44 by sol              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstiter(t_list *alst, void (*f)(t_list *elem))
{
	t_list	*clst;

	clst = alst;
	while (clst != NULL)
	{
		(*f)(clst);
		clst = clst->next;
	}
}
