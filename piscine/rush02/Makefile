CC		= gcc
FLAG	= -Wall -Wextra -Werror -I includes

NAME	= rush-02

SRCS	= $(wildcard srcs/*.c) $(wildcard srcs/ft/*.c)
OBJS	= $(SRCS:.c=.o)

all			: $(NAME)

$(NAME)		: $(OBJS)
			$(CC) $(FLAG) $(OBJS) -o $(NAME)

.c.o		: $(SRCS)
			$(CC) $(FLAG) -c $< -o $(<:.c=.o)

clean		:
			$(RM) $(OBJS)

fclean		: clean
			$(RM) $(NAME)

re			: fclean all