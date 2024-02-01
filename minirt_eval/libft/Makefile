NAME		= libft.a
CC			= cc

DIR_HDR		= .
DIR_SRC		= source
DIR_FT		= original
DIR_LIBC	= $(DIR_SRC)/$(DIR_FT)/libc
DIR_ADD		= $(DIR_SRC)/$(DIR_FT)/add
DIR_BONUS	= $(DIR_SRC)/$(DIR_FT)/list
DIR_CUSTOM	= $(DIR_SRC)/custom
DIR_GNL		= $(DIR_SRC)/get_next_line
DIR_PRNTF	= $(DIR_SRC)/ft_printf

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
$(DIR_CUSTOM)/ft_atoi_long.c \
$(DIR_CUSTOM)/ft_free_set_null.c \
$(DIR_CUSTOM)/ft_free.c \
$(DIR_CUSTOM)/ft_itoa_uint_base.c \
$(DIR_CUSTOM)/ft_itoa_uint.c \
$(DIR_CUSTOM)/ft_itoa_ulong_base.c \
$(DIR_CUSTOM)/ft_itoa_ulong.c \
$(DIR_CUSTOM)/ft_lstadd_idx.c \
$(DIR_CUSTOM)/ft_lstdel_idx.c \
$(DIR_CUSTOM)/ft_lstidx.c \
$(DIR_CUSTOM)/ft_putchar.c \
$(DIR_CUSTOM)/ft_putstr.c \
$(DIR_CUSTOM)/ft_strdup_ptr.c \
$(DIR_CUSTOM)/write_hex_len.c \
$(DIR_CUSTOM)/write_hex.c \
\
$(DIR_GNL)/get_next_line_utils.c \
$(DIR_GNL)/get_next_line.c

OBJS	= $(SRCS:.c=.o)

FLAG		= -Wall -Wextra -Werror \
-I $(DIR_HDR) \
-I $(DIR_GNL) \
-I $(DIR_PRNTF)

all			: $(NAME)

$(NAME)		: $(NAME)($(OBJS))

$(NAME)(%)	: %
			ar rc $@ $<

%.o			: %.c
			$(CC) $(FLAG) -c $< -o $@

clean		:
			$(RM) $(OBJS)

fclean		: clean
			$(RM) $(NAME)

re			: 
			$(MAKE) fclean
			$(MAKE) all

.PHONY		: all clan fcelan re