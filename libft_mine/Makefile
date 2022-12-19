NAME	= libft.a

CC		= cc
FLAG	= -Wall -Wextra -Werror -I $(DIR_HEADER)

SRCS	= \
$(wildcard $(DIR_LIBC)/*.c) \
$(wildcard $(DIR_ADD)/*.c) \
$(wildcard $(DIR_BONUS)/*.c) \
$(wildcard $(DIR_CUSTOM)/*.c)

OBJS	= $(SRCS:.c=.o)

DIR_HEADER	= include
DIR_LIBC	= source/libc
DIR_ADD		= source/additional
DIR_BONUS	= source/bonus
DIR_CUSTOM	= source/custom

all		: $(NAME)

$(NAME)	: $(NAME)($(OBJS))

%.o		: %.c
		$(CC) $(FLAG) -c $< -o $@

clean	:
		$(RM) $(OBJS)

fclean	: clean
		$(RM) $(NAME)

re		: fclean all

.PHONY	: all clan fcelan re