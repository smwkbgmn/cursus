NAME		= philo

CC			= cc

DIR_HDR		= .
DIR_SRCS	= source

SRCS		= \
philo.c \
$(wildcard $(DIR_SRCS)/*.c) \
$(wildcard $(DIR_SRCS)/life/*.c)

OBJS		= $(SRCS:.c=.o)

FLAG		= -Wall -Wextra -Werror \
$(FLAG_HDR)

FLAG_HDR	= -I $(DIR_HDR)

all			: $(NAME)

$(NAME)		: $(OBJS)
			$(CC) $(FLAG) $(OBJS) -o $@

%.o			: %.c
			$(CC) $(FLAG) -c $< -o $@

clean		:
			$(RM) $(OBJS)

fclean		:
			make clean
			$(RM) $(NAME)

re			:
			make fclean
			make all

.PHONY		: all celan fclean re
