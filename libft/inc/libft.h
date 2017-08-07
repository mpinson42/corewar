/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 17:34:16 by apieropa          #+#    #+#             */
/*   Updated: 2017/08/06 04:53:29 by pveniat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Version 3.2.0
*/

#ifndef LIBFT_H
# define LIBFT_H

/*
** Includes <System>
*/
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>

/*
** Includes "User"
*/
# include "libft_structs.h"

/*
** MACROS
*/
# ifndef TRUE
#  define TRUE		1
# endif
# ifndef FALSE
#  define FALSE		0
# endif

# define RET_OK		0
# define RET_FAIL	-1

# define ABS(a)		(a < 0 ? -a : a)
# define MIN(a, b)	(a <= b ? a : b)
# define MAX(a, b)	(a >= b ? a : b)

/*
** Typedefs;
*/
typedef char	t_bool;
typedef char	t_iny;
typedef char	t_rep;

/*
** Functions
*/
int				ft_atoi(const char *str);
long int		ft_atol(const char *str);
void			ft_bzero(void *s, size_t n);
char			*ft_ctoa(char c);
void			ft_dump_str(char *str, int n);

int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
t_bool			ft_isnbr(const char *s);
int				ft_isprint(int c);

char			*ft_itoa(int n);

void			ft_lstadd_end(t_list **alst, t_list *new);
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdump(t_list *alst, t_iny mode);
t_list			*ft_lstelem_n(t_list *alst, int index);
void			ft_lstiter(t_list *alst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *alst, t_list *(*f)(t_list *elem));
t_list			*ft_lstnew(const void *content, size_t content_size);
int				ft_lstsize(t_list *alst);

void			*ft_memalloc(size_t size);
void			*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *s1, const void *s2, size_t n);
void			ft_memdel(void **ap);
void			*ft_memmove(void *s1, const void *s2, size_t n);
void			*ft_memset(void *b, int c, size_t len);

int				ft_nbrchrs(const char *str, char *chrs);
int				ft_nbrlen(int nb);
int				ft_nbrlen_base(int nb, int base);
int				ft_nbrlen_base_chrs(long int nb, char *base);
size_t			ft_nstrlen(const char *str, size_t maxlen);
long int		ft_power(int n, int power);

void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl(const char *s);
void			ft_putendl_fd(const char *s, int fd);
void			ft_putnbr(int nb);
void			ft_putnbr_base(int nb, int base);
void			ft_putnbr_base_chrs(int nb, char *base);
void			ft_putnbr_fd(int nb, int fd);
void			ft_putstr(const char *str);
void			ft_putstr_fd(const char *str, int fd);
void			ft_putnwstr(const wchar_t *str, size_t len);
void			ft_putnwstr_fd(const wchar_t *str, size_t len, int fd);
void			ft_putwchar(wchar_t chr);
void			ft_putwchar_fd(wchar_t chr, int fd);

char			*ft_strcat(char *s1, const char *s2);
char			*ft_strchr(const char *s, int c);
void			ft_strclr(char *s);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strcpy(char *s1, const char *s2);
char			*ft_strcut(const char *s, int cutstart, int cutend);
void			ft_strdel(char **as);
char			*ft_strdel_chrs(char *str, char *chrs);
char			*ft_strdup(const char *s);
int				ft_strequ(char const *s1, char const *s2);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strjoin(const char *s1, const char *s2);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlen(const char *str);
char			*ft_strmap(const char *s, char (*f)(char));
char			*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char			*ft_strncat(char *s1, const char *s2, size_t n);
char			*ft_strnchr(const char *s, int c, size_t n);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strncpy(char *s1, const char *s2, size_t n);
int				ft_strnequ(const char *s1, const char *s2, size_t n);
char			*ft_strnew(size_t size);
char			*ft_strnstr(const char *s1, const char *s2, size_t n);
char			*ft_strrchr(const char *s, int c);
char			*ft_strrev(char *str);
char			**ft_strsplit(const char *s, char c);
char			**ft_strsplit_chrs(const char *s, char *chrs);
char			**ft_strsplit_with_empty(const char *s, char c);
char			*ft_strstr(const char *s1, const char *s2);
char			*ft_strsub(const char *s, size_t start, size_t len);
char			*ft_strtrim(const char *s);
char			*ft_strtrim_chrs(const char *s, char *chrs);

int				ft_tolower(int c);
int				ft_toupper(int c);

int				get_next_line(const int fd, char **line);
void			here(int num);
int				nmatch(char *str, char *regex);
void			str_array_del(char ***array);
uint			str_array_length(char **array);

int				ft_printf(const char *format, ...);
int				ft_printf_fd(int fd, const char *format, ...);

#endif
