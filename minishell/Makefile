NAME		= minishell

CC			= cc

FLAG		= -Wall -Wextra -Werror -fsanitize=address \
$(FLAG_HEADER)

FLAG_HEADER	= -I $(DIR_MAIN) -I $(DIR_LIB_FT) -I $(DIR_LIB_RL)/include

SRCS		= \
debug.c \
minishell.c \
$(wildcard $(DIR_SRCS)/*.c) \
$(wildcard $(DIR_SRCS)/execute/*.c) \
$(wildcard $(DIR_SRCS)/parse/*.c) \
$(wildcard $(DIR_SRCS)/system/*.c)

OBJS		= $(SRCS:.c=.o)

LIB_FT		= $(DIR_LIB_FT)/libft.a
LIB_RL		= -lreadline

DIR_MAIN	= .
DIR_SRCS	= source
DIR_LIB_FT	= ../archive/libft
DIR_LIB_RL	= /opt/homebrew/Cellar/readline

all			: $(NAME)

$(NAME)		: $(LIB_FT) $(OBJS)
			$(CC) $(FLAG) $(LIB_FT) $(LIB_RL) $(OBJS) -o $@

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
