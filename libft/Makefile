# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 17:24:29 by apieropa          #+#    #+#              #
#    Updated: 2015/03/28 17:36:13 by apieropa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Macros
## General options
CC		= gcc
RM		= /bin/rm

## Flags
MODE	= prod
CFLAGS	= -Wall -Werror -Wextra -pedantic
ifeq ($(MODE),dev)
CFLAGS	=
endif
LDFLAGS	+= -I $(DIR_INC)

## Directories
DIR_SRC	= src
DIR_OBJ	= obj
DIR_INC	= inc

## Files
NAME	= libft.a

SRC		= $(addprefix $(DIR_SRC)/,$(SRC_F))
INC		= $(addprefix $(DIR_INC)/,$(INC_F))
OBJ		= $(subst .c,.o,$(subst $(DIR_SRC), $(DIR_OBJ),$(SRC)))

### Libft files
SRC_F	+= libft/ft_atoi.c
SRC_F	+= libft/ft_atol.c
SRC_F	+= libft/ft_bzero.c
SRC_F	+= libft/ft_ctoa.c
SRC_F	+= libft/ft_dump_str.c

SRC_F	+= libft/ft_isalnum.c
SRC_F	+= libft/ft_isalpha.c
SRC_F	+= libft/ft_isascii.c
SRC_F	+= libft/ft_isdigit.c
SRC_F	+= libft/ft_isnbr.c
SRC_F	+= libft/ft_isprint.c

SRC_F	+= libft/ft_itoa.c

SRC_F	+= libft/ft_lstadd.c
SRC_F	+= libft/ft_lstadd_end.c
SRC_F	+= libft/ft_lstdel.c
SRC_F	+= libft/ft_lstdelone.c
SRC_F	+= libft/ft_lstdump.c
SRC_F	+= libft/ft_lstelem_n.c
SRC_F	+= libft/ft_lstiter.c
SRC_F	+= libft/ft_lstmap.c
SRC_F	+= libft/ft_lstnew.c
SRC_F	+= libft/ft_lstsize.c

SRC_F	+= libft/ft_memalloc.c
SRC_F	+= libft/ft_memccpy.c
SRC_F	+= libft/ft_memchr.c
SRC_F	+= libft/ft_memcmp.c
SRC_F	+= libft/ft_memcpy.c
SRC_F	+= libft/ft_memdel.c
SRC_F	+= libft/ft_memmove.c
SRC_F	+= libft/ft_memset.c

SRC_F	+= libft/ft_nbrchrs.c
SRC_F	+= libft/ft_nbrlen.c
SRC_F	+= libft/ft_nbrlen_base.c
SRC_F	+= libft/ft_nbrlen_base_chrs.c
SRC_F	+= libft/ft_nstrlen.c

SRC_F	+= libft/ft_power.c

SRC_F	+= libft/ft_putchar.c
SRC_F	+= libft/ft_putchar_fd.c
SRC_F	+= libft/ft_putendl.c
SRC_F	+= libft/ft_putendl_fd.c
SRC_F	+= libft/ft_putnbr.c
SRC_F	+= libft/ft_putnbr_base.c
SRC_F	+= libft/ft_putnbr_base_chrs.c
SRC_F	+= libft/ft_putnbr_fd.c
SRC_F	+= libft/ft_putnwstr.c
SRC_F	+= libft/ft_putnwstr_fd.c
SRC_F	+= libft/ft_putstr.c
SRC_F	+= libft/ft_putstr_fd.c
SRC_F	+= libft/ft_putwchar.c
SRC_F	+= libft/ft_putwchar_fd.c

SRC_F	+= libft/ft_strcat.c
SRC_F	+= libft/ft_strchr.c
SRC_F	+= libft/ft_strclr.c
SRC_F	+= libft/ft_strcmp.c
SRC_F	+= libft/ft_strcpy.c
SRC_F	+= libft/ft_strcut.c
SRC_F	+= libft/ft_strdel.c
SRC_F	+= libft/ft_strdel_chrs.c
SRC_F	+= libft/ft_strdup.c
SRC_F	+= libft/ft_strequ.c
SRC_F	+= libft/ft_striter.c
SRC_F	+= libft/ft_striteri.c
SRC_F	+= libft/ft_strjoin.c
SRC_F	+= libft/ft_strlcat.c
SRC_F	+= libft/ft_strlen.c
SRC_F	+= libft/ft_strmap.c
SRC_F	+= libft/ft_strmapi.c
SRC_F	+= libft/ft_strncat.c
SRC_F	+= libft/ft_strnchr.c
SRC_F	+= libft/ft_strncmp.c
SRC_F	+= libft/ft_strncpy.c
SRC_F	+= libft/ft_strnequ.c
SRC_F	+= libft/ft_strnew.c
SRC_F	+= libft/ft_strnstr.c
SRC_F	+= libft/ft_strrchr.c
SRC_F	+= libft/ft_strrev.c
SRC_F	+= libft/ft_strsplit.c
SRC_F	+= libft/ft_strsplit_chrs.c
SRC_F	+= libft/ft_strsplit_with_empty.c
SRC_F	+= libft/ft_strstr.c
SRC_F	+= libft/ft_strsub.c
SRC_F	+= libft/ft_strtrim.c
SRC_F	+= libft/ft_strtrim_chrs.c

