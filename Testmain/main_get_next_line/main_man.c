#include "main.h"

int	main(void)
{
	// printf("BUFFER_SIZE --- [%d]\n", BUFFER_SIZE);

	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	// printf("fd --- [%d]\n", fd);

	while (1)
	{
		line = get_next_line(fd);
		printf("%s\n\n", line);
		if (line)
			free(line);
		else
			break ;
	}
	
	close(fd);

	// system("leaks gnl_man.out");

	return (0);
}
