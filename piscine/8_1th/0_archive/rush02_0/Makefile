SRCS	= main.c srcs/get_dict.c srcs/print.c srcs/hundred.c srcs/etc.c srcs/free.c

OBJS	= ${SRCS:.c=.o}
	
CC		= gcc

CFLAGS	= -Wall -Wextra -Werror -Iincludes

NAME	= rush-02

RM		= rm -f

all :		${NAME}


${NAME} :	${OBJS}
				${CC} ${CFLAGS} ${OBJS} -o ${NAME}

.c.o :		${SRCS}
				${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

re :		fclean all

clean :
				${RM} ${OBJS}
			
fclean :	clean
				${RM} ${NAME}
