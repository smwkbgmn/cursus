NAME	= libft.a

CC		= cc
FLAG	= -Wall -Wextra -Werror -I include

SRCS	= $(wildcard libc/*.c) $(wildcard additional/*.c) $(wildcard bonus/*.c)
OBJS	= $(SRCS:.c=.o)

all		: $(NAME)

$(NAME)	: $(OBJS)
		ar rc $(NAME) $(OBJS)

.c.o	: $(SRCS)
		$(CC) $(FLAG) -c $< -o $(<:.c=.o)

clean	:
		$(RM) $(OBJS) $(wildcard main*.o)

fclean	: clean
		$(RM) $(NAME) libc add bns

re		: fclean all

lc		: $(NAME) main_libc.c
		$(CC) $(FLAG) $(NAME) main_libc.c -o lc

add		: $(NAME) main_additional.c
		$(CC) $(FLAG) $(NAME) main_additional.c -o add

bns		: $(NAME) main_bonus.c
		$(CC) $(FLAG) $(NAME) main_bonus.c -o bns