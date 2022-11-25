NAME	= libftprintf.a

CC		= cc
FLAG	= -Wall -Wextra -Werror

SRCS	= $(wildcard *.c)
OBJS	= $(SRCS:.c=.o)
LIBFT	= libft.a

all		: $(NAME)

$(NAME)	: $(OBJS)
		ar rc $(NAME) $(LIBFT) $(OBJS) 
		
.c.o	: $(SRCS)
		$(CC) $(FLAG) -c $< -o $(<:.c=.o)

clean	: 
		$(RM) $(OBJS)

fclean	: clean
		$(RM) $(NAME)

re		: fclean all

main	: $(NAME)
		$(CC) $(FLAG) $(NAME) $(LIBFT) main_printf/main.c -o test