#include <unistd.h>

void ft_putchar(char c);
void ft_swap(int *a, int *b);
void ft_putstr(char *str);
int ft_strlen(char *str);
int ft_strcmp(char *s1, char *s2);

int main(void)
{
	int a, b, size, rst_cmp;
	a = 4;
	b = 2;

	ft_putchar('A');
	ft_putstr("\nHello\n");
	size = ft_strlen("Hello");
	write(1, &"0123456789"[size], 1);
	write(1, "\n", 1);
	ft_swap(&a, &b);
	write(1, &"0123456789"[a], 1);
	write(1, &"0123456789"[b], 1);
	rst_cmp = ft_strcmp("01234", "01234");
	write(1, &"0123456789"[rst_cmp], 1);
	write(1, "\n", 1);
}
