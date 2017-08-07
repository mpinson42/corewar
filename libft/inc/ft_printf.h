/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 15:07:45 by apieropa          #+#    #+#             */
/*   Updated: 2017/08/06 04:54:33 by pveniat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <wchar.h>
# include "libft.h"
# include "ft_printf_types.h"

# define FT_PRINTF_PADCHR 	arg->zero_padding ? '0' : ' '

int			ft_printf(const char *format, ...);
int			ft_printf_fd(int fd, const char *format, ...);

char		*ft_printf_parse_flags(char **format, t_ptfa *arg);
char		*ft_printf_parse_width(char **format, va_list *list, t_ptfa *arg);
char		*ft_printf_parse_precision(char **format, va_list *list,
		t_ptfa *arg);
char		*ft_printf_parse_modifier(char **format, t_ptfa *arg);

t_ptfh		ft_printf_get_handler(char c);

ssize_t		ft_printf_handle_binary(char **format, va_list *args, t_ptfa *arg);
ssize_t		ft_printf_handle_char(char **format, va_list *args, t_ptfa *arg);
ssize_t		ft_printf_handle_escape(char **format, va_list *args, t_ptfa *arg);
ssize_t		ft_printf_handle_hex(char **format, va_list *args, t_ptfa *arg);
ssize_t		ft_printf_handle_int(char **format, va_list *args, t_ptfa *arg);
ssize_t		ft_printf_handle_long(char **format, va_list *args, t_ptfa *arg);
ssize_t		ft_printf_handle_null(char **format, va_list *args, t_ptfa *arg);
ssize_t		ft_printf_handle_octal(char **format, va_list *args, t_ptfa *arg);
ssize_t		ft_printf_handle_ptr(char **format, va_list *args, t_ptfa *arg);
ssize_t		ft_printf_handle_str(char **format, va_list *args, t_ptfa *arg);
ssize_t		ft_printf_handle_uint(char **format, va_list *args, t_ptfa *arg);
ssize_t		ft_printf_handle_wchar(char **format, va_list *args, t_ptfa *arg);
ssize_t		ft_printf_handle_wstr(char **format, va_list *args, t_ptfa *arg);

ssize_t		ft_printf_handle_signed(intmax_t nbr, t_ptfa *arg, char *b,
		char *p);
ssize_t		ft_printf_handle_unsigned(uintmax_t nbr, t_ptfa *arg, char *b,
		char *p);

intmax_t	ft_printf_apply_modifier_int(va_list *args, t_ptfa *arg);
uintmax_t	ft_printf_apply_modifier_uint(va_list *args, t_ptfa *arg);

uint		ft_printf_nbrlen(intmax_t nbr, char *base);
uint		ft_printf_nbrlen_unsigned(uintmax_t nbr, char *base);
uint		ft_printf_full_nbrlen(intmax_t nbr,
										t_ptfa *arg, char *base, char *prefix);
uint		ft_printf_full_nbrlen_unsigned(uintmax_t nbr,
										t_ptfa *arg, char *base, char *prefix);

void		ft_printf_print_padding(int width, char padchar, int fd);
void		ft_printf_putnbr_base(intmax_t nb, char *base, int fd);
void		ft_printf_putnbr_base_unsigned(uintmax_t nb, char *base, int fd);

int			ft_printf_exec_arg(const char *format,
										va_list *args, size_t tot_len, int fd);
int			ft_printf_core(const char *format,
										va_list *args, size_t tot_len, int fd);

#endif
