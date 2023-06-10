NAME_MAN	= push_swap
NAME_BNS	= checker

CC			= cc
FLAG		= -Wall -Wextra -Werror -I . -I $(DIR_LIBFT)

DIR_SRC		= source
DIR_OPER	= $(DIR_SRC)/operator
DIR_SORT	= $(DIR_SRC)/sorting
DIR_UTIL	= $(DIR_SRC)/utill
DIR_CHECKR	= $(DIR_SRC)/checker
DIR_LIBFT	= ../1_archive/libft

SRCS_MAN	= \
push_swap.c \
$(DIR_OPER)/op_push.c \
$(DIR_OPER)/op_rotate_rvs.c \
$(DIR_OPER)/op_rotate.c \
$(DIR_OPER)/op_swap.c \
$(DIR_SORT)/sort_3.c \
$(DIR_SORT)/sort_5.c \
$(DIR_SORT)/sort_insertion.c \
$(DIR_SORT)/sort_reverse.c \
$(DIR_SORT)/sort_rotate.c \
$(DIR_SORT)/sort_hourglass1.c \
$(DIR_SORT)/sort_hourglass2.c \
$(DIR_UTIL)/util_init.c \
$(DIR_UTIL)/util_select.c \
$(DIR_UTIL)/util_sort.c \
$(DIR_UTIL)/util_stack.c \
$(DIR_UTIL)/util_valid.c \

OBJS_MAN	= $(SRCS_MAN:.c=.o)

SRCS_BNS	= \
$(DIR_CHECKR)/checker.c \
$(DIR_CHECKR)/execute.c \
$(DIR_OPER)/op_push.c \
$(DIR_OPER)/op_rotate_rvs.c \
$(DIR_OPER)/op_rotate.c \
$(DIR_OPER)/op_swap.c \
$(DIR_UTIL)/util_init.c \
$(DIR_UTIL)/util_stack.c \
$(DIR_UTIL)/util_valid.c \

OBJS_BNS	= $(SRCS_BNS:.c=.o)

LIBFT		= $(DIR_LIBFT)/libft.a

all			: $(NAME_MAN)

$(NAME_MAN)	: $(LIBFT) $(OBJS_MAN)
			$(CC) $(FLAG) $(LIBFT) $(OBJS_MAN) -o $@

%.o			: %.c
			$(CC) $(FLAG) -c $< -o $@

$(LIBFT)	:
			$(MAKE) -C $(DIR_LIBFT) all

clean		:
			$(RM) $(OBJS_MAN)
			$(RM) $(OBJS_BNS)
			$(MAKE) -C $(DIR_LIBFT) clean

fclean		:
			make clean
			$(RM) $(NAME_MAN) $(NAME_BNS) $(LIBFT)

re			:
			make fclean
			make all
			
bonus		: $(NAME_BNS)

$(NAME_BNS)	: $(LIBFT) $(OBJS_BNS)
			$(CC) $(FLAG) $(LIBFT) $(OBJS_BNS) -o $@

.PHONY		: all celan fclean re bonus