# NAME	= cd echo env exit export pwd unset
# NAME	= $(DIR_BIN)/$(PROGRAM)
PROGRAM = pwd cd

CC		= cc
FLAG	= -Wall -Werror -Wextra \
$(FLAG_HEADER)

FLAG_HEADER	= -I $(DIR_HDR) -I $(DIR_LIBFT)

SRCS		= \
builtin.c \
source/$(PROGRAM).c
# $(PROGRAM)/$(PROGRAM).c

OBJS		= $(SRCS:.c=.o)

LIBFT		= $(DIR_LIBFT)/libft.a

DIR_HDR		= .
DIR_LIBFT	= ../../archive/libft
DIR_BIN		= bin

all			: $(DIR_BIN)/$(PROGRAM)

$(DIR_BIN)/$(PROGRAM)		: $(LIBFT) $(OBJS)
			$(CC) $(FLAG) $(LIBFT) $(OBJS) -o $@

# all			: $(NAME)

# $(NAME)		: $(LIBFT) $(OBJS)
# 			$(CC) $(FLAG) $(LIBFT) $(OBJS) -o $@

%.o			: %.c
			$(CC) $(FLAG) -c $< -o $@

$(LIBFT)	:
			make -C $(DIR_LIBFT)

clean		:
			$(RM) $(OBJS)
			make -C $(DIR_LIBFT) clean

fclean		:
			make clean
			$(RM) $(NAME)
			make -C $(DIR_LIBFT) fclean

re			:
			make fclean
			make all

.PHONY		: all celan fclean re
