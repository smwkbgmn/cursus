NAME		= libft.a
CC			= cc

DIR_HDR		= .
DIR_SRC		= source
DIR_FT		= original
DIR_LIBC	= $(DIR_SRC)/$(DIR_FT)/libc
DIR_ADD		= $(DIR_SRC)/$(DIR_FT)/add
DIR_BONUS	= $(DIR_SRC)/$(DIR_FT)/list
DIR_CUSTOM	= $(DIR_SRC)/custom
DIR_GNL		= $(DIR_SRC)/get_next_line
DIR_PRNTF	= $(DIR_SRC)/ft_printf

SRCS	= \
$(wildcard $(DIR_LIBC)/*.c) \
$(wildcard $(DIR_ADD)/*.c) \
$(wildcard $(DIR_BONUS)/*.c) \
$(wildcard $(DIR_BTREE)/*.c) \
$(wildcard $(DIR_CUSTOM)/*.c) \
$(wildcard $(DIR_GNL)/*.c) \
$(wildcard $(DIR_PRNTF)/*.c) \
$(wildcard $(DIR_PRNTF)/*/*.c)

OBJS	= $(SRCS:.c=.o)

FLAG		= -Wall -Wextra -Werror \
-I $(DIR_HDR) \
-I $(DIR_GNL) \
-I $(DIR_PRNTF)

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