/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/04 10:37:26 by apieropa          #+#    #+#             */
/*   Updated: 2015/03/27 20:11:53 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This getnextline is multi-fd
** .
** getnextline calls:
**   - st_allocline to malloc line
**      There is a mechanism around memory allocation: 1rst time st_allocline
**      has to give memory (Macro GNL_INITialisation), and other times
**      (GL_EXTension).
**   - st_gnl_get and st_gnl_free to use the chain list of t_gnl
**      The elements of the list contains static a buffer + indicators for
**      each file descriptors. It allows you to use multiple fd at the time.
**   - st_readloop to read and fill line
**      This function is intended to order getnextline to call it back several
**      times. The principle is to do very simple tasks on very simple
**      conditions, each call.
**      The most important element is the return values:
**       - 'r' to relaunch
**       - 'l' for end of line
**       - 'd' for job done (EOF)
**       - 'e' for error (of read(2))
*/

#include "libft.h"
#include "get_next_line.h"

static t_iny	st_allocline(char **line, int size)
{
	char	*nline;

	if (size == GNL_INIT)
		return ((*line = ft_strnew(GNL_INIT)) == NULL ? RET_FAIL : RET_OK);
	if ((nline = ft_strnew(size)) == NULL)
		return (RET_FAIL);
	ft_strcpy(nline, *line);
	ft_strdel(line);
	*line = nline;
	return (RET_OK);
}

static t_gnl	*st_sgnl_get(t_gnl **sgnl, int fd)
{
	t_gnl	*cgnl;

	cgnl = *sgnl;
	while (cgnl != NULL && cgnl->fd != fd)
		cgnl = cgnl->n;
	if (cgnl != NULL)
		return (cgnl);
	if (cgnl == NULL && (cgnl = (t_gnl *)malloc(sizeof(t_gnl))) == NULL)
		return (NULL);
	ft_memset(cgnl->buff, '\0', BUFF_SIZE + 1);
	cgnl->fd = fd;
	cgnl->beg = 0;
	cgnl->end = 0;
	cgnl->n = *sgnl;
	return ((*sgnl = cgnl));
}

static void		st_gnl_free(t_gnl **sgnl, int fd)
{
	t_gnl	*dgnl;
	t_gnl	*cgnl;

	if ((*sgnl)->fd == fd)
	{
		dgnl = *sgnl;
		*sgnl = (*sgnl)->n;
	}
	else
	{
		cgnl = *sgnl;
		while (cgnl->n->fd != fd)
			cgnl = cgnl->n;
		dgnl = cgnl->n;
		cgnl->n = cgnl->n->n;
	}
	dgnl->fd = 0;
	ft_memset(dgnl->buff, '\0', BUFF_SIZE + 1);
	dgnl->beg = 0;
	dgnl->end = 0;
	dgnl->n = NULL;
	free(dgnl);
}

static char		st_readloop(t_gnl *gnl, char **line)
{
	int			ret;
	char		*posn;
	char		*buff;

	if (gnl->beg >= gnl->end)
	{
		ft_memset(gnl->buff, '\0', BUFF_SIZE);
		ret = read(gnl->fd, gnl->buff, BUFF_SIZE);
		gnl->beg = 0;
		gnl->end = ret;
		if (ret == 0)
			return ('d');
		return (ret == -1 ? 'e' : 'r');
	}
	buff = gnl->buff + gnl->beg;
	if ((posn = ft_strchr(buff, '\n')) != NULL)
	{
		ft_strncat(*line, buff, posn - buff);
		gnl->beg = (int)(posn - gnl->buff) + 1;
		return ('l');
	}
	ft_strcat(*line, gnl->buff + gnl->beg);
	gnl->beg = BUFF_SIZE;
	return ('r');
}

int				get_next_line(const int fd, char **line)
{
	static t_gnl	*sgnl = NULL;
	t_gnl			*cgnl;
	int				i;
	int				ret;

	if ((cgnl = st_sgnl_get(&sgnl, fd)) == NULL)
		return (-1);
	if (st_allocline(line, GNL_INIT) == RET_FAIL)
		return (-1);
	i = GNL_INIT;
	while ((ret = st_readloop(cgnl, line)) == 'r')
	{
		i += BUFF_SIZE;
		if (i == GNL_INIT + BUFF_SIZE &&
			st_allocline(line, GNL_INIT + GNL_EXT) == RET_FAIL)
			return (-1);
		else if (i % GNL_EXT == 0 &&
			st_allocline(line, i + GNL_EXT) == RET_FAIL)
			return (-1);
	}
	if (ret == 'd')
		st_gnl_free(&sgnl, fd);
	if (ret == 'e')
		return (-1);
	return (ret == 'l' ? 1 : 0);
}
