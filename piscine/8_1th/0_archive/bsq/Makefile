CC		= gcc
CFLAGS	=-Wall -Wextra -Werror

SRCS	= srcs/bsq.c srcs/free.c srcs/set_default.c srcs/main.c srcs/prints.c \
	 	srcs/get_map.c srcs/get_answer.c srcs/validations.c \
	 	srcs/ft/ft_atoi.c srcs/ft/ft_putchar.c srcs/ft/ft_putstr.c
OBJS	= ${SRCS:.c=.o}

INC		= includes
NAME	= bsq

all : $(NAME)

$(NAME) : $(OBJS)
		$(CC) $(CFLAGS) -o $@ $(OBJS)

%o : %c
		$(CC) $(CFLAGS) -o $@ -c $< -I $(INC)

clean :
		rm -f $(OBJS)

fclean : clean
		rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
