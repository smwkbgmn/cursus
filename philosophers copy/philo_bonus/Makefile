NAME		= philo_bonus

CC			= cc

DIR_HDR		= .
DIR_SRCS	= source

SRCS		= \
philo.c \
$(DIR_SRCS)/error.c \
$(DIR_SRCS)/free.c \
$(DIR_SRCS)/init_philo.c \
$(DIR_SRCS)/init_share.c \
$(DIR_SRCS)/valid.c \
$(DIR_SRCS)/life/life_monitor.c \
$(DIR_SRCS)/life/life_one_philo.c \
$(DIR_SRCS)/life/life_start.c \
$(DIR_SRCS)/life/life_timer.c \
$(DIR_SRCS)/life/life1.c \
$(DIR_SRCS)/life/life2.c \
$(DIR_SRCS)/utill/util_life.c \
$(DIR_SRCS)/utill/util_print.c \
$(DIR_SRCS)/utill/util_semaphore.c \
$(DIR_SRCS)/utill/util_thread.c \
$(DIR_SRCS)/utill/util_time.c

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
