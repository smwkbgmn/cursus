NAME		= minishell

CC			= cc

FLAG		= -Wall -Wextra -Werror \
$(FLAG_HEADER)

FLAG_HEADER	= -I $(DIR_HDR) -I $(DIR_LIBFT)
FLAG_LIBFT	= -L $(DIR_LIBFT) -l ft

SRCS		= \
minishell.c
# $(DIR_SRCS)/$(wildcard *.c)

OBJS		= $(SRCS:.c=.o)

LIBFT		= $(DIR_LIBFT)/libft.a

DIR_HDR		= .
DIR_SRCS	= source
DIR_LIBFT	= ../archive/libft

all			: $(NAME)

$(NAME)		: $(LIBFT) $(OBJS)
			$(CC) $(FLAG) $(FLAG_LIBFT) $(OBJS) -o $@

%.o			: %.c
			$(CC) $(FLAG) -c $< -o $@

$(LIBFT)	:
			make -C $(DIR_LIBFT)

clean		:
			$(RM) $(OBJS)
			make -C $(DIR_LIBFT) clean

fclean		:
			make clean
			$(RM) $(NAME)
			make -C $(DIR_LIBFT) fclean

re			:
			make fclean
			make all
#			make -C $(DIR_LIBFT) re

.PHONY		: all celan fclean re
