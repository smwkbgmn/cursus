NAME		= push_swap

CC			= cc
FLAG		= -Wall -Wextra -Werror -I $(DIR_LIBFT)/include

DIR_LIBFT	= 2-archive/libft

SRCS		= $(wildcard *.c)
OBJS		= $(SRCS:.c=.o)

LIBFT		= $(DIR_LIBFT)/libft.a

all			: $(NAME)

$(NAME)		: $(OBJS)
			$(CC) $(FLAG) $(OBJS) -o $@

%.o			: %.c
			$(CC) $(FLAG) $(LIBFT) -c $< -o $@

clean		:
			$(RM) $(OBJS)

fclean		:
			make clean
			$(RM) $(NAME)

re			:
			make fclean
			make all

.PHONY		: all celan fclean re