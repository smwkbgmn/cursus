NAME		= minishell

CC			= cc

FLAG		= -Wall -Wextra -Werror -fsanitize=address \
$(FLAG_HEADER)

FLAG_HEADER	= -I $(DIR_HDR) -I $(DIR_LIB_FT) -I $(DIR_LIB_RL)/include

SRCS		= \
minishell.c \
$(DIR_SRCS)/builtin/cd_path.c \
$(DIR_SRCS)/builtin/cd.c \
$(DIR_SRCS)/builtin/echo.c \
$(DIR_SRCS)/builtin/env.c \
$(DIR_SRCS)/builtin/exit.c \
$(DIR_SRCS)/builtin/export_proceed.c \
$(DIR_SRCS)/builtin/export.c \
$(DIR_SRCS)/builtin/pwd.c \
$(DIR_SRCS)/builtin/unset.c \
$(DIR_SRCS)/execute/child_builtin.c \
$(DIR_SRCS)/execute/child.c \
$(DIR_SRCS)/execute/execute.c \
$(DIR_SRCS)/execute/parent.c \
$(DIR_SRCS)/init/parse/expand_env.c \
$(DIR_SRCS)/init/parse/expand_wildcard1.c \
$(DIR_SRCS)/init/parse/expand_wildcard2.c \
$(DIR_SRCS)/init/parse/lexer_none_meta.c \
$(DIR_SRCS)/init/parse/lexer_zerolen.c \
$(DIR_SRCS)/init/parse/lexer.c \
$(DIR_SRCS)/init/parse/parse.c \
$(DIR_SRCS)/init/get_cmd_rd.c \
$(DIR_SRCS)/init/get_cmd.c \
$(DIR_SRCS)/init/get_exe.c \
$(DIR_SRCS)/init/get_heredoc_fork.c \
$(DIR_SRCS)/init/get_heredoc.c \
$(DIR_SRCS)/init/get_path.c \
$(DIR_SRCS)/init/init.c \
$(DIR_SRCS)/init/utill.c \
$(DIR_SRCS)/system/error.c \
$(DIR_SRCS)/system/fd.c \
$(DIR_SRCS)/system/free.c \
$(DIR_SRCS)/system/signal.c \
$(DIR_SRCS)/system/terminal.c

OBJS		= $(SRCS:.c=.o)

LIB_FT		= $(DIR_LIB_FT)/libft.a
LIB_RL		= -L$(DIR_LIB_RL)/lib -lreadline
LIB_TM		= -lncurses

DIR_HDR		= include 
DIR_SRCS	= source

DIR_LIB_FT	= ../archive/libft
DIR_LIB_RL	= /Users/donghyu2/.brew/Cellar/readline/8.2.1

all			: $(NAME)

$(NAME)		: $(LIB_FT) $(OBJS)
			$(CC) $(FLAG) $(LIB_FT) $(LIB_RL) $(LIB_TM) \
			$(OBJS) -o $@

%.o			: %.c
			$(CC) $(FLAG) -c $< -o $@

$(LIB_FT)	:
			make -C $(DIR_LIB_FT)

clean		:
			$(RM) $(OBJS)
			make -C $(DIR_LIB_FT) clean

fclean		:
			make clean
			$(RM) $(NAME)
			make -C $(DIR_LIB_FT) fclean

re			:
			make fclean
			make all

.PHONY		: all celan fclean re
