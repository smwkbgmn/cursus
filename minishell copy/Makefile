NAME		= minishell

CC			= cc

FLAG		= -Wall -Wextra -Werror -fsanitize=address \
$(FLAG_HEADER)

FLAG_HEADER	= -I $(DIR_HDR) -I $(DIR_LIB_FT) -I $(DIR_LIB_RL)/include

SRCS		= \
debug.c \
minishell.c \
$(wildcard $(DIR_SRCS)/*.c) \
$(wildcard $(DIR_SRCS)/builtin/*.c) \
$(wildcard $(DIR_SRCS)/execute/*.c) \
$(wildcard $(DIR_SRCS)/init/*.c) \
$(wildcard $(DIR_SRCS)/init/parse/*.c) \
$(wildcard $(DIR_SRCS)/system/*.c)

OBJS		= $(SRCS:.c=.o)

LIB_FT		= $(DIR_LIB_FT)/libft.a
LIB_RL		= -L$(DIR_LIB_RL)/lib -lreadline
LIB_TM		= -lncurses

DIR_HDR		= include 
DIR_SRCS	= source

DIR_LIB_FT	= ../archive/libft
DIR_LIB_RL	= /opt/homebrew/Cellar/readline/8.2.1
# DIR_LIB_RL	= /Users/donghyu2/.brew/Cellar/readline/8.2.1

all			: $(NAME)

$(NAME)		: $(LIB_FT) $(OBJS)
			$(CC) $(FLAG) $(LIB_FT) $(LIB_RL) $(LIB_TM) \
			$(OBJS) -o $@

%.o			: %.c
			$(CC) $(FLAG) -c $< -o $@

$(LIB_FT)	:
			make -C $(DIR_LIB_FT)

clean		:
			$(RM) $(OBJS)
			make -C $(DIR_LIB_FT) clean

fclean		:
			make clean
			$(RM) $(NAME)
			make -C $(DIR_LIB_FT) fclean

re			:
			make fclean
			make all

.PHONY		: all celan fclean re
