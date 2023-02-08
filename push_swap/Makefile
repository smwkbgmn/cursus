NAME		= push_swap

CC			= cc
FLAG		= -Wall -Wextra -Werror -I $(DIR_LIBFT)/include

DIR_LIBFT	= ../1-archive/libft

SRCS		= $(wildcard *.c)
OBJS		= $(SRCS:.c=.o)

LIBFT		= $(DIR_LIBFT)/libft.a

all			: $(NAME)

$(NAME)		: $(OBJS)
			$(CC) $(FLAG) $(OBJS) -o $@

%.o			: %.c $(LIBFT)
			$(CC) $(FLAG) $(LIBFT) -c $< -o $@

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