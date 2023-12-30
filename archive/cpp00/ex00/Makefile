NAME		= megaphone

CC			= c++
FLAG		= -Wall -Wextra -Werror \
$(F_STD)

F_STD		= -std=c++98

SRC			= $(wildcard *.cpp)

OBJ			= $(SRC:.cpp=.o)

all			: $(NAME)

$(NAME)		: $(OBJ)
			$(CC) $(FLAG) $(OBJ) -o $@

%.o			: %.c
			$(CC) $(FLAG) -c $< -o $@

clean		:
			$(RM) $(OBJ)

fclean		:
			make clean
			$(RM) $(NAME)

re			:
			make fclean
			make all

.PHONY		: all celan fclean re
