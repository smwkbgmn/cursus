NAME		= pipex

CC			= cc

DIR_HDR		= .
DIR_SRCS	= source
DIR_LIBFT	= ../libft
# DIR_LIBFT	= libft

SRCS		= \
$(DIR_SRCS)/execute_child.c \
$(DIR_SRCS)/execute_parent.c \
$(DIR_SRCS)/execute.c \
$(DIR_SRCS)/init_cmd.c \
$(DIR_SRCS)/init_env.c \
$(DIR_SRCS)/init_file.c \
$(DIR_SRCS)/init_heredoc_write.c \
$(DIR_SRCS)/init_heredoc.c \
$(DIR_SRCS)/init.c \
$(DIR_SRCS)/system_error.c \
$(DIR_SRCS)/system_fd.c \
$(DIR_SRCS)/system_free.c \
pipex.c

OBJS		= $(SRCS:.c=.o)

LIBFT		= $(DIR_LIBFT)/libft.a

FLAG		= -Wall -Wextra -Werror \
$(FLAG_HDR) \
$(FLAG_LIBFT) \

FLAG_HDR	= -I $(DIR_HDR)
FLAG_LIBFT	= -I $(DIR_LIBFT)

all			: $(NAME)

$(NAME)		: $(LIBFT) $(OBJS)
			$(CC) $(FLAG) $(LIBFT) $(OBJS) -o $@

$(LIBFT)	:
			$(MAKE) -C $(DIR_LIBFT) all

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

.PHONY		: all clean fclean re
