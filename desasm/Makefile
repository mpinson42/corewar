
# Macros
## Options generales
CC		= gcc
RM		= /bin/rm

## Flags
MODE	= prod # Mode prod/dev, pour compiler sans les flags a volonte.
CFLAGS	= -Wall -Werror -Wextra -pedantic
ifeq ($(MODE),dev)
CFLAGS	=
endif
LDFLAGS		+= -I $(DIR_INC) -I $(DIR_LIBFT)/inc
LIBFLAGS 	+= -L $(DIR_LIBFT) -lft

## Dossiers
DIR_SRC		= srcs
DIR_OBJ		= objs
DIR_INC		= include
DIR_LIBFT	= ../libft

## Fichiers
NAME	= deasm

SRC		= $(addprefix $(DIR_SRC)/,$(SRC_F))
INC		= $(addprefix $(DIR_INC)/,$(INC_F))
OBJ		= $(subst .c,.o,$(subst $(DIR_SRC), $(DIR_OBJ),$(SRC)))

LIBFT	= $(DIR_LIBFT)/libft.a

### Fichiers *.c
SRC_F += main.c

SRC_F += ft_conv_int.c
SRC_F += figth.c
SRC_F += exec.c
SRC_F += lib.c
SRC_F += lib2.c
SRC_F += exec2.c
SRC_F += exec3.c
SRC_F += exec4.c
SRC_F += exec5.c
SRC_F += binary2.c
SRC_F += ft_strdup2.c

### Fichiers *.h (includes)
INC_F	+= vm.h

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
	@$(MSG_MODE) && $(MSG_BUILD) && echo " ./deasm ok!" && $(MSG_DEF)

### Compiler les `.o`
$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c $(INC)
	@$(MSG_MODE) && $(MSG_BUILDING) && printf " " && printf $< && $(MSG_DEF)
	@$(CC) -o $@ -c $< $(CFLAGS) $(LDFLAGS)
	@$(LINE_ERASE)

clean:
	@$(RM) -f $(OBJ)
	@$(MSG_REMOVE) && echo " deasm .o down." && $(MSG_DEF)

fclean: clean
	@$(RM) -rf $(DIR_OBJ)
	@$(RM) -f $(NAME)
	@$(MSG_REMOVE) && echo " deasm binary down." && $(MSG_DEF)

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
