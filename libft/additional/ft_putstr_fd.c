#include <unistd.h>
#include "libft.h"

static int	ft_strlen(char *str);

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

static int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}