SRC_F	+= libft/ft_tolower.c
SRC_F	+= libft/ft_toupper.c

SRC_F	+= libft/get_next_line.c
SRC_F	+= libft/here.c
SRC_F	+= libft/nmatch.c
SRC_F	+= libft/str_array_del.c
SRC_F	+= libft/str_array_length.c

### Prinft files
SRC_F	+= printf/ft_printf.c
SRC_F	+= printf/ft_printf_parse.c
SRC_F	+= printf/ft_printf_get_handler.c

SRC_F	+= printf/handlers/handle_binary.c
SRC_F	+= printf/handlers/handle_char.c
SRC_F	+= printf/handlers/handle_escape.c
SRC_F	+= printf/handlers/handle_hex.c
SRC_F	+= printf/handlers/handle_int.c
SRC_F	+= printf/handlers/handle_long.c
SRC_F	+= printf/handlers/handle_null.c
SRC_F	+= printf/handlers/handle_numbers.c
SRC_F	+= printf/handlers/handle_octal.c
SRC_F	+= printf/handlers/handle_ptr.c
SRC_F	+= printf/handlers/handle_str.c
SRC_F	+= printf/handlers/handle_uint.c
SRC_F	+= printf/handlers/handle_wchar.c
SRC_F	+= printf/handlers/handle_wstr.c

SRC_F	+= printf/utils/ft_printf_apply_modifier.c
SRC_F	+= printf/utils/ft_printf_nbrlen.c
SRC_F	+= printf/utils/ft_printf_print_padding.c
SRC_F	+= printf/utils/ft_printf_putstr_base.c

## Includes
INC_F	+= libft.h
INC_F	+= libft_structs.h
INC_F	+= get_next_line.h
INC_F	+= ft_printf.h
INC_F	+= ft_printf_types.h

## Messages & Colors
CLR_GREEN		= \033[0;32m
CLR_ORANGE		= \033[38;5;208m
CLR_BLUE		= \033[1;34m
CLR_RED			= \033[0;31m
CLR_PINK		= \033[0;35m
CLR_DEFAULT		= \033[0m

MSG_BUILD		= printf "$(CLR_GREEN)[build]"
MSG_BUILDING	= printf "$(CLR_ORANGE)[building]"
MSG_REMOVE		= printf "$(CLR_RED)[remove]"
MSG_DEF			= printf "$(CLR_DEFAULT)"
MSG_MODE		= printf "$(CLR_BLUE)[prod_mode]"
ifeq ($(MODE),dev)
MSG_MODE		= printf "$(CLR_PINK)[dev_mode]"
endif

LINE_ERASE		= printf "\r" && printf "\033[K"

# Rules
## Classic Rules
all: $(NAME)

$(NAME): $(DIR_OBJ) $(OBJ)
	@ar -rcs $@ $(OBJ)
	@$(MSG_MODE) && $(MSG_BUILD) && echo " Libft ok!" && $(MSG_DEF)

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c $(INC)
	@$(MSG_MODE) && $(MSG_BUILDING) && printf " " && printf $< && $(MSG_DEF)
	@$(CC) -o $@ -c $< $(CFLAGS) $(LDFLAGS)
	@$(LINE_ERASE)

clean:
	@$(RM) -f $(OBJ)
	@$(MSG_REMOVE) && echo " Libft .o down." && $(MSG_DEF)

fclean: clean
	@$(RM) -rf $(DIR_OBJ)
	@$(RM) -f $(NAME)
	@$(MSG_REMOVE) && echo " Libft .a down." && $(MSG_DEF)

re: fclean all

$(DIR_OBJ):
	@mkdir $@
	@mkdir $@/libft
	@mkdir $@/printf
	@mkdir $@/printf/handlers
	@mkdir $@/printf/utils

## Supp Rules
dev:
	@make re MODE=dev

prod:
	@make re MODE=prod

.PHONY: all clean fclean re dev prod

test:
	@echo $(SRC)
