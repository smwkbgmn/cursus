#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

// char *get_next_line(int fd)
// {  
//     static char	*data;
//     char		*buf;
//     char		*temp;
    
//     if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
//     {
//         if (data)
//         {
//             free(data);
//             data = NULL;
//         }
//         return (NULL);
//     }
//     buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
//     // buf = (char *)malloc(-1);
//     if (buf == NULL)
//         return (NULL);
//     temp = read_buf(fd, &data, buf, 1);ㅈ
//     if (temp == NULL)
//     {
//         if (data)
//         {
//             free(data);
//             data = NULL;
//         }
//     }
//     free(buf);
//     buf = NULL;
//     return temp;
// }

char	*get_next_line(int fd)
{
	static char	*data;
	char		*buf;
	char		*temp;

	temp = NULL;
	if (fd >= 0 && BUFFER_SIZE > 0 && read(fd, 0, 0) != ERROR)
	{
		buf = malloc(BUFFER_SIZE + 1); 
		// buf = malloc(-1);
		if (buf)
			temp = read_buf(fd, &data, buf, 1);
		ft_free(&buf);
	}
	if (data && !temp)
		ft_free(&data);
	return (temp);
}

char *read_buf(int fd, char **data, char *buf, int size)
{
    char *temp;
 
    temp = NULL;
    while (size)
    {
        size = read(fd, buf, BUFFER_SIZE);
        if (size == ERROR)
            return (NULL);
        buf[size] = '\0';
        if (!*data)
        {
            *data = ft_strdup("");
            if (!*data)
                return (NULL);
        }
        if (size == 0)
            return size_is_zero(data);
        temp = *data;
        *data = ft_strjoin(*data, buf);
        if (*data == NULL)
            return NULL;
        free(temp);
        temp = NULL;
        if (ft_strchr(*data, '\n') != -1)
            return devide_line(data);
    }
    return temp;
}

char *read_buf(int fd, char **data, char *buf, int size)
{
	char	*temp;
	
	temp = NULL;
	while (size)
	{
		size = read(fd, buf, BUFFER_SIZE);
		if (size == ERROR)

	}
}

char    *size_is_zero(char **data)
{
    char *line;
    
    if (ft_strchr(*data, '\n') != -1)
        return devide_line(data);
    line = ft_substr(*data, 0, ft_strlen(*data));
    if (!line)
    {
        free(*data);
        *data = NULL;
        return line;
    }
    if (*line == '\0')
		ft_free(&line);
	ft_free(data);
    return (line);
}

char *devide_line(char **data)
{
    char *line;
    char *data_new;
    int idx;
    
    data_new = 0;
    idx = ft_strchr(*data, '\n');
    line = ft_substr(*data, 0, idx + 1);
    if (line)
        data_new = ft_substr(*data, idx + 1, ft_strlen(*data));
    free(*data);
    *data = data_new;
    return line;
}

// #include <unistd.h>

// void	abc(void)
// {
// 	system("leaks a.out");
// }

// int	main(void)
// {
// 	char	*line;

// 	line = get_next_line(open("test", O_RDONLY));
// 	free(line);

// 	atexit(abc);
// }
