NAME		= so_long

CC			= cc

DIR_HDR		= .
DIR_SRCS	= source
DIR_LIBFT	= libft
DIR_LIBMLX	= mlx

SRCS		= \
so_long.c \
$(DIR_SRCS)/init/asset_character.c \
$(DIR_SRCS)/init/asset.c \
$(DIR_SRCS)/init/character.c \
$(DIR_SRCS)/init/game.c \
$(DIR_SRCS)/init/init.c \
$(DIR_SRCS)/init/map.c \
$(DIR_SRCS)/init/mlx.c \
\
$(DIR_SRCS)/play/enemy.c \
$(DIR_SRCS)/play/hook.c \
$(DIR_SRCS)/play/loop1.c \
$(DIR_SRCS)/play/loop2.c \
$(DIR_SRCS)/play/map.c \
\
$(DIR_SRCS)/system/error.c \
$(DIR_SRCS)/system/exit.c \
$(DIR_SRCS)/system/fd.c \
$(DIR_SRCS)/system/free.c \
\
$(DIR_SRCS)/valid/map_dfs1.c \
$(DIR_SRCS)/valid/map_dfs2.c \
$(DIR_SRCS)/valid/map_dfs3.c \
$(DIR_SRCS)/valid/map.c

OBJS		= $(SRCS:.c=.o)

LIBFT		= $(DIR_LIBFT)/libft.a
LIBMLX		= $(DIR_LIBMLX)/libmlx.dylib

FLAG		= -Wall -Wextra -Werror \
$(FLAG_HDR) \
$(FLAG_LIBFT) \
$(FLAG_LIBMLX)

FLAG_HDR	= -I $(DIR_HDR)
FLAG_LIBFT	= -I $(DIR_LIBFT)
FLAG_LIBMLX	= -I $(DIR_LIBMLX)

all			: $(NAME)

$(NAME)		: $(LIBFT) $(LIBMLX) $(OBJS)
			$(CC) $(FLAG) $(LIBFT) $(LIBMLX) $(OBJS) -o $@
			cp $(LIBMLX) .	

$(LIBFT)	:
			$(MAKE) -C $(DIR_LIBFT) all

$(LIBMLX)	:
			$(MAKE) -C $(DIR_LIBMLX)

%.o			: %.c
			$(CC) $(FLAG) -c $< -o $@

clean		:
			$(RM) $(OBJS)
			$(MAKE) -C $(DIR_LIBFT) clean
			$(MAKE) -C $(DIR_LIBMLX) clean

fclean		:
			make clean
			$(RM) $(NAME) $(LIBFT) $(LIBMLX)
			$(RM) libmlx.dylib

re			:
			make fclean
			make all

.PHONY		: all celan fclean re
