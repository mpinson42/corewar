
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
DIR_SRC		= src
DIR_OBJ		= obj
DIR_INC		= inc
DIR_LIBFT	= ../../libft

## Fichiers
NAME	= asm

SRC		= $(addprefix $(DIR_SRC)/,$(SRC_F))
INC		= $(addprefix $(DIR_INC)/,$(INC_F))
OBJ		= $(subst .c,.o,$(subst $(DIR_SRC), $(DIR_OBJ),$(SRC)))

LIBFT	= $(DIR_LIBFT)/libft.a

### Fichiers *.c
SRC_F	+= main.c

SRC_F	+= main_get_champion_lines.c
SRC_F	+= main_get_instructions.c
SRC_F	+= main_get_champion_program.c
SRC_F	+= main_check_champion_lines.c
SRC_F	+= main_print_champion_file.c

SRC_F	+= line_parsed_as.c
SRC_F	+= pass_arguments_meta.c
SRC_F	+= pass_arguments_values.c
SRC_F	+= pass_opcode_meta.c
SRC_F	+= pass_addresses.c

SRC_F	+= div_is_arg_a.c
SRC_F	+= div_failures.c
SRC_F	+= div_div.c
SRC_F	+= div_str_utils_1.c
SRC_F	+= div_str_utils_2.c
SRC_F	+= div_op.c

SRC_F	+= line_is_1.c
SRC_F	+= line_is_2.c

### Fichiers *.h (includes)
INC_F	+= corewar.h
INC_F	+= structs.h
INC_F	+= op.h

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
	@$(MSG_MODE) && $(MSG_BUILD) && echo " ./asm ok!" && $(MSG_DEF)

### Compiler les `.o`
$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c $(INC)
	@$(MSG_MODE) && $(MSG_BUILDING) && printf " " && printf $< && $(MSG_DEF)
	@$(CC) -o $@ -c $< $(CFLAGS) $(LDFLAGS)
	@$(LINE_ERASE)

clean:
	@$(RM) -f $(OBJ)
	@$(MSG_REMOVE) && echo " Asm .o down." && $(MSG_DEF)

fclean: clean
	@$(RM) -rf $(DIR_OBJ)
	@$(RM) -f $(NAME)
	@$(MSG_REMOVE) && echo " Asm binary down." && $(MSG_DEF)

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
