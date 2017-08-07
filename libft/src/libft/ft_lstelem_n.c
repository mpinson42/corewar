/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstelem_n.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sol <sol@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/05 16:29:53 by apieropa          #+#    #+#             */
/*   Updated: 2015/03/01 15:36:32 by sol              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstelem_n(t_list *alst, int index)
{
	int			i;
	t_list		*clst;
	int			size;

	if (index < 0)
	{
		size = ft_lstsize(alst);
		if (size < -index)
			return (NULL);
		return (ft_lstelem_n(alst, size + index));
	}
	i = 0;
	clst = alst;
	while (i < index && clst != NULL)
	{
		clst = clst->next;
		i++;
	}
	return (clst);
}
