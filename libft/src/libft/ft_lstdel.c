/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sol <sol@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 10:51:19 by apieropa          #+#    #+#             */
/*   Updated: 2015/03/01 15:05:04 by sol              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*clst;
	t_list		*nlst;

	clst = *alst;
	while (clst != NULL)
	{
		nlst = clst->next;
		ft_lstdelone(&clst, del);
		clst = nlst;
	}
	*alst = NULL;
}
