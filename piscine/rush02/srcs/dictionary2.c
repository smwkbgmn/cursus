#include "rush.h"

int get_size(char *f_name)
{
//	printf("get_size\n");
    char buf[1];
    int fd;
    int size;

    fd = open(f_name, O_RDONLY);

    size = 0;
    while (read(fd, buf, 1) != 0)
        size++;

    close(fd);
    return (size);
}

int get_line(char *str)
{
//	printf("get_line\n");
    int line;

    line = 0;
    while (*str)
    {
        if (*str == '\n')
            line++;
        str++;
    }

    return (line);
}

int get_length(char *str)
{
//	printf("get_length\n");
    int len;

    len = 0;
    while (*str != '\n' && *str)
    {
        len++;
        str++;
    }
    return (len);
}

void    init_buffer(char *to_find)
{
    int idx;

    idx = 40;
    while (idx-- > 0)
        *to_find++ = 0;
}