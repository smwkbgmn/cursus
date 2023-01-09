#include "main.h"

int	main(void)
{
	int		fd;
	char	*line;

	// fd = open("~/dev/ecole/get_next_line/test.txt", O_RDONLY);
	fd = open("test.txt", O_RDONLY);
	printf("fd --- [%d]\n", fd);

	line = get_next_line(fd);
	printf("%s\n", line);
	free(line);
	
	line = get_next_line(fd);
	printf("%s\n", line);
	free(line);

	close(fd);

	system("leaks gnl_man.out");
	return (0);
}
