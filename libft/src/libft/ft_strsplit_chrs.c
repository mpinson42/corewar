/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_chrs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sol <sol@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 11:29:11 by apieropa          #+#    #+#             */
/*   Updated: 2015/02/27 19:58:01 by sol              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strsplit_chrs_nbr(char *s, char *chrs)
{
	int i;
	int ret;

	i = 0;
	ret = 0;
	while (s[i] != '\0')
	{
		while (ft_strchr(chrs, s[i]) != NULL && s[i] != '\0')
			i++;
		if (ft_strchr(chrs, s[i]) == NULL && s[i] != '\0')
			ret += 1;
		while (ft_strchr(chrs, s[i]) == NULL && s[i] != '\0')
			i++;
	}
	return (ret);
}

static char	*ft_strsplit_chrs_dup(char *s, char *chrs)
{
	char	*ret;
	int		len;

	len = 0;
	while (ft_strchr(chrs, s[len]) == NULL && s[len] != '\0')
		len++;
	ret = ft_strnew(len);
	return (ft_strncpy(ret, s, len));
}

char		**ft_strsplit_chrs(const char *s, char *chrs)
{
	char	**ret;
	int		size;
	int		i;
	int		pos;

	size = ft_strsplit_chrs_nbr((char*)s, chrs);
	if ((ret = (char **)malloc(sizeof(char*) * (size + 1))) == NULL)
		return (NULL);
	i = 0;
	pos = 0;
	while (s[pos] != '\0')
	{
		while (ft_strchr(chrs, s[pos]) != NULL && s[pos] != '\0')
			pos++;
		if (s[pos] == '\0')
			break ;
		ret[i] = ft_strsplit_chrs_dup((char*)s + pos, chrs);
		i++;
		while (ft_strchr(chrs, s[pos]) == NULL && s[pos] != '\0')
			pos++;
	}
	ret[size] = NULL;
	return (ret);
}
