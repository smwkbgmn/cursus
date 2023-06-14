NAME		= so_long

ARCH		= arch -x86_64
CC			= cc

DIR_HDR		= .
DIR_SRCS	= source
DIR_LIBFT	= ../1_archive/libft
DIR_LIBMLX	= mlx

SRCS		= \
so_long.c \
$(wildcard $(DIR_SRCS)/*.c)

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
# FLAG_MNLBX	= -framework Metal -framework Metalkit

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

fclean		:
			make clean
			$(RM) $(NAME) $(LIBFT)

re			:
			make fclean
			make all

.PHONY		: all celan fclean re
