NAME		= libftprintf.a

CC			= cc
FLAG		= -Wall -Wextra -Werror -I include -I $(DIR_LIBFT)/include

SRCS		= $(wildcard $(DIR_UTIL)/*.c) $(wildcard $(DIR_TYPE)/*.c) $(wildcard $(DIR_FLAG)/*.c)
OBJS		= $(SRCS:.c=.o)
LIBFT		= $(DIR_LIBFT)/libft.a

DIR_UTIL	= source/utility
DIR_TYPE	= source/type
DIR_FLAG	= source/flag
DIR_LIBFT	= ../libft

all			: $(NAME)

$(NAME)		: $(LIBFT) $(NAME)($(OBJS))

$(LIBFT)	:
			$(MAKE) -C $(DIR_LIBFT) all
			@cp $(LIBFT) $(NAME)

$(NAME)(%)	: %
			ar rc $@ $<

bonus		: $(NAME) $(NAME)($(OBJS))
		
%.o			: %.c
			$(CC) $(FLAG) -c $< -o $@

clean		: 
			$(RM) $(OBJS)
			$(MAKE) -C $(DIR_LIBFT) clean

fclean		: clean
			$(RM) $(LIBFT) $(NAME)

re			: fclean
			all

.PHONY		: all clean fclean re bonus



################### Test Main ########################

main	: $(NAME) ../Testmain/main_printf/main.c
		@$(CC) $(FLAG) $(NAME) ../Testmain/main_printf/main.c
		@./a.out
		@$(RM) a.out

a		: 
		@$(CC) $(FLAG) ../Testmain/main_printf/main.c
		@./a.out
		@$(RM) a.out