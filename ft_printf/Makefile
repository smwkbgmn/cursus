NAME	= libftprintf.a

CC		= cc
FLAG	= -Wall -Wextra -Werror

SRCS	= $(wildcard *.c)
OBJS	= $(SRCS:.c=.o)
LIBFT	= libft.a

all		: $(NAME)

$(NAME)	: $(OBJS)
		ar rc $(NAME) $(OBJS)
		
.c.o	: $(SRCS)
		$(CC) $(FLAG) -c $< -o $(<:.c=.o)

clean	: 
		$(RM) $(OBJS)

fclean	: clean
		$(RM) $(NAME) test

re		: fclean all





main	: $(NAME) main/main.c
		$(CC) $(FLAG) -I. -L. -lft $(NAME) main/main.c -o test