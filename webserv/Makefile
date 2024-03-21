NAME		= Webserv

CPP			= c++
FLAG		= -Wall -Wextra -Werror \
$(FLG_STD) -I include

FLG_STD		= -std=c++98

SRC			= \
$(wildcard *.cpp) \
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

re			:
			make fclean
			make all

.PHONY		: all celan fclean re
