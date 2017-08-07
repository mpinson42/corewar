/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_types.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 15:06:12 by apieropa          #+#    #+#             */
/*   Updated: 2016/10/31 15:06:15 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_TYPES_H
# define FT_PRINTF_TYPES_H

# include <sys/types.h>
# include <stdarg.h>

typedef struct s_ptfa	t_ptfa;

struct		s_ptfa
{
	uint	alternate_form : 1;
	uint	zero_padding : 1;
	uint	right_pad : 1;
	uint	force_sign : 1;
	uint	force_blank : 1;
	uint	has_minwidth : 1;
	uint	has_precision : 1;
	char	conversion;
	uint	minwidth;
	uint	precision;
	int		fd;
	enum {
		none,
		hh,
		h,
		l,
		ll,
		j,
		z
	}		modifier;
};

typedef ssize_t	(*t_ptfh)(char**, va_list*, t_ptfa*);

#endif
