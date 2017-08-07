/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sol <sol@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 11:29:11 by apieropa          #+#    #+#             */
/*   Updated: 2015/02/27 19:34:21 by sol              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strsplit_nbr(char *s, char c)
{
	int i;
	int ret;

	i = 0;
	ret = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != c && s[i] != '\0')
			ret += 1;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (ret);
}

static char	*ft_strsplit_dup(char *s, char c)
{
	char	*ret;
	int		len;

	len = 0;
	while (s[len] != c && s[len] != '\0')
		len++;
	ret = ft_strnew(len);
	return (ft_strncpy(ret, s, len));
}

char		**ft_strsplit(const char *s, char c)
{
	char	**ret;
	int		size;
	int		i;
	int		pos;

	size = ft_strsplit_nbr((char*)s, c);
	if ((ret = (char **)malloc(sizeof(char*) * (size + 1))) == NULL)
		return (NULL);
	i = 0;
	pos = 0;
	while (s[pos] != '\0')
	{
		while (s[pos] == c && s[pos] != '\0')
			pos++;
		if (s[pos] == '\0')
			break ;
		ret[i] = ft_strsplit_dup((char*)s + pos, c);
		i++;
		while (s[pos] != c && s[pos] != '\0')
			pos++;
	}
	ret[size] = NULL;
	return (ret);
}
