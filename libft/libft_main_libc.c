#include "main.h"

int main(void)
{
	char s1[100] = "learningisfun";
	char s2[100] = "learningisfun";
	char *st1, *st2;

	st1 = s1;
	st2 = s2; 

	printf ("origin string1\t[%s]\n", st1);
	printf ("origin string2\t[%s]\n\n", st2);

	memcpy(st1 + 8, st1, 10);
	ft_memcpy(st2 + 8, st2, 10);

	printf ("after string1\t[%s]\n", st1);
	printf ("after string2\t[%s]\n", st2);




	return (0);	
}