
# Macros
## Options generales
CC		= gcc
RM		= /bin/rm

## Flags
MODE	= prod # Mode prod/dev, pour compiler sans les flags a volonte.
CFLAGS	= -Wall -Werror -Wextra -pedantic
ifeq ($(MODE),dev)
CFLAGS	= -g
endif
LDFLAGS		+= -I $(DIR_INC) -I $(DIR_LIBFT)/inc
LIBFLAGS 	+= -L $(DIR_LIBFT) -lft

## Dossiers
DIR_SRC		= srcs
DIR_OBJ		= objs
DIR_INC		= includes
DIR_LIBFT	= ../libft

## Fichiers
NAME	= corewar

SRC		= $(addprefix $(DIR_SRC)/,$(SRC_F))
INC		= $(addprefix $(DIR_INC)/,$(INC_F))
OBJ		= $(subst .c,.o,$(subst $(DIR_SRC), $(DIR_OBJ),$(SRC)))

LIBFT	= $(DIR_LIBFT)/libft.a

### Fichiers *.c
SRC_F	 += main.c

SRC_F	 += init.c
SRC_F	 += init_2.c
SRC_F	 += op_0.c
SRC_F	 += op_1.c
SRC_F	 += op_2.c
SRC_F	 += op_3.c
SRC_F	 += print.c
SRC_F	 += print_champ.c
SRC_F	 += print_mem_hexa.c
SRC_F	 += errors.c
SRC_F	 += endian_fts.c
SRC_F	 += mem_ops.c
SRC_F	 += fts.c
SRC_F	 += end.c
SRC_F	 += checks.c
SRC_F	 += op_args.c

### Fichiers *.h (includes)
INC_F	+= corewar.h

## Messages d'affichage, pour la frime
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

# Regles
## Regles classiques
all: $(NAME)

### Compiler `./asm`
$(NAME): $(DIR_OBJ) $(OBJ) $(LIBFT)
	@$(CC) -o $@ $(OBJ) $(LIBFLAGS)
	@$(MSG_MODE) && $(MSG_BUILD) && echo " ./corewar ok!" && $(MSG_DEF)

### Compiler les `.o`
$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c $(INC)
	@$(MSG_MODE) && $(MSG_BUILDING) && printf " " && printf $< && $(MSG_DEF)
	@$(CC) -o $@ -c $< $(CFLAGS) $(LDFLAGS)
	@$(LINE_ERASE)

clean:
	@$(RM) -f $(OBJ)
	@$(MSG_REMOVE) && echo " corewar .o down." && $(MSG_DEF)

fclean: clean
	@$(RM) -rf $(DIR_OBJ)
	@$(RM) -f $(NAME)
	@$(MSG_REMOVE) && echo " corewar binary down." && $(MSG_DEF)

gclean: fclean
	@make fclean -C $(DIR_LIBFT)

re: fclean all

### Dossier `obj`: s'assurer qu'il existe.
$(DIR_OBJ):
	@mkdir $@

### Libft: s'assurer qu'elle est compile.
$(LIBFT):
	make -C $(DIR_LIBFT)

## Regles supplementaires
### Compiler sans les flags, pour qd ils sont trop chiants
dev:
	@make re MODE=dev

### Compiler avec les flags
prod:
	@make re MODE=prod

## Regles qui doivent tout le temps s'executer
.PHONY: all clean fclean re dev prod

## Regles pour debug le Makefile
test:
	echo $(OBJ)
