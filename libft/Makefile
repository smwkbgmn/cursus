NAME	= libft.a

CC		= cc
FLAG	= -Wall -Wextra -Werror -I include

SRCS	= $(wildcard source/libc/*.c) \
		$(wildcard source/additional/*.c) \
		$(wildcard source/bonus/*.c)
OBJS	= $(SRCS:.c=.o)

all		: $(NAME)

$(NAME)	: $(OBJS)
		ar rc $(NAME) $(OBJS)

.c.o	: $(SRCS)
		$(CC) $(FLAG) -c $< -o $(<:.c=.o)

clean	:
		$(RM) $(OBJS) $(wildcard main*.o)

fclean	: clean
		$(RM) $(NAME) test

re		: fclean all

lc		: $(NAME) main/main_libc.c
		$(CC) $(FLAG) $(NAME) main/main_libc.c -o test

add		: $(NAME) main/main_additional.c
		$(CC) $(FLAG) $(NAME) main/main_additional.c -o test

bns		: $(NAME) main/main_bonus.c
		$(CC) $(FLAG) $(NAME) main/main_bonus.c -o test