NAME	= libft.a

CC		= cc
FLAG	= -Wall -Wextra -Werror

SRC_MAN	= \
ft_strnstr.c \
ft_isdigit.c \
ft_strlcpy.c \
ft_strlen.c \
ft_memcmp.c \
ft_strchr.c \
ft_bzero.c \
ft_isascii.c \
ft_memcpy.c \
ft_isprint.c \
ft_toupper.c \
ft_strrchr.c \
ft_isalpha.c \
ft_memchr.c \
ft_memset.c \
ft_strncmp.c \
ft_memmove.c \
ft_strlcat.c \
ft_calloc.c \
ft_strdup.c \
ft_atoi.c \
ft_isalnum.c \
ft_tolower.c \
\
ft_putstr_fd.c \
ft_putnbr_fd.c \
ft_striteri.c \
ft_strjoin.c \
ft_putendl_fd.c \
ft_split.c \
ft_putchar_fd.c \
ft_substr.c \
ft_strtrim.c \
ft_strmpi.c \
ft_itoa.c

SRC_BNS	= \
ft_lstadd_back.c \
ft_lstnew.c \
ft_lstlast.c \
ft_lstclear.c \
ft_lstiter.c \
ft_lstmap.c \
ft_lstsize.c \
ft_lstadd_front.c \
ft_lstdelone.c

OBJ_MAN	:= $(SRC_MAN:.c=.o)
OBJ_BNS := $(SRC_BNS:.c=.o)

all		: $(NAME)

$(NAME)	: $(NAME)($(OBJ_MAN))

# $(NAME)(%)	: %
# 			ar rc $@ $<

%.o		: %.c
		$(CC) $(FLAG) -c $< -o $@

clean	:
		$(RM) $(OBJ_MAN) $(OBJ_BNS)

fclean	: clean
		$(RM) $(NAME)

re		: fclean all

bonus	: $(NAME)($(OBJ_MAN)) $(NAME)($(OBJ_BNS))

# .PRECIOUS : %.o
.PHONY	: all clan fcelan re bonus