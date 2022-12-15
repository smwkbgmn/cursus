NAME	= libft.a

CC		= cc
FLAG	= -Wall -Wextra -Werror -I $(DIR_HEADER)

SRCS	= \
$(DIR_LIBC)/ft_strnstr.c \
$(DIR_LIBC)/ft_isdigit.c \
$(DIR_LIBC)/ft_strlcpy.c \
$(DIR_LIBC)/ft_strlen.c \
$(DIR_LIBC)/ft_memcmp.c \
$(DIR_LIBC)/ft_strchr.c \
$(DIR_LIBC)/ft_bzero.c \
$(DIR_LIBC)/ft_isascii.c \
$(DIR_LIBC)/ft_memcpy.c \
$(DIR_LIBC)/ft_isprint.c \
$(DIR_LIBC)/ft_toupper.c \
$(DIR_LIBC)/ft_strrchr.c \
$(DIR_LIBC)/ft_isalpha.c \
$(DIR_LIBC)/ft_memchr.c \
$(DIR_LIBC)/ft_memset.c \
$(DIR_LIBC)/ft_strncmp.c \
$(DIR_LIBC)/ft_memmove.c \
$(DIR_LIBC)/ft_strlcat.c \
$(DIR_LIBC)/ft_calloc.c \
$(DIR_LIBC)/ft_strdup.c \
$(DIR_LIBC)/ft_atoi.c \
$(DIR_LIBC)/ft_isalnum.c \
$(DIR_LIBC)/ft_tolower.c \
\
$(DIR_ADD)/ft_putstr_fd.c \
$(DIR_ADD)/ft_putnbr_fd.c \
$(DIR_ADD)/ft_striteri.c \
$(DIR_ADD)/ft_strjoin.c \
$(DIR_ADD)/ft_putendl_fd.c \
$(DIR_ADD)/ft_split.c \
$(DIR_ADD)/ft_putchar_fd.c \
$(DIR_ADD)/ft_substr.c \
$(DIR_ADD)/ft_strtrim.c \
$(DIR_ADD)/ft_strmpi.c \
$(DIR_ADD)/ft_itoa.c \
\
$(DIR_BONUS)/ft_lstadd_back.c \
$(DIR_BONUS)/ft_lstnew.c \
$(DIR_BONUS)/ft_lstlast.c \
$(DIR_BONUS)/ft_lstclear.c \
$(DIR_BONUS)/ft_lstiter.c \
$(DIR_BONUS)/ft_lstmap.c \
$(DIR_BONUS)/ft_lstsize.c \
$(DIR_BONUS)/ft_lstadd_front.c \
$(DIR_BONUS)/ft_lstdelone.c \
\
$(DIR_CUSTOM)/write_hex_lower.c \
$(DIR_CUSTOM)/write_hex_upper.c \
$(DIR_CUSTOM)/write_hex_lower_len.c \
$(DIR_CUSTOM)/write_hex_upper_len.c \
$(DIR_CUSTOM)/write_address.c \
$(DIR_CUSTOM)/ft_putchar_len.c \
$(DIR_CUSTOM)/ft_putstr_len.c \
$(DIR_CUSTOM)/ft_putnbr_len.c

OBJS	= $(SRCS:.c=.o)

DIR_HEADER	= include
DIR_LIBC	= source/libc
DIR_ADD		= source/additional
DIR_BONUS	= source/bonus
DIR_CUSTOM	= source/custom

all		: $(NAME)

$(NAME)	: $(OBJS) $(NAME)($(OBJS))

$(NAME)(%)	: %
			ar rc $@ $<

%.o		: %.c
		$(CC) $(FLAG) -c $< -o $@

clean	:
		$(RM) $(OBJS)

fclean	: clean
		$(RM) $(NAME)

re		: fclean all

.PRECIOUS	: %.o
.PHONY		: all clan fcelan re