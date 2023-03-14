NAME		= push_swap

CC			= cc
FLAG		= -Wall -Wextra -Werror -I $(DIR_LIBFT)/include

DIR_LIBFT	= ../1-archive/libft

SRCS		= $(wildcard *.c)
OBJS		= $(SRCS:.c=.o)

LIBFT		= $(DIR_LIBFT)/libft.a

all			: $(NAME)

$(NAME)		: $(LIBFT) $(OBJS)
			$(CC) $(FLAG) $(LIBFT) $(OBJS) -o $@

%.o			: %.c
			$(CC) $(FLAG) -c $< -o $@

# %.o			: %.c
# 			$(CC) $(FLAG) -c $< -o $@

$(LIBFT)	:
			$(MAKE) -C $(DIR_LIBFT) all

clean		:
			$(RM) $(OBJS)
			$(MAKE) -C $(DIR_LIBFT) clean

fclean		:
			make clean
			$(RM) $(NAME) $(LIBFT)

re			:
			make fclean
			make all

.PHONY		: all celan fclean re

TEST_INPUT	= 2 1 3 6 5 8

test		: $(NAME)
			@./$(NAME) $(TEST_INPUT)
			@$(RM) $(NAME)