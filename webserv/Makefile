NAME		= webserv

CPP			= c++
FLAG		= -Wall -Wextra -Werror \
$(FLG_STD) -I include -I include/class

FLG_STD		= -std=c++98

SRC			= \
$(wildcard src/*.cpp) \
$(wildcard src/cgi/*.cpp) \
$(wildcard src/http/*.cpp) \
$(wildcard src/tcp/*.cpp)

OBJ			= $(SRC:.cpp=.o)

all			: $(NAME)

$(NAME)		: $(OBJ)
			$(CPP) $(FLAG) $(OBJ) -o $@

%.o			: %.cpp
			$(CPP) $(FLAG) -c $< -o $@

clean		:
			$(RM) $(OBJ)

fclean		:
			make clean
			$(RM) $(NAME)

rmlog		:
			$(RM) $(wildcard log/*.log)

re			:
			make fclean
			make all

.PHONY		: all celan fclean re
