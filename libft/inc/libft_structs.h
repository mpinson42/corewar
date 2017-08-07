/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/24 12:08:20 by apieropa          #+#    #+#             */
/*   Updated: 2015/03/27 20:15:02 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_STRUCTS_H
# define LIBFT_STRUCTS_H

/*
** Typedefs;
*/
typedef struct s_list	t_list;

/*
** Structs{};
*/
struct					s_list
{
	void				*content;
	size_t				content_size;
	t_list				*next;
};

#endif
