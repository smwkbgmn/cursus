NAME		= pipex

CC			= cc

DIR_HDR		= .
DIR_SRCS	= source
DIR_LIBFT	= ../1_archive/libft

SRCS		= \
pipex.c \
$(wildcard $(DIR_SRCS)/*.c)

OBJS		= $(SRCS:.c=.o)

LIBFT		= $(DIR_LIBFT)/libft.a

FLAG		= -Wall -Wextra -Werror \
$(FLAG_HDR) \
$(FLAG_LIBFT) \

FLAG_HDR	= -I $(DIR_HDR)
FLAG_LIBFT	= -I $(DIR_LIBFT)

all			: $(NAME)

$(NAME)		: $(LIBFT) $(LIBMLX) $(OBJS)
			$(CC) $(FLAG) $(LIBFT) $(OBJS) -o $@			

$(LIBFT)	:
			$(ARCH) $(MAKE) -C $(DIR_LIBFT) all

$(LIBMLX)	:
			$(ARCH) $(MAKE) -C $(DIR_LIBMLX)

%.o			: %.c
			$(CC) $(FLAG) -c $< -o $@

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
