/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sol <sol@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 19:05:09 by apieropa          #+#    #+#             */
/*   Updated: 2014/12/08 00:04:58 by sol              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(const char *s)
{
	int		i_b;
	int		i_e;
	char	*nstr;

	i_b = 0;
	while (s[i_b] == ' ' || s[i_b] == '\n' || s[i_b] == '\t')
		i_b++;
	i_e = ft_strlen((char *)s) - 1;
	while (s[i_e] == ' ' || s[i_e] == '\n' || s[i_e] == '\t')
		i_e--;
	if (i_e < 0)
		return ((nstr = ft_strnew(0)) == NULL ? NULL : nstr);
	return ((nstr = ft_strsub(s, i_b, i_e - i_b + 1)) == NULL ? NULL : nstr);
}
