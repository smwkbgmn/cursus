NAME_MAN	= gnl_man.out
NAME_BNS	= gnl_bns.out

CC			= cc
ifdef BUF
	FLAG		= -Wall -Wextra -Werror -D BUFFER_SIZE=$(BUF)
else
	FLAG		= -Wall -Wextra -Werror
endif
 
SRC_MAN		= \
get_next_line.c \
get_next_line_utils.c

SRC_BNS		= \
get_next_line_bonus.c \
get_next_line_utils_bonus.c

OBJ_MAN		= $(SRC_MAN:.c=.o)
OBJ_BNS		= $(SRC_BNS:.c=.o)

DIR_MAIN	= ../testmain/main_get_next_line

all			: $(NAME_MAN)

bonus		: $(NAME_BNS)

$(NAME_MAN)	: $(OBJ_MAN)
			$(CC) $(FLAG) $(DIR_MAIN)/main_man.c $(OBJ_MAN) -o $(NAME_MAN)

$(NAME_BNS)	: $(OBJ_BNS)
			@$(CC) $(FLAG) $(DIR_MAIN)/main_bns.c $(OBJ_BNS) -o $(NAME_BNS)

%.o			: %.c
			@$(CC) $(FLAG) -c $< -o $@

clean		:
			$(RM) $(OBJ_MAN) $(OBJ_BNS)
	
fclean		: 
			make clean
			$(RM) $(NAME_MAN) $(NAME_BNS)

re			:
			make fclean
			make all

.PHONY		: all clean fclean re bonus

################ FOR TEST ###############

man			: $(NAME_MAN) 
			@./gnl_man.out
			@rm gnl_man.out

bns			: $(NAME_BNS) 
			@./gnl_man.out
			@rm gnl_man.out

.PHONY		: man bns
