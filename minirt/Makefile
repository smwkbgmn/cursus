NAME		= miniRT

CC			= cc

FLAG		= -Wall -Wextra -Werror $(F_HDR)

F_HDR	= -I $(DIR_HDR) -I $(DIR_L_FT) -I $(DIR_L_MLX)

SRC		= \
minirt.c \
$(wildcard $(DIR_SRC)/*.c) \
$(wildcard $(DIR_SRC)/object/*.c)

OBJ		= $(SRC:.c=.o)

L_FT		= $(DIR_L_FT)/libft.a
L_MLX		= $(DIR_L_MLX)/libmlx.dylib

DIR_HDR		= .
DIR_SRC	= source
DIR_L_FT	= ../archive/libft
DIR_L_MLX	= mlx

all			: $(NAME)

$(NAME)		: $(L_FT) $(OBJ)
			$(CC) $(FLAG) $(L_FT) $(L_MLX) $(OBJ) -o $@
			cp $(L_MLX) .

%.o			: %.c
			$(CC) $(FLAG) -c $< -o $@

$(L_FT)	:
			make -C $(DIR_L_FT)

clean		:
			$(RM) $(OBJ)
			make -C $(DIR_L_FT) clean

fclean		:
			make clean
			$(RM) $(NAME)
			make -C $(DIR_L_FT) fclean

re			:
			make fclean
			make all

.PHONY		: all celan fclean re
