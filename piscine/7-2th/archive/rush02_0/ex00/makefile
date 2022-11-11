CC=gcc
CFLAGS= -Wall -Wextra -Werror
TARGET=rush-02.a
SRCSDIR=srcs
HEADER=includes
SRCS=$(wildcard *.c $(SRCSDIR)/*.c)
OBJS=$(SRCS:.c=.o)
 
all: $(TARGET)
 
.c.o:
   	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER)
 
$(TARGET): $(OBJS)
    $(CC) $(CFLAGS) -o $@ $^
 
clean:
    rm -f $(SRCSDIR)/*.o
 
fclean: clean
    rm -f $(TARGET)
 
re: fclean all

.PHONY: clean fclean all re
