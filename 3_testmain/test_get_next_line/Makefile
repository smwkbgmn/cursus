NAME_MAN	= gnl_man.out
NAME_BNS	= gnl_bns.out

CC			= cc
ifdef BUF
	FLAG		= -Wall -Wextra -Werror -D BUFFER_SIZE=$(BUF)
else
	FLAG		= -Wall -Wextra -Werror
endif

DIR_SRC		= ~/dev/ecole/2-for_mine/get_next_line
 
SRC_MAN		= \
$(DIR_SRC)/get_next_line.c \
$(DIR_SRC)/get_next_line_utils.c

SRC_BNS		= \
$(DIR_SRC)/get_next_line_bonus.c \
$(DIR_SRC)/get_next_line_utils_bonus.c

OBJ_MAN		= $(SRC_MAN:.c=.o)
OBJ_BNS		= $(SRC_BNS:.c=.o)


all			: $(NAME_MAN)

bonus		: $(NAME_BNS)

$(NAME_MAN)	: $(OBJ_MAN)
			@$(CC) $(FLAG) main.c $(OBJ_MAN) -o $(NAME_MAN)

$(NAME_BNS)	: $(OBJ_BNS)
			@$(CC) $(FLAG) main.c $(OBJ_BNS) -o $(NAME_BNS)

%.o			: %.c
			@$(CC) $(FLAG) -c $< -o $@

clean		:
			@$(RM) $(OBJ_MAN) $(OBJ_BNS)
	
fclean		: 
			@make clean
			@$(RM) $(NAME_MAN) $(NAME_BNS)

re			:
			@make fclean
			@make all

.PHONY		: clean fclean re bonus

################ FOR TEST ###############

man			: $(NAME_MAN)
			@./$(NAME_MAN)
			@rm $(NAME_MAN)

bns			: $(NAME_BNS)
			@./$(NAME_BNS)
			@rm $(NAME_BNS)
