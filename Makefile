
NAME_ASM = asm
NAME_VM  = corewar
NAME_DEASM = deasm

DIR_ASM   = assembleur/project
DIR_VM    = vm
DIR_DEASM = desasm

FULLNAME_ASM 	= $(DIR_ASM)/$(NAME_ASM)
FULLNAME_VM  	= $(DIR_VM)/$(NAME_VM)
FULLNAME_DEASM  = $(DIR_DEASM)/$(NAME_DEASM)

all: $(NAME_VM) $(NAME_ASM) $(NAME_DEASM)

$(NAME_DEASM):
	@make -C $(DIR_DEASM)
	@cp $(FULLNAME_DEASM) .

$(NAME_ASM):
	@make -C $(DIR_ASM)
	@cp $(FULLNAME_ASM) .

$(NAME_VM):
	@make -C $(DIR_VM)
	@cp $(FULLNAME_VM) .

re:
	@make -C $(DIR_ASM) re
	@make -C $(DIR_VM) re
	@make -C $(DIR_DEASM) re
	@cp $(FULLNAME_VM) .
	@cp $(FULLNAME_ASM) .
	@cp $(FULLNAME_DEASM) .

clean:
	@make -C $(DIR_ASM) clean
	@make -C $(DIR_VM) clean
	@make -C $(DIR_DEASM) clean

fclean:
	@make -C $(DIR_ASM) fclean
	@make -C $(DIR_VM) fclean
	@make -C $(DIR_DEASM) fclean
	@rm -rf $(NAME_ASM)
	@rm -rf $(NAME_VM)
	@rm -rf $(NAME_DEASM)

gclean:
	@make -C $(DIR_ASM) gclean
	@make -C $(DIR_VM) gclean

dev:
	@make -C $(DIR_ASM) dev
	@make -C $(DIR_VM) dev
	@make -C $(DIR_DEASM) dev
	@cp $(FULLNAME_VM) .
	@cp $(FULLNAME_ASM) .
	@cp $(FULLNAME_DEASM) .

.PHONY: all re
