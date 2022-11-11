SRCS	= srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c

OBJS	= ${SRCS:.c=.o}
	
cc		= gcc

CFLAGS	= -Wall -Wextra -Werror -Iincludes

LIB		= libft.a

AR		= ar rc

RM		= rm -f

all :		${LIB}


${LIB} :	${OBJS}
				${AR} ${LIB} ${OBJS}

.c.o :		${SRCS}
				${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

re :		fclean all

clean :
				${RM} ${OBJS}
			
fclean :	clean
				${RM} ${LIB}
