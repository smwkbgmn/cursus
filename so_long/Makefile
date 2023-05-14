NAME		= so_long

ARCH		= arch -x86_64
CC			= $(ARCH) cc

FLAG		= -Wall -Wextra -Werror -I .
FLAG_LIBFT	= -I $(DIR_LIBFT)/include
FLAG_MLX	= -I $(DIR_LIBMLX) -framework OpenGL -framework AppKit -lz
# FLAG_MNLBX	= -framework Metal -framework Metalkit

DIR_SRCS	= sources
DIR_LIBFT	= ../1_archive/libft
DIR_LIBMLX	= mlx

SRCS		= \
so_long.c \
$(wildcard $(DIR_SRCS)/*.c)

OBJS		= $(SRCS:.c=.o)

LIBFT		= $(DIR_LIBFT)/libft.a
LIBMLX		= $(DIR_LIBMLX)/libmlx.a

all			: $(NAME)

$(NAME)		: $(LIBFT) $(LIBMLX) $(OBJS)
			$(CC) $(FLAG) $(FLAG_MLX) $(LIBMLX) $(LIBFT) $(OBJS) -o $@

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
