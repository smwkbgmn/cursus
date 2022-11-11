#include <unistd.h>
#include <fcntl.h>

int print_file(int fd);

int main(int ac, char **av)
{
	if (ac == 1)
		write(1, "File name missing.\n", 19);
	else if (ac > 2)
		write(1, "Too many arguments.\n", 20);
	else
		close(print_file(open(*(av + 1), O_RDONLY)));
	return (0);
}

// int print_file(int fd)
// {
// 	char buf[1];
// 	int chk;

// 	if (fd < 0)
// 	{
// 		write(1, "Cannot read file.\n", 18);
// 		return (0);
// 	}
// 	chk = 1;
// 	while (chk != 0)
// 	{
// 		chk = read(fd, buf, 1);
// 		if (chk < 0)
// 		{
// 			write(1, "Cannot read file.\n", 18);
// 			return (0);
// 		}
// 		else if (chk > 0)
// 			write(1, buf, 1);
// 	}
// 	return (fd);
// }

int print_file(int fd)
{
	char buf[1];
	int valid;

	if (fd < 0)
	{
		write(1, "Cannot read file.\n", 18);
		return (0);
	}
	while (1)
	{
		valid = read(fd, buf, 1);
		if (valid < 0)
		{
			write(1, "Cannot read file.\n", 18);
			return (0);
		}
		else if (valid == 0)
			break;
		else
			write(1, buf, 1);
	}
	return (fd);
}