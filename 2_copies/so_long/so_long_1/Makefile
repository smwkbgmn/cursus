NAME		= so_long

CC			= cc

DIR_HDR		= .
DIR_SRCS	= source
DIR_LIBFT	= libft
DIR_LIBMLX	= mlx

SRCS		= \
so_long.c \
$(DIR_SRCS)/init/init_asset1.c \
$(DIR_SRCS)/init/init_asset2.c \
$(DIR_SRCS)/init/init_enemy.c \
$(DIR_SRCS)/init/init_game.c \
$(DIR_SRCS)/init/init_map.c \
$(DIR_SRCS)/init/init_mlx.c \
$(DIR_SRCS)/init/init.c \
\
$(DIR_SRCS)/play/play_hook.c \
$(DIR_SRCS)/play/play_loop1.c \
$(DIR_SRCS)/play/play_loop2.c \
\
$(DIR_SRCS)/valid/valid_map_dfs1.c \
$(DIR_SRCS)/valid/valid_map_dfs2.c \
$(DIR_SRCS)/valid/valid_map_dfs3.c \
$(DIR_SRCS)/valid/valid_map.c \
\
$(DIR_SRCS)/util_map.c \
$(DIR_SRCS)/util.c

OBJS		= $(SRCS:.c=.o)

LIBFT		= $(DIR_LIBFT)/libft.a
LIBMLX		= $(DIR_LIBMLX)/libmlx.a

FLAG		= -Wall -Wextra -Werror \
$(FLAG_HDR) \
$(FLAG_LIBFT) \
$(FLAG_LIBMLX)

FLAG_HDR	= -I $(DIR_HDR)
FLAG_LIBFT	= -I $(DIR_LIBFT)
FLAG_LIBMLX	= -I $(DIR_LIBMLX)
FLAG_MLX	= -framework OpenGL -framework AppKit -lz

all			: $(NAME)

$(NAME)		: $(LIBFT) $(LIBMLX) $(OBJS)
			$(CC) $(FLAG) $(FLAG_MLX) $(LIBMLX) $(LIBFT) $(OBJS) -o $@			

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

re			:
			make fclean
			make all

.PHONY		: all celan fclean re
