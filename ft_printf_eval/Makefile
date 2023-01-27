NAME		= libftprintf.a

CC			= cc
FLAG		= -Wall -Wextra -Werror -I include -I $(DIR_LIBFT)/include

SRCS		= \
$(DIR_UTIL)/utill_flag.c \
$(DIR_UTIL)/utill_list1.c \
$(DIR_UTIL)/utill_list2.c \
$(DIR_UTIL)/utill_printf.c \
$(DIR_UTIL)/utill_type.c \
\
$(DIR_TYPE)/type_c.c \
$(DIR_TYPE)/type_d.c \
$(DIR_TYPE)/type_i.c \
$(DIR_TYPE)/type_p.c \
$(DIR_TYPE)/type_percent.c \
$(DIR_TYPE)/type_s.c \
$(DIR_TYPE)/type_u.c \
$(DIR_TYPE)/type_x_lower.c \
$(DIR_TYPE)/type_x_upper.c \
\
$(DIR_FLAG)/flag_dash.c \
$(DIR_FLAG)/flag_hash.c \
$(DIR_FLAG)/flag_plus.c \
$(DIR_FLAG)/flag_precision.c \
$(DIR_FLAG)/flag_space.c \
$(DIR_FLAG)/flag_width.c \
$(DIR_FLAG)/flag_zero.c

OBJS		= $(SRCS:.c=.o)

DIR_UTIL	= source/utility
DIR_TYPE	= source/type
DIR_FLAG	= source/flag

LIBFT		= $(DIR_LIBFT)/libft.a

DIR_LIBFT	= libft

all			: $(NAME)

$(NAME)		: $(LIBFT) $(NAME)($(OBJS))

$(LIBFT)	:
			$(MAKE) -C $(DIR_LIBFT) all
			@cp $(LIBFT) $(NAME)

$(NAME)(%)	: %
			@ar rc $@ $<

bonus		: $(NAME)
		
%.o			: %.c
			@$(CC) $(FLAG) -c $< -o $@

clean		: 
			$(RM) $(OBJS)
			$(MAKE) -C $(DIR_LIBFT) clean

fclean		: 
			make clean
			$(RM) $(LIBFT) $(NAME)

re			: 
			make fclean
			make all

.PHONY		: all clean fclean re bonus