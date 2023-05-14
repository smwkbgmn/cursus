NAME	= libft.a

DIR_HDR		= include
DIR_SRC		= source
DIR_LIBC	= $(DIR_SRC)/libc
DIR_ADD		= $(DIR_SRC)/add
DIR_BONUS	= $(DIR_SRC)/list
DIR_CUSTOM	= $(DIR_SRC)/custom
DIR_GNL		= $(DIR_SRC)/gnl
# DIR_PRNTF	= $(DIR_SRC)/printf

CC			= cc
FLAG		= -Wall -Wextra -Werror $(FLAG_HDR)
FLAG_HDR	= -I $(DIR_HDR)

SRCS	= \
$(wildcard $(DIR_LIBC)/*) \
$(wildcard $(DIR_ADD)/*) \
$(wildcard $(DIR_BONUS)/*) \
$(wildcard $(DIR_CUSTOM)/*) \
$(wildcard $(DIR_GNL)/*) \
# $(wildcard $(DIR_PRNTF)/**)

OBJS	= $(SRCS:.c=.o)

all			: $(NAME)

$(NAME)		: $(NAME)($(OBJS))

$(NAME)(%)	: %
			ar rc $@ $<

%.o			: %.c
		$(CC) $(FLAG) -c $< -o $@

clean		:
		$(RM) $(OBJS)

fclean		: clean
		$(RM) $(NAME)

re			: fclean all

.PHONY		: all clan fcelan re