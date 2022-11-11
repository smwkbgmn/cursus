OBJS = main.o find_largest_square.o ft.o read_file.o read_input.o check_print_validation.o print_map.o
CC = gcc
NAME = bsq
W= -Wall -Wextra -Werror


$(NAME) : $(OBJS)
	$(CC) $(W) -o $@ $(OBJS) 

clean : 
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

all : $(NAME)

re : fclean all

main.o : main.c
	$(CC) $(W) -c -o main.o main.c
find_largest_square.o : find_largest_square.c
	$(CC) $(W) -c -o find_largest_square.o find_largest_square.c
ft.o : ft.c
	$(CC) $(W) -c -o ft.o ft.c
read_file.o : read_file.c read_input.o
	$(CC) $(W) -c -o read_file.o read_file.c
read_input.o : read_input.c
	$(CC) $(W) -c -o read_input.o read_input.c
check_print_validation.o : check_print_validation.c
	$(CC) $(W) -c -o check_print_validation.o check_print_validation.c
print_map.o : print_map.c
	$(CC) $(W) -c -o print_map.o print_map.c
.PHONY: clean fclean all re
