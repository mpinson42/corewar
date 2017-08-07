/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 16:16:15 by mpinson           #+#    #+#             */
/*   Updated: 2017/07/23 16:16:18 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <termcap.h>
# include <fcntl.h>

typedef	struct		s_champ
{
	int				ici;
	int				nb_joueur;
	int				nb_pross;
	int				last_live;
	int				cycle;
	int				ok;
	int				live;
	int				pross_live;
	int				carry;
	int				pc;
	int				reg[17];
	char			*name;
	char			*vrai_name;
	char			*commante;
	int				leng;
	unsigned char	code[1024];
}					t_champ;

typedef	struct		s_vm
{
	int				visu;
	int				dump;
	int				nb_dump;
	int				nb_joueur;
	int				cycle;
	int				cycle_to_die;
	int				cycle_delta;
	t_champ			champ[4];
	t_champ			*pross;
	int				nb_prosse;
	int				nb_prosses_live;
	char			*joueur[4];
	unsigned char	map[4 * 1024];
	int				map_pc[4 * 1024];
	int				map_color[4 * 1024];
	int				verif;
}					t_vm;

void				ft_affiche_map(t_vm *vm);
int					ft_conv_int(unsigned char *str);
int					ft_chr_leng(char *str);
void				ft_go_figth(t_vm *vm);
int					ft_cher_leng_file(char *str);
void				ft_and6(t_champ *c, t_vm *vm, int fd, unsigned int *oct);
void				ft_live(t_champ *c, t_vm *vm, int fd);
void				ft_zjmp(t_champ *c, t_vm *vm, int fd);
void				ft_fork(t_champ *c, t_vm *vm, int fd);
void				ft_lfork(t_champ *c, t_vm *vm, int fd);
void				ft_sti(t_champ *c, t_vm *vm, int fd);
void				ft_and(t_champ *c, t_vm *vm, int fd);
void				ft_or(t_champ *c, t_vm *vm, int fd);
void				ft_xor(t_champ *c, t_vm *vm, int fd);
void				ft_sub(t_champ *c, t_vm *vm, int fd);
void				ft_add(t_champ *c, t_vm *vm, int fd);
void				ft_aff(t_champ *c, t_vm *vm, int fd);
void				ft_ld(t_champ *c, t_vm *vm, int fd);
void				ft_st(t_champ *c, t_vm *vm, int fd);
void				ft_lld(t_champ *c, t_vm *vm, int fd);
void				ft_ldi(t_champ *c, t_vm *vm, int fd);
void				ft_lldi(t_champ *c, t_vm *vm, int fd);
void				ft_conv2(unsigned int nb, unsigned char (*str)[4]);
char				*ft_strdup2(unsigned char *src);
int					unsigned_atoi_base(unsigned char *str, int base);
unsigned int		unsigned_strlen(unsigned char *s);
unsigned char		*unsigned_strjoin(unsigned char *s1, unsigned char *s2);
unsigned char		*unsigned_strsub(unsigned char *s,
	unsigned int start, unsigned int len);
unsigned char		*unsigned_itoa_base2(unsigned int n, int base);
unsigned char		*unsigned_strdup(unsigned char *src);
void				*ft_memcpy2(void *s1, void *s2, size_t n);

#endif
