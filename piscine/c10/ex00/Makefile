CC		= gcc
FlAG	= -Wall -Wextra -Werror

NAME 	= ft_display_file

DIR		= srcs
SRCS	= $(DIR)/ft_display_file.c
OBJS	= $(SRCS:.c=.o)

all		: $(NAME)

$(NAME)	: $(OBJS)
		$(CC) $(FLAG) $(OBJS) -o $(NAME)

.c.o	: $(SRCS)
		$(CC) $(FLAG) -c $< -o $(<:.c=.o)

clean	:
		$(RM) $(OBJS)

fclean	: clean
		$(RM) %(NAME)

re		: fclean all