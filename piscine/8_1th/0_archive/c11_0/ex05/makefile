SRCS	= main.c operator.c ft_strcpy.c ft_putnbr.c ft_atoi.c

OBJS	= ${SRCS:.c=.o}

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror -Iincludes

NAME	= do-op

RM		= rm -f

all :		$(NAME)
	
${NAME} :	${OBJS}
				${CC} ${CFLAGS} ${OBJS} -o ${NAME}

.c.o :		${SRCS}
				${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean :
				${RM} ${OBJS}
