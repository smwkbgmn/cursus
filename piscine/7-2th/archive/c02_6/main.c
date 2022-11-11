#include <stdio.h>
#include <string.h>

#include "ex00/ft_strcpy.c"
#include "ex01/ft_strncpy.c"
#include "ex02/ft_str_is_alpha.c"
#include "ex03/ft_str_is_numeric.c"
#include "ex04/ft_str_is_lowercase.c"
#include "ex05/ft_str_is_uppercase.c"
#include "ex06/ft_str_is_printable.c"
#include "ex07/ft_strupcase.c"
#include "ex08/ft_strlowcase.c"
#include "ex09/ft_strcapitalize.c"
#include "ex10/ft_strlcpy.c"
#include "ex11/ft_putstr_non_printable.c"
//#include "ex11/ft_print_memory.c"

int main()
{
	{
		printf("======ex00======\n");
		char dest[6];
		char src1[3] = "hi";
		char src2[6] = "gaeon";
		printf("%s %s\n", strcpy(dest, src1), ft_strcpy(dest, src1));
		printf("%s %s\n", strcpy(dest, src2), ft_strcpy(dest, src2));
	}
	{
		printf("======ex01======\n");
		char dest[8];
		char src1[11] = "hi hello!";
		printf("%s %s\n", strncpy(dest, src1, 3), ft_strncpy(dest, src1, 3));
		printf("%s %s\n", strncpy(dest, src1, 8), ft_strncpy(dest, src1, 8));
	}
	{
		printf("======ex02======\n");
		char str1[10] = "abcdefh";
		char str2[10] = "abc12";
		char str3[10] = "123";
		char str4[10] = "";
		printf("1 : %d\n", ft_str_is_alpha(str1));
		printf("0 : %d\n", ft_str_is_alpha(str2));
		printf("0 : %d\n", ft_str_is_alpha(str3));
		printf("1 : %d\n", ft_str_is_alpha(str4));
	}
	{
		printf("======ex03======\n");
		char str1[10] = "abcdefh";
		char str2[10] = "abc12";
		char str3[10] = "123";
		char str4[10] = "";
		printf("0 : %d\n", ft_str_is_numeric(str1));
		printf("0 : %d\n", ft_str_is_numeric(str2));
		printf("1 : %d\n", ft_str_is_numeric(str3));
		printf("1 : %d\n", ft_str_is_numeric(str4));
	}
	{
		printf("======ex04======\n");
		char str1[10] = "abcdefh";
		char str2[10] = "aBcD";
		char str3[10] = "ABC";
		char str4[10] = "123";
		char str5[10] = "";
		printf("1 : %d\n", ft_str_is_lowercase(str1));
		printf("0 : %d\n", ft_str_is_lowercase(str2));
		printf("0 : %d\n", ft_str_is_lowercase(str3));
		printf("0 : %d\n", ft_str_is_lowercase(str4));
		printf("1 : %d\n", ft_str_is_lowercase(str5));
	}
	{
		printf("======ex05======\n");
		char str1[10] = "abcdefh";
		char str2[10] = "aBcD";
		char str3[10] = "ABC";
		char str4[10] = "123";
		char str5[10] = "";
		printf("0 : %d\n", ft_str_is_uppercase(str1));
		printf("0 : %d\n", ft_str_is_uppercase(str2));
		printf("1 : %d\n", ft_str_is_uppercase(str3));
		printf("0 : %d\n", ft_str_is_uppercase(str4));
		printf("1 : %d\n", ft_str_is_uppercase(str5));
	}
	{
		printf("======ex06======\n");
		char c1 = 20;
		char c2 = 127;
		char str1[10] = "abcdefh";
		char str2[10] = "";
		printf("0 : %d\n", ft_str_is_printable(&c1));
		printf("0 : %d\n", ft_str_is_printable(&c2));
		printf("1 : %d\n", ft_str_is_printable(str1));
		printf("1 : %d\n", ft_str_is_printable(str2));
	}
	{
		printf("======ex07======\n");
		char str1[10] = "abcdefg";
		char str2[10] = "ABCDEFG";
		char str3[30] = "HEllO hi 123";
		printf("%s\n", ft_strupcase(str1));
		printf("%s\n", ft_strupcase(str2));
		printf("%s\n", ft_strupcase(str3));
	}
	{
		printf("======ex08======\n");
		char str1[10] = "abcdefg";
		char str2[10] = "ABCDEFG";
		char str3[30] = "HEllO hi 123";
		printf("%s\n",ft_strlowcase(str1));
		printf("%s\n",ft_strlowcase(str2));
		printf("%s\n",ft_strlowcase(str3));
	}
	{
		printf("======ex09======\n");
		char str1[100] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
		char str2[100] = "abc, def Gh iJk : abcd deEf";
		printf("%s\n", ft_strcapitalize(str1));
		printf("%s\n", ft_strcapitalize(str2));
	}
	{
		printf("======ex10======\n");
		char src1[30] = "HEllO hi 123";
		char dest1[30] = ""; char dest2[30] = "";
		printf("%lu\n", strlcpy(dest1, src1, 5));
		printf("%u\n", ft_strlcpy(dest2, src1, 5));
	}
	{
		printf("======ex11======\n");
		char str[10] = "abcdef ? ";
		char str1[30] = "Coucou\ntu vas bien ?";
		ft_putstr_non_printable(str);
		printf("\n");
		ft_putstr_non_printable(str1);
		printf("\n");
	}
	return (0);
}