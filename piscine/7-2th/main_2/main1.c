#include <stdio.h>
#include <string.h>

#include "ex00/ft_strcmp.c"
#include "ex01/ft_strncmp.c"
#include "ex02/ft_strcat.c"
#include "ex03/ft_strncat.c"
#include "ex04/ft_strstr.c"
#include "ex05/ft_strlcat.c"

int main()
{
	{
		printf("======ex00======\n");
		char s1[10] = "abcdefg ";
		char s2[10] = "abcdefg";
		char s3[10] = "   ";
		char s4[10] = "gdcxf";
		printf("%d %d\n", strcmp(s1, s2), ft_strcmp(s1, s2));
		printf("%d %d\n", strcmp(s3, s4), ft_strcmp(s3, s4));
	}
	{
		printf("======ex01======\n");
		char s1[10] = "abcdefg ";
		char s2[10] = "abcdefg";
		char s3[10] = "   ";
		char s4[10] = "gdcxf";
		printf("%d %d\n", strncmp(s1, s2, 6), ft_strncmp(s1, s2, 6));
		printf("%d %d\n", strncmp(s1, s2, 7), ft_strncmp(s1, s2, 7));
		printf("%d %d\n", strncmp(s3, s4, 1), ft_strncmp(s3, s4, 1));
		printf("%d %d\n", strncmp(s3, s4, 0), ft_strncmp(s3, s4, 0));
	}
	{
		printf("======ex02======\n");
		char src[10] = "gaeon";
		char dest0[20] = "hello ";
		char dest1[20] = "hello ";
		char src1[10] = "hi";
		char dest2[20] = "bonjour ";
		char dest3[20] = "bonjour ";
		printf("%s %s\n", strcat(dest0, src), ft_strcat(dest1, src));
		printf("%s %s\n", strcat(dest2, src1), ft_strcat(dest3, src1));
	}
	{
		printf("======ex03======\n");
		char src[10] = "gaeon";
		char dest0[20] = "hello ";
		char dest1[20] = "hello ";
		char src1[10] = "hello";
		char dest2[20] = "bonjour ";
		char dest3[20] = "bonjour ";
		printf("%s %s\n", strncat(dest0, src, 8), ft_strncat(dest1, src, 8));
		printf("%s %s\n", strncat(dest2, src1, 2), ft_strncat(dest3, src1, 2));
	}
	{
		printf("======ex04======\n");
		char str[20] = "abcabcabcdabc";
		char to_find[20] = "abcd";
		char str1[20] = "hello hello";
		char to_find1[20] = "o h";
		printf("%s %s\n", strstr(str, to_find), ft_strstr(str, to_find));
		printf("%s %s\n", strstr(str1, to_find1), ft_strstr(str1, to_find1));
	}
	{
		printf("======ex05======\n");
		char src[10] = "gaeon";
		char src1[10] = "42";
		char dest[10] = "hello";
		char dest1[10] = "hello";
		char dest2[10] = "hi";
		char dest3[10] = "hi";
		printf("%lu %u\n", strlcat(dest, src, 3), ft_strlcat(dest1, src, 3));
		printf("%lu %u\n", strlcat(dest, src, 10), ft_strlcat(dest1, src, 10));
		printf("%lu %u\n", strlcat(dest2, src1, 5), ft_strlcat(dest3, src1, 5));
	}
}
