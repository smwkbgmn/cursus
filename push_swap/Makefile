NAME		= push_swap

CC			= cc
FLAG		= -Wall -Wextra -Werror -I $(DIR_LIBFT)/include

DIR_LIBFT	= ../1_archive/libft

SRCS		= \
op_push.c \
op_swap.c \
op_rotate.c \
op_rotate_rvs.c \
util_push_swap.c \
util_sort.c \
util_stack.c \
util_valid.c \
test.c

OBJS		= $(SRCS:.c=.o)

LIBFT		= $(DIR_LIBFT)/libft.a

all			: $(NAME)

$(NAME)		: $(LIBFT) $(OBJS)
			$(CC) $(FLAG) $(LIBFT) $(OBJS) -o $@

%.o			: %.c
			$(CC) $(FLAG) -c $< -o $@

# %.o			: %.c
# 			$(CC) $(FLAG) -c $< -o $@

$(LIBFT)	:
			$(MAKE) -C $(DIR_LIBFT) all

clean		:
			$(RM) $(OBJS)
			$(MAKE) -C $(DIR_LIBFT) clean

fclean		:
			make clean
			$(RM) $(NAME) $(LIBFT)

re			:
			make fclean
			make all

.PHONY		: all celan fclean re

####################################
############ FOR TEST ##############
####################################

SIZE		= 10

gen			: 
			@$(CC) test_gen_input.c -o test_gen_input
			@./test_gen_input $(SIZE)
			@$(RM) test_gen_input

test		: $(NAME)
			@./$(NAME) $$(cat test_in)
			@$(RM) $(NAME)

out			: $(NAME)
			@./$(NAME) $$(cat test_in) > test_out
			@$(R M) $(NAME)
