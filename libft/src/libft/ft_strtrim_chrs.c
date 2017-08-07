/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_chrs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 19:10:31 by apieropa          #+#    #+#             */
/*   Updated: 2015/03/27 20:07:42 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim_chrs(const char *s, char *chrs)
{
	int		ib;
	int		ie;
	char	*nstr;

	ib = 0;
	while (ft_strchr(chrs, s[ib]) != NULL)
		ib++;
	ie = ft_strlen((char *)s) - 1;
	while (ft_strchr(chrs, s[ie]) != NULL && ie != 0)
		ie--;
	if (ie <= 0)
		return ((nstr = ft_strnew(0)) == NULL ? NULL : nstr);
	return ((nstr = ft_strsub(s, ib, ie - ib + 1)) == NULL ? NULL : nstr);
}
