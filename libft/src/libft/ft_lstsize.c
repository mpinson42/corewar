/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sol <sol@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 15:49:22 by apieropa          #+#    #+#             */
/*   Updated: 2015/03/01 15:09:55 by sol              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_lstsize(t_list *alst)
{
	t_list		*clst;
	size_t		size;

	size = 0;
	clst = alst;
	while (clst != NULL)
	{
		clst = clst->next;
		size++;
	}
	return (size);
}
