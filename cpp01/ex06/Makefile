NAME		= harlFilter

CPP			= c++
FLAG		= -Wall -Wextra -Werror \
$(FLG_STD)

FLG_STD		= -std=c++98

SRC			= $(wildcard *.cpp)

OBJ			= $(SRC:.cpp=.o)

all			: $(NAME)

$(NAME)		: $(OBJ)
			$(CPP) $(FLAG) $(OBJ) -o $@

%.o			: %.c
			$(CPP) $(FLAG) -c $< -o $@

clean		:
			$(RM) $(OBJ)

fclean		:
			make clean
			$(RM) $(NAME)

re			:
			make fclean
			make all

.PHONY		: all celan fclean re
