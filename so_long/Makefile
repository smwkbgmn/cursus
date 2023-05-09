NAME		= so_long

ARCH		= arch -x86_64
CC			= $(ARCH) cc

FLAG		= -Wall -Wextra -Werror -I . -I $(DIR_LIBFT)/include -I $(DIR_MNLBX)
# FLAG_MNLBX	= -L mlx_2021 -l mlx
# FLAG_MNLBX	= -framework Metal -framework Metalkit
FLAG_MNLBX	= -framework OpenGL -framework AppKit -lz

DIR_SRCS	= sources
DIR_LIBFT	= ../1_archive/libft
DIR_MNLBX	= mlx

SRCS		= \
so_long.c \
$(wildcard $(DIR_SRCS)/*.c)

OBJS		= $(SRCS:.c=.o)

LIBFT		= $(DIR_LIBFT)/libft.a
# MNLBX		= libmlx.dylib
MNLBX		= $(DIR_MNLBX)/libmlx.a

all			: $(NAME)

$(NAME)		:  $(MNLBX) $(OBJS)
			$(CC) $(FLAG) $(FLAG_MNLBX) $(MNLBX) $(OBJS) -o $@

$(LIBFT)	:
			$(MAKE) -C $(DIR_LIBFT) all

$(MNLBX)	:
			$(ARCH) $(MAKE) -C $(DIR_MNLBX)

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
