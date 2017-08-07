/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/04 10:37:47 by apieropa          #+#    #+#             */
/*   Updated: 2014/09/28 17:51:52 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>

# include "libft.h"

/*
** BUFF_SIZE is the number or bits read(2) will read.
** GNL_INIT is the amout of memory that a line should take without extension.
** GNL_EXT is the amout of memory extention for a line.
*/

# define BUFF_SIZE	128
# define GNL_INIT	(2 * BUFF_SIZE)
# define GNL_EXT	(1 * BUFF_SIZE)

typedef struct s_gnl	t_gnl;

struct					s_gnl
{
	int					fd;
	char				buff[BUFF_SIZE + 1];
	int					beg;
	int					end;
	t_gnl				*n;
};

int						get_next_line(const int fd, char **line);

#endif
