/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sol <sol@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 04:22:07 by apieropa          #+#    #+#             */
/*   Updated: 2015/03/03 19:40:53 by sol              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcut(const char *s, int cutstart, int cutend)
{
	int		len;
	char	*str;
	int		slen;

	slen = ft_strlen(s);
	if (cutstart > slen || cutend > slen || cutstart > cutend)
		return (NULL);
	len = slen + cutend - cutstart;
	if ((str = ft_strnew(len)) == NULL)
		return (NULL);
	ft_strncpy(str, s, cutstart);
	ft_strcpy(str + cutstart, s + cutend);
	return (str);
}
