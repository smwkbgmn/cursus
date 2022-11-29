NAME		= libftprintf.a

CC			= cc
FLAG		= -Wall -Wextra -Werror -I $(DIR_HEADER)
DIR_HEADER	= include

SRCS		= $(wildcard $(DIR_SRCS)/*.c) $(wildcard $(DIR_SPECIF)/*.c)
DIR_SRCS	= source
DIR_SPECIF	= specifier

OBJS		= $(SRCS:.c=.o)

LIBFT		= $(DIR_LIBFT)/libft.a
DIR_LIBFT	= libft

all		: $(NAME)

$(NAME)	: $(OBJS)
		ar rc $(NAME) $(OBJS)
		
%.o		: %.c
		$(CC) $(FLAG) -I include -c $< -o $@

clean	: 
		$(RM) $(OBJS)

fclean	: clean
		$(RM) $(NAME) a.out

re		: fclean all




$(LIBFT):
		$(MAKE) -C $(DIR_LIBFT) all
		$(MAKE) -C $(DIR_LIBFT) clean

main	: $(NAME) $(LIBFT) main/main.c
		$(CC) $(FLAG) -L$(DIR_LIBFT) -lft $(NAME) main/main.c

.PHONY	: all clean fclean re