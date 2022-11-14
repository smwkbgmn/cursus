#include <unistd.h>
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
		ft_putnbr_fd(n, fd);
	}
	else if (n < 10)
		write(fd, &"0123456789"[n], 1);
	else
	{
		ft_putnbr_fd(n / 10, fd);
		write(fd, &"0123456789"[n % 10], 1);
	}	
}
