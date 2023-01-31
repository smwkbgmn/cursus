#include <stdio.h>
#include <string.h>

int main(void)
{
	char	*str = strdup("0123456789");

	printf("[%zu]\n", strchr(str, '1') - str);
	return (0);
}