/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sol <sol@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 15:57:42 by apieropa          #+#    #+#             */
/*   Updated: 2015/03/02 13:58:37 by sol              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *alst, t_list *(*f)(t_list *elem))
{
	t_list	*ret;
	t_list	*clst;
	t_list	*nlst;

	ret = NULL;
	clst = alst;
	while (clst != NULL)
	{
		if ((nlst = ft_lstnew(clst->content, clst->content_size)) == NULL)
			return (NULL);
		ft_lstadd_end(&ret, (*f)(nlst));
		clst = clst->next;
	}
	return (ret);
}
