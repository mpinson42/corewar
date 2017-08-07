/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen_base_chrs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sol <sol@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 19:46:09 by apieropa          #+#    #+#             */
/*   Updated: 2015/03/05 16:24:45 by sol              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_nbrlen_base_chrs(long int nb, char *base)
{
	return (ft_nbrlen_base(nb, ft_strlen(base)));
}
