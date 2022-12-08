NAME		= libftprintf.a

CC			= cc
FLAG		= -Wall -Wextra -Werror -I $(DIR_HEADER)

SRCS		= $(wildcard $(DIR_UTL)/*.c) $(wildcard $(DIR_SPCF)/*.c)
OBJS		= $(SRCS:.c=.o)
LIBFT		= $(DIR_LIBFT)/libft.a

DIR_HEADER	= include
DIR_UTL		= source/utility
DIR_SPCF	= source/specifier
DIR_LIBFT	= libft

all		: $(NAME)

$(NAME)	: $(LIBFT) $(OBJS)
		cp $(LIBFT) $(NAME)
		ar rc $(NAME) $(OBJS)

$(LIBFT):
		$(MAKE) -C $(DIR_LIBFT) all
		
%.o		: %.c
		$(CC) $(FLAG) -c $< -o $@

clean	: 
		$(MAKE) -C $(DIR_LIBFT) clean
		$(RM) $(OBJS)

fclean	: clean
		$(MAKE) -C $(DIR_LIBFT) fclean
		$(RM) $(NAME) a.out

re		: fclean all

.PHONY	: all clean fclean re



main	: $(NAME) $(LIBFT) main/main.c
		$(MAKE) -C $(DIR_LIBFT) all
		$(CC) $(FLAG) -L$(DIR_LIBFT) -lft $(NAME) main/main.c

a.out		: 
		@$(CC) $(FLAG) main/main.c
		@./a.out
		@$(RM) a.out