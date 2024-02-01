NAME		= miniRT

CC			= cc
FLAG		= -Wall -Wextra -Werror $(FLAG_HDR)
FLAG_HDR	= -I $(DIR_HDR) -I $(DIR_L_FT) -I $(DIR_L_MLX)

SRC		= \
$(DIR_SRC)/data/parse/get_element.c \
$(DIR_SRC)/data/parse/get_value.c \
$(DIR_SRC)/data/parse/parse.c \
$(DIR_SRC)/data/parse/strtod.c \
$(DIR_SRC)/data/free.c \
$(DIR_SRC)/data/init.c \
$(DIR_SRC)/data/scene.c \
$(DIR_SRC)/data/texture.c \
$(DIR_SRC)/data/utill.c \
$(DIR_SRC)/data/world.c \
$(DIR_SRC)/render/ray/hit/cylinder.c \
$(DIR_SRC)/render/ray/hit/hit.c \
$(DIR_SRC)/render/ray/hit/plane.c \
$(DIR_SRC)/render/ray/hit/sphere.c \
$(DIR_SRC)/render/ray/vector/operation.c \
$(DIR_SRC)/render/ray/vector/product.c \
$(DIR_SRC)/render/ray/vector/vector.c \
$(DIR_SRC)/render/ray/color.c \
$(DIR_SRC)/render/ray/interval.c \
$(DIR_SRC)/render/ray/phong.c \
$(DIR_SRC)/render/ray/ray.c \
$(DIR_SRC)/render/ray/utill.c \
$(DIR_SRC)/render/hook.c \
$(DIR_SRC)/render/render.c \
$(DIR_SRC)/error.c \
minirt.c

OBJ		= $(SRC:.c=.o)

L_FT		= $(DIR_L_FT)/libft.a
L_MLX		= libmlx.dylib

DIR_HDR		= include
DIR_SRC		= source
DIR_L_FT	= libft
DIR_L_MLX	= mlx

all			: $(NAME)

$(NAME)		: $(L_FT) $(L_MLX) $(OBJ)
			cp $(DIR_L_MLX)/libmlx.dylib .
			$(CC) $(FLAG) $(L_FT) $(L_MLX) $(OBJ) -o $@

%.o			: %.c
			$(CC) $(FLAG) -c $< -o $@

$(L_FT)		:
			make -C $(DIR_L_FT)

$(L_MLX)	:
			make -C $(DIR_L_MLX)

clean		:
			$(RM) $(OBJ)
			make -C $(DIR_L_FT) clean
			make -C $(DIR_L_MLX) clean

fclean		:
			make clean
			$(RM) $(NAME) $(L_FT) $(L_MLX)

re			:
			make fclean
			make all

bonus		:
			@make all

.PHONY		: all celan fclean re bonus