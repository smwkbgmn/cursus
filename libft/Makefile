NAME	= test.out

CC		= cc
FLAG	= -Wall -Wextra -Werror

SRCS	= libft_main_libc.c $(wildcard libc/*.c) $(wildcard additional/*.c)
OBJS	= $(SRCS:.c=.o)

all		: $(NAME) clean
$(NAME)	: $(OBJS)
		$(CC) $(FLAG) $(OBJS) -o $(NAME)
.c.o	: $(SRCS) $(HDR)
		$(CC) $(FLAG) -I includes -c $< -o $(<:.c=.o)
clean	:
		$(RM) $(OBJS)
fclean	: clean
		$(RM) $(NAME)
re		: fclean all