#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include "/Users/donghyun/dev/cursus/1_archive/libft/libft.h"

int main(void)
{
	// char	*buf = calloc(50, 1);

	// while (1)
	// {
		// printf("return of read : %zd\n", read(0, buf, 50));
		// printf("buf : %s", buf);
	// 	if (buf[0] == '\0')
	// 		break ;
	// }
	// printf("%s", buf);

	char	*line;
	// char	*buf = malloc(50);

	line = get_next_line(0);
	printf("%p, %s", line, line);
	// read(0, buf, 50);
	// printf("%p, %s", buf, buf);
	return (0);	
}
