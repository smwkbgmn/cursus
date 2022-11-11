#include "rush.h"

char *import(char *f_name, int size);
char **split(char *buf);
void print_dict(char **dict);

char **get_dict(char *f_name)
{
    char *buf;
    char **dict;
    
    buf = import(f_name, get_size(f_name));
    dict = split(buf);

    free(buf);
    return (dict);
}

char *import(char *f_name, int size)
{
    char *buf;
    int fd;
    
    buf = (char *)malloc(sizeof(char) * (size + 1));
    
    fd = open(f_name, O_RDONLY);
    read(fd, buf, size);
    close(fd);
    
    return (buf);
}

char **split(char *buf)
{
    char **dict;
    int line;

    dict = (char **)malloc(sizeof(char *) * (get_line(buf) + 1));
    if (dict == 0)
        return ((void *)0);

    line = 0;
    while (*buf)
    {
        dict[line] = (char *)malloc(sizeof(char) * (get_length(buf) + 1));
        if (dict[line] == 0)
        {
           free_dict(dict, line);
           return (0);
        }

		apply_atoi_rule(dict[line], buf);
        while (*buf != ':' && *buf)
            buf++;
        ft_strncat(dict[line], ":", 1);
        buf++;
		while (*buf == ' ')
			buf++;
        while (*buf != '\n' && *buf)
			ft_strncat(dict[line], buf++, 1);
        buf++;
        line++;
    }
    dict[line] =  0;

    return (dict);
}