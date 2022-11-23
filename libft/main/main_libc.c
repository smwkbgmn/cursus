#include "main.h"
// #include "libft.h"

#define FILLN(which, n) \
{ \
	size_t idx = 0; \
	while (idx < n) \
	{ \
		int_##which[idx] = idx; \
		idx++; \
	} \
}

#define PRINTF(type, which, n) \
{ \
	size_t idx = 0; \
	while (idx < n) \
	{ \
		if (type == 0) \
			printf("[%d]", int_##which[idx++]); \
		else \
			printf("[%c]", char_##which[idx++]); \
	} \
	printf("\n"); \
}

int main(void)
{
	// isalpha
	printf("\n[isalpha]\n\n");

	char letter;
	char letter_ft;

	letter = '\0';
	printf("letter (\\0)\t[%d][%d]\n", isalpha(letter), ft_isalpha(letter));
	letter = '\40';
	printf("letter (%c)\t[%d][%d]\n", letter, isalpha(letter), ft_isalpha(letter));
	letter = '5';
	printf("letter (%c)\t[%d][%d]\n", letter, isalpha(letter), ft_isalpha(letter));
	letter = 'g';
	printf("letter (%c)\t[%d][%d]\n", letter, isalpha(letter), ft_isalpha(letter));
	letter = 'A';
	printf("letter (%c)\t[%d][%d]\n", letter, isalpha(letter), ft_isalpha(letter));
	letter = '\176';
	printf("letter (\\176)\t[%d][%d]\n", isalpha(letter), ft_isalpha(letter));
	letter = '\177';
	printf("letter (\\177)\t[%d][%d]\n", isalpha(letter), ft_isalpha(letter));
	letter = '\377';
	printf("letter (\\377)\t[%d][%d]\n", isalpha(letter), ft_isalpha(letter));
	printf("letter (-1)\t[%d][%d]\n", isalpha(-1), ft_isalpha(-1));
	
	printf("\n------------------------------------------------\n");

	// isdigit
	printf("\n[isdigit]\n\n");

	letter = '\0';
	printf("letter (\\0)\t[%d][%d]\n", isdigit(letter), ft_isdigit(letter));
	letter = '\40';
	printf("letter (%c)\t[%d][%d]\n", letter, isdigit(letter), ft_isdigit(letter));
	letter = '0';
	printf("letter (%c)\t[%d][%d]\n", letter, isdigit(letter), ft_isdigit(letter));
	letter = '5';
	printf("letter (%c)\t[%d][%d]\n", letter, isdigit(letter), ft_isdigit(letter));
	letter = '9';
	printf("letter (%c)\t[%d][%d]\n", letter, isdigit(letter), ft_isdigit(letter));
	letter = 'g';
	printf("letter (%c)\t[%d][%d]\n", letter, isdigit(letter), ft_isdigit(letter));
	letter = 'A';
	printf("letter (%c)\t[%d][%d]\n", letter, isdigit(letter), ft_isdigit(letter));
	letter = '\176';
	printf("letter (\\176)\t[%d][%d]\n", isdigit(letter), ft_isdigit(letter));
	letter = '\177';
	printf("letter (\\177)\t[%d][%d]\n", isdigit(letter), ft_isdigit(letter));
	letter = '\377';
	printf("letter (\\377)\t[%d][%d]\n", isdigit(letter), ft_isdigit(letter));

	printf("\n------------------------------------------------\n");

	// isalnum
	printf("\n[isalnum]\n\n");

	letter = '\0';
	printf("letter (\\0)\t[%d][%d]\n", isalnum(letter), ft_isalnum(letter));
	letter = '\40';
	printf("letter (%c)\t[%d][%d]\n", letter, isalnum(letter), ft_isalnum(letter));
	letter = '5';
	printf("letter (%c)\t[%d][%d]\n", letter, isalnum(letter), ft_isalnum(letter));
	letter = 'g';
	printf("letter (%c)\t[%d][%d]\n", letter, isalnum(letter), ft_isalnum(letter));
	letter = 'A';
	printf("letter (%c)\t[%d][%d]\n", letter, isalnum(letter), ft_isalnum(letter));
	letter = '\176';
	printf("letter (\\176)\t[%d][%d]\n", isalnum(letter), ft_isalnum(letter));
	letter = '\177';
	printf("letter (\\177)\t[%d][%d]\n", isalnum(letter), ft_isalnum(letter));
	letter = '\377';
	printf("letter (\\377)\t[%d][%d]\n", isalnum(letter), ft_isalnum(letter));
	
	printf("\n------------------------------------------------\n");

	// isascii
	printf("\n[isascii]\n\n");

	letter = '\0';
	printf("letter (\\0)\t[%d][%d]\n", isascii(letter), ft_isascii(letter));
	letter = '\40';
	printf("letter (%c)\t[%d][%d]\n", letter, isascii(letter), ft_isascii(letter));
	letter = '5';
	printf("letter (%c)\t[%d][%d]\n", letter, isascii(letter), ft_isascii(letter));
	letter = 'g';
	printf("letter (%c)\t[%d][%d]\n", letter, isascii(letter), ft_isascii(letter));
	letter = 'A';
	printf("letter (%c)\t[%d][%d]\n", letter, isascii(letter), ft_isascii(letter));
	letter = '\176';
	printf("letter (\\176)\t[%d][%d]\n", isascii(letter), ft_isascii(letter));
	letter = '\177';
	printf("letter (\\177)\t[%d][%d]\n", isascii(letter), ft_isascii(letter));
	letter = '\377';
	printf("letter (\\377)\t[%d][%d]\n", isascii(letter), ft_isascii(letter));
	
	printf("\n------------------------------------------------\n");

	// isprint
	printf("\n[isprint]\n\n");

	letter = '\0';
	printf("letter (\\0)\t[%d][%d]\n", isprint(letter), ft_isprint(letter));
	letter = '\40';
	printf("letter (%c)\t[%d][%d]\n", letter, isprint(letter), ft_isprint(letter));
	letter = '5';
	printf("letter (%c)\t[%d][%d]\n", letter, isprint(letter), ft_isprint(letter));
	letter = 'g';
	printf("letter (%c)\t[%d][%d]\n", letter, isprint(letter), ft_isprint(letter));
	letter = 'A';
	printf("letter (%c)\t[%d][%d]\n", letter, isprint(letter), ft_isprint(letter));
	letter = '\176';
	printf("letter (\\176)\t[%d][%d]\n", isprint(letter), ft_isprint(letter));
	letter = '\177';
	printf("letter (\\177)\t[%d][%d]\n", isprint(letter), ft_isprint(letter));
	letter = '\377';
	printf("letter (\\377)\t[%d][%d]\n", isprint(letter), ft_isprint(letter));
	
	printf("\n------------------------------------------------\n");

	// toupper
	printf("\n[toupper]\n\n");

	letter = letter_ft = '\0';
	printf("letter (\\0)\t[%c][%c]\n", toupper(letter), ft_toupper(letter_ft));
	letter = letter_ft = '\40';
	printf("letter (%c)\t[%c][%c]\n", letter, toupper(letter), ft_toupper(letter_ft));
	letter = letter_ft = '5';
	printf("letter (%c)\t[%c][%c]\n", letter, toupper(letter), ft_toupper(letter_ft));
	letter = letter_ft = 'g';
	printf("letter (%c)\t[%c][%c]\n", letter, toupper(letter), ft_toupper(letter_ft));
	letter = letter_ft = 'A';
	printf("letter (%c)\t[%c][%c]\n", letter, toupper(letter), ft_toupper(letter_ft));
	letter = letter_ft = '\177';
	printf("letter (\\177)\t[%c][%c]\n", toupper(letter), ft_toupper(letter_ft));
	letter = letter_ft = '\377';
	printf("letter (\\377)\t[%c][%c]\n", toupper(letter), ft_toupper(letter_ft));



	printf("\n------------------------------------------------\n");

	// tolower
	printf("\n[tolower]\n\n");

	letter = letter_ft = '\0';
	printf("letter (\\0)\t[%c][%c]\n", tolower(letter), ft_tolower(letter_ft));
	letter = letter_ft = '\40';
	printf("letter (%c)\t[%c][%c]\n", letter, tolower(letter), ft_tolower(letter_ft));
	letter = letter_ft = '5';
	printf("letter (%c)\t[%c][%c]\n", letter, tolower(letter), ft_tolower(letter_ft));
	letter = letter_ft = 'g';
	printf("letter (%c)\t[%c][%c]\n", letter, tolower(letter), ft_tolower(letter_ft));
	letter = letter_ft = 'A';
	printf("letter (%c)\t[%c][%c]\n", letter, tolower(letter), ft_tolower(letter_ft));
	letter = letter_ft = '\177';
	printf("letter (\\177)\t[%c][%c]\n", tolower(letter), ft_tolower(letter_ft));
	letter = letter_ft = '\377';
	printf("letter (\\377)\t[%c][%c]\n", tolower(letter), ft_tolower(letter_ft));


	printf("\n------------------------------------------------\n");

	// bzero
	printf("\n[bzero]\n\n");

	int int_origin[20] = {0, 1, 2, 3, 4};
	int int_ft[20]   = {0, 1, 2, 3, 4};
	char char_origin[20] = "01234";
	char char_ft[20] = "01234";
	
	size_t len;

	len = 5;

	printf("input int\t");
	PRINTF(0, origin, 5);
	printf("input char\t");
	PRINTF(1, origin, 5);
	printf("input len\t[%zu]\n", len);

	bzero(int_origin, len);
	ft_bzero(int_ft, len);

	printf("\noutput ary_int\n");
	printf("origin\t\t");
	PRINTF(0, origin, len);
	printf("ft\t\t");
	PRINTF(0, ft, len);

	bzero(char_origin, len);
	ft_bzero(char_ft, len);

	printf("\noutput ary_char\n");
	printf("origin\t\t");
	PRINTF(1, origin, len);
	printf("ft\t\t");
	PRINTF(1, ft, len);

	printf("\n------------------------------------------------\n");

	// memset
	printf("\n[memset]\n\n");

	int c;

	FILLN(origin, 5);
	FILLN(ft, 5);
	strcpy(char_origin, "uvxyz");
	strcpy(char_ft, "uvxyz");

	printf("input int\t\t");
	PRINTF(0, origin, 5);
	printf("input char\t\t");
	PRINTF(1, origin, 5);
	printf("\n");


	c = 'a';
	len = 1;
	memset(int_origin, c, len);
	ft_memset(int_ft, c, len);
	memset(char_origin, c, len);
	ft_memset(char_ft, c, len);

	printf("int origin (%c, %zu)\t", c, len);
	PRINTF(0, origin, 5);
	printf("int ft (%c, %zu)\t\t", c, len);
	PRINTF(0, ft, 5);
	printf("char origin (%c, %zu)\t", c, len);
	PRINTF(1, origin, 5);
	printf("char ft (%c, %zu)\t\t", c, len);
	PRINTF(1, ft, 5);
	printf("\n");


	len = 3;
	memset(int_origin, c, len);
	ft_memset(int_ft, c, len);
	memset(char_origin, c, len);
	ft_memset(char_ft, c, len);

	printf("int origin (%c, %zu)\t", c, len);
	PRINTF(0, origin, 5);
	printf("int ft (%c, %zu)\t\t", c, len);
	PRINTF(0, ft, 5);
	printf("char origin (%c, %zu)\t", c, len);
	PRINTF(1, origin, 5);
	printf("char ft (%c, %zu)\t\t", c, len);
	PRINTF(1, ft, 5);
	printf("\n");


	len = 5;
	memset(int_origin, c, len);
	ft_memset(int_ft, c, len);
	memset(char_origin, c, len);
	ft_memset(char_ft, c, len);

	printf("int origin (%c, %zu)\t", c, len);
	PRINTF(0, origin, 5);
	printf("int ft (%c, %zu)\t\t", c, len);
	PRINTF(0, ft, 5);
	printf("char origin (%c, %zu)\t", c, len);
	PRINTF(1, origin, 5);
	printf("char ft (%c, %zu)\t\t", c, len);
	PRINTF(1, ft, 5);
	printf("\n");


	len = 6;
	memset(int_origin, c, len);
	ft_memset(int_ft, c, len);
	memset(char_origin, c, len);
	ft_memset(char_ft, c, len);

	printf("int origin (%c, %zu)\t", c, len);
	PRINTF(0, origin, 5);
	printf("int ft (%c, %zu)\t\t", c, len);
	PRINTF(0, ft, 5);
	printf("char origin (%c, %zu)\t", c, len);
	PRINTF(1, origin, 5);
	printf("char ft (%c, %zu)\t\t", c, len);
	PRINTF(1, ft, 5);
	printf("\n");



	printf("\n------------------------------------------------\n");

	// memcpy
	printf("\n[memcpy]\n\n");

	char s1[100] = "learningisfun";
	char s2[100] = "learningisfun";
	char *st1, *st2;

	st1 = s1;
	st2 = s2; 

	printf ("before origin\t[%s]\n", st1);
	printf ("before ft\t[%s]\n\n", st2);

	memcpy(st1 + 8, st1, 10);
	ft_memcpy(st2 + 8, st2, 10);

	printf ("after origin\t[%s]\n", st1);
	printf ("after ft\t[%s]\n", st2);

	printf("\n------------------------------------------------\n");

	// memmove
	printf("\n[memmove]\n\n");
	
	strcpy(s1, "learningisfun");
	strcpy(s2, "learningisfun");

	printf ("before origin\t[%s]\n", st1);
	printf ("before ft\t[%s]\n\n", st2);

	memmove(st1 + 8, st1 + 0, 10);
	ft_memmove(st2 + 8, st2 + 0, 10);

	printf ("after origin\t[%s]\n", st1);
	printf ("after ft\t[%s]\n", st2);

	printf("\n------------------------------------------------\n");

	// memcmp
	printf("\n[memcmp]\n\n");

	char s3[50] = "learning";
	char s4[50] = "a";
	char s5[50] = "";
	char s6[50] = "le";
	
	strcpy(s1, "lear");
	strcpy(s2, "lear");

	printf("str1 vs str2 (length)\t[origin][ft]\n\n");
	printf("%s vs %s (3)\t[%d][%d]\n", s1, s2, memcmp(s1, s2, 3), ft_memcmp(s1, s2, 3));
	printf("%s vs %s (4)\t[%d][%d]\n", s1, s2, memcmp(s1, s2, 4), ft_memcmp(s1, s2, 4));
	printf("%s vs %s (5)\t[%d][%d]\n", s1, s2, memcmp(s1, s2, 5), ft_memcmp(s1, s2, 5));
	printf("%s vs %s (6)\t[%d][%d]\n", s1, s2, memcmp(s1, s2, 6), ft_memcmp(s1, s2, 6));
	printf("%s vs %s (100)\t[%d][%d]\n", s1, s2, memcmp(s1, s2, 100), ft_memcmp(s1, s2, 100));

	printf("\n");

	printf("%s vs %s (1)\t\t[%d][%d]\n", s1, s6, memcmp(s1, s6, 1), ft_memcmp(s1, s6, 1));
	printf("%s vs %s (2)\t\t[%d][%d]\n", s1, s6, memcmp(s1, s6, 2), ft_memcmp(s1, s6, 2));
	printf("%s vs %s (3)\t\t[%d][%d]\n", s1, s6, memcmp(s1, s6, 3), ft_memcmp(s1, s6, 3));
	printf("%s vs %s (4)\t\t[%d][%d]\n", s1, s6, memcmp(s1, s6, 4), ft_memcmp(s1, s6, 4));

	printf("\n");

	printf("%s vs %s (4)\t[%d][%d]\n", s1, s3, memcmp(s1, s3, 4), ft_memcmp(s1, s3, 4));
	printf("%s vs %s (5)\t[%d][%d]\n", s1, s3, memcmp(s1, s3, 5), ft_memcmp(s1, s3, 5));
	printf("%s vs %s (6)\t[%d][%d]\n", s1, s3, memcmp(s1, s3, 6), ft_memcmp(s1, s3, 6));

	printf("\n");

	printf("%s vs %s (0)\t\t[%d][%d]\n", s1, s4, memcmp(s1, s4, 0), ft_memcmp(s1, s4, 0));
	printf("%s vs %s (1)\t\t[%d][%d]\n", s1, s4, memcmp(s1, s4, 1), ft_memcmp(s1, s4, 1));
	printf("%s vs %s (2)\t\t[%d][%d]\n", s1, s4, memcmp(s1, s4, 2), ft_memcmp(s1, s4, 2));
	printf("%s vs %s (3)\t\t[%d][%d]\n", s1, s4, memcmp(s1, s4, 3), ft_memcmp(s1, s4, 3));

	printf("\n");

	printf("%s vs null (0)\t[%d][%d]\n", s1, memcmp(s1, s5, 0), ft_memcmp(s1, s5, 0));
	printf("%s vs null (1)\t[%d][%d]\n", s1, memcmp(s1, s5, 1), ft_memcmp(s1, s5, 1));
	printf("%s vs null (2)\t[%d][%d]\n", s1, memcmp(s1, s5, 2), ft_memcmp(s1, s5, 2));

	printf("\n");

	printf("null vs null (0)\t[%d][%d]\n", memcmp(s5, s5, 0), ft_memcmp(s5, s5, 0));
	printf("null vs null (1)\t[%d][%d]\n", memcmp(s5, s5, 1), ft_memcmp(s5, s5, 1));
	printf("null vs null (2)\t[%d][%d]\n", memcmp(s5, s5, 2), ft_memcmp(s5, s5, 2));

	printf("\n------------------------------------------------\n");

	// memchr
	printf("\n[memchr]\n\n");

	size_t nn;
	
	strcpy(s1, "aabcde");
	strcpy(s2, "abccde");
	strcpy(s3, "abcdee");
	strcpy(s4, "\0");

	nn = 0;
	printf("n = %zu\n", nn);
	printf("\"%s\" (%c)\t\t[%s]\t[%s]\n", s1, 'a', (char *)memchr(s1, 'a', nn), (char *)ft_memchr(s1, 'a', nn));
	printf("\"%s\" (%c)\t\t[%s]\t[%s]\n", s2, 'c', (char *)memchr(s2, 'c', nn), (char *)ft_memchr(s2, 'c', nn));
	printf("\"%s\" (%c)\t\t[%s]\t[%s]\n", s3, 'e', (char *)memchr(s3, 'e', nn), (char *)ft_memchr(s3, 'e', nn));
	printf("\"%s\" (%c)\t\t[%s]\t[%s]\n", s3, 'z', (char *)memchr(s3, 'z', nn), (char *)ft_memchr(s3, 'z', nn));
	printf("\"%s\" (null)\t\t[%s]\t[%s]\n", s3, (char *)memchr(s3, '\0', nn), (char *)ft_memchr(s3, '\0', nn));
	printf("empty string (%c)\t[%s]\t[%s]\n", 'a', (char *)memchr(s4, 'a', nn), (char *)ft_memchr(s4, 'a', nn));
	printf("empty string (null)\t[%s]\t[%s]\n", (char *)memchr(s4, '\0', nn), (char *)ft_memchr(s4, '\0', nn));
	printf("\n");

	nn = 3;
	printf("n = %zu\n", nn);
	printf("\"%s\" (%c)\t\t[%s]\t[%s]\n", s1, 'a', (char *)memchr(s1, 'a', nn), (char *)ft_memchr(s1, 'a', nn));
	printf("\"%s\" (%c)\t\t[%s]\t\t[%s]\n", s2, 'c', (char *)memchr(s2, 'c', nn), (char *)ft_memchr(s2, 'c', nn));
	printf("\"%s\" (%c)\t\t[%s]\t[%s]\n", s3, 'e', (char *)memchr(s3, 'e', nn), (char *)ft_memchr(s3, 'e', nn));
	printf("\"%s\" (%c)\t\t[%s]\t[%s]\n", s3, 'z', (char *)memchr(s3, 'z', nn), (char *)ft_memchr(s3, 'z', nn));
	printf("\"%s\" (null)\t\t[%s]\t[%s]\n", s3, (char *)memchr(s3, '\0', nn), (char *)ft_memchr(s3, '\0', nn));
	printf("empty string (%c)\t[%s]\t[%s]\n", 'a', (char *)memchr(s4, 'a', nn), (char *)ft_memchr(s4, 'a', nn));
	printf("empty string (null)\t[%s]\t\t[%s]\n", (char *)memchr(s4, '\0', nn), (char *)ft_memchr(s4, '\0', nn));
	printf("\n");

	nn = 5;
	printf("n = %zu\n", nn);
	printf("\"%s\" (%c)\t\t[%s]\t[%s]\n", s1, 'a', (char *)memchr(s1, 'a', nn), (char *)ft_memchr(s1, 'a', nn));
	printf("\"%s\" (%c)\t\t[%s]\t\t[%s]\n", s2, 'c', (char *)memchr(s2, 'c', nn), (char *)ft_memchr(s2, 'c', nn));
	printf("\"%s\" (%c)\t\t[%s]\t\t[%s]\n", s3, 'e', (char *)memchr(s3, 'e', nn), (char *)ft_memchr(s3, 'e', nn));
	printf("\"%s\" (%c)\t\t[%s]\t[%s]\n", s3, 'z', (char *)memchr(s3, 'z', nn), (char *)ft_memchr(s3, 'z', nn));
	printf("\"%s\" (null)\t\t[%s]\t[%s]\n", s3, (char *)memchr(s3, '\0', nn), (char *)ft_memchr(s3, '\0', nn));
	printf("empty string (%c)\t[%s]\t[%s]\n", 'a', (char *)memchr(s4, 'a', nn), (char *)ft_memchr(s4, 'a', nn));
	printf("empty string (null)\t[%s]\t\t[%s]\n", (char *)memchr(s4, '\0', nn), (char *)ft_memchr(s4, '\0', nn));
	printf("\n");

	nn = 6;
	printf("n = %zu\n", nn);
	printf("\"%s\" (%c)\t\t[%s]\t[%s]\n", s1, 'a', (char *)memchr(s1, 'a', nn), (char *)ft_memchr(s1, 'a', nn));
	printf("\"%s\" (%c)\t\t[%s]\t\t[%s]\n", s2, 'c', (char *)memchr(s2, 'c', nn), (char *)ft_memchr(s2, 'c', nn));
	printf("\"%s\" (%c)\t\t[%s]\t\t[%s]\n", s3, 'e', (char *)memchr(s3, 'e', nn), (char *)ft_memchr(s3, 'e', nn));
	printf("\"%s\" (%c)\t\t[%s]\t[%s]\n", s3, 'z', (char *)memchr(s3, 'z', nn), (char *)ft_memchr(s3, 'z', nn));
	printf("\"%s\" (null)\t\t[%s]\t[%s]\n", s3, (char *)memchr(s3, '\0', nn), (char *)ft_memchr(s3, '\0', nn));
	printf("empty string (%c)\t[%s]\t[%s]\n", 'a', (char *)memchr(s4, 'a', nn), (char *)ft_memchr(s4, 'a', nn));
	printf("empty string (null)\t[%s]\t\t[%s]\n", (char *)memchr(s4, '\0', nn), (char *)ft_memchr(s4, '\0', nn));
	printf("\n");

	nn = 7;
	printf("n = %zu\n", nn);
	printf("\"%s\" (%c)\t\t[%s]\t[%s]\n", s1, 'a', (char *)memchr(s1, 'a', nn), (char *)ft_memchr(s1, 'a', nn));
	printf("\"%s\" (%c)\t\t[%s]\t\t[%s]\n", s2, 'c', (char *)memchr(s2, 'c', nn), (char *)ft_memchr(s2, 'c', nn));
	printf("\"%s\" (%c)\t\t[%s]\t\t[%s]\n", s3, 'e', (char *)memchr(s3, 'e', nn), (char *)ft_memchr(s3, 'e', nn));
	printf("\"%s\" (%c)\t\t[%s]\t[%s]\n", s3, 'z', (char *)memchr(s3, 'z', nn), (char *)ft_memchr(s3, 'z', nn));
	printf("\"%s\" (null)\t\t[%s]\t\t[%s]\n", s3, (char *)memchr(s3, '\0', nn), (char *)ft_memchr(s3, '\0', nn));
	printf("empty string (%c)\t[%s]\t[%s]\n", 'a', (char *)memchr(s4, 'a', nn), (char *)ft_memchr(s4, 'a', nn));
	printf("empty string (null)\t[%s]\t\t[%s]\n", (char *)memchr(s4, '\0', nn), (char *)ft_memchr(s4, '\0', nn));

	strcpy(s1, "\0\1\2\3\4\5");

	printf("\n");
	printf("\"%s\" (%c)\t\t[%s]\t\t[%s]\n", s1, '\2', (char *)memchr(s2, 2, 3), (char *)ft_memchr(s2, 2, 3));
	printf("\"%s\" (%c)\t\t[%s]\t\t[%s]\n", s1, '\2', (char *)memchr(s2, 2 + 256, 3), (char *)ft_memchr(s2, 2 + 256, 3));


	printf("\n------------------------------------------------\n");

	// strlcpy
	printf("\n[strlcpy]\n\n");

	char src[10] = "source";
	char src_null[10] = "";

	char dst1[10];
	char dst2[10];
	char dst3[10];
	char dst4[10];
	char dst9[10];
	// char dst11[10] = "AAAAAAAAAA";

	printf("src string\t[%s]\n\n", src);
	
	printf("origin (%d)\t[%lu][%s]\n", 0, strlcpy(dst1, src, 0), dst1);
	printf("origin (%d)\t[%lu][%s]\n", 6, strlcpy(dst2, src, 6), dst2);
	printf("origin (%d)\t[%lu][%s]\n", 7, strlcpy(dst3, src, 7), dst3);
	printf("origin (%d)\t[%lu][%s]\n", 8, strlcpy(dst4, src, 8), dst4);
	printf("origin (%d)\t[%lu][%s]\n", 3, strlcpy(dst9, src_null, 3), dst9);
	// printf("origin (%d)\t[%lu][%s]\n", 42, strlcpy(dst11, src_null, 42), dst11);

	printf("\n");

	char dst5[10];
	char dst6[10];
	char dst7[10];
	char dst8[10];
	char dst10[10];
	// char dst12[10] = "AAAAAAAAAA";

	printf("ft (%d)\t\t[%lu][%s]\n", 0, ft_strlcpy(dst5, src, 0), dst5);
	printf("ft (%d)\t\t[%lu][%s]\n", 6, ft_strlcpy(dst6, src, 6), dst6);
	printf("ft (%d)\t\t[%lu][%s]\n", 7, ft_strlcpy(dst7, src, 7), dst7);
	printf("ft (%d)\t\t[%lu][%s]\n", 8, ft_strlcpy(dst8, src, 8), dst8);
	printf("ft (%d)\t\t[%lu][%s]\n", 3, ft_strlcpy(dst10, src_null, 3), dst10);
	// printf("ft (%d)\t\t[%lu][%s]\n", 42, ft_strlcpy(dst12, "", 42), dst12);

	printf("\n------------------------------------------------\n");

	// strlcat
	printf("\n[strlcat]\n\n");

	char dst[50] = "dest";
	char dst_null[10] = "";
	char dst_lack_size[2] = "";

	printf("dest string\t[%s]\n", dst);
	printf("source string\t[%s]\n\n", src);

	printf("origin (%d)\t[%lu][%s]\n", 0, strlcat(dst, src, 0), dst);
	strcpy(dst, "dest"); 
	printf("origin (%d)\t[%lu][%s]\n", 3, strlcat(dst, src, 3), dst);
	strcpy(dst, "dest"); 
	printf("origin (%d)\t[%lu][%s]\n", 4, strlcat(dst, src, 4), dst);
	strcpy(dst, "dest"); 
	printf("origin (%d)\t[%lu][%s]\n", 5, strlcat(dst, src, 5), dst);
	strcpy(dst, "dest"); 
	printf("origin (%d)\t[%lu][%s]\n", 6, strlcat(dst, src, 6), dst);
	strcpy(dst, "dest"); 
	printf("origin (%d)\t[%lu][%s]\n", 7, strlcat(dst, src, 7), dst);
	strcpy(dst, "dest"); 
	printf("origin (%d)\t[%lu][%s]\n", 12, strlcat(dst, src, 12), dst);
	strcpy(dst, "dest"); 
	printf("origin (%d)\t[%lu][%s]\n\n", 13, strlcat(dst, src, 13), dst);
	strcpy(dst, "dest");

	printf("origin_null_src (%d)\t\t[%lu][%s]\n", 7, strlcat(dst, src_null, 7), dst);
	strcpy(dst, "dest");
	printf("origin_null_dst (%d)\t\t[%lu][%s]\n", 7, strlcat(dst_null, src, 7), dst_null);
	strcpy(dst_null, "");
	printf("origin_lack_size_of_dst (%d)\t[%lu][%s]\n", 1, strlcat(dst_lack_size, src, 1), dst_lack_size);
	strcpy(dst_lack_size, "");
	printf("origin_lack_size_of_dst (%d)\t[%lu][%s]\n", 2, strlcat(dst_lack_size, src, 2), dst_lack_size);
	strcpy(dst_lack_size, "");
	
	printf("\n");

	printf("ft (%d)\t\t[%lu][%s]\n", 0, ft_strlcat(dst, src, 0), dst);
	strcpy(dst, "dest"); 
	printf("ft (%d)\t\t[%lu][%s]\n", 3, ft_strlcat(dst, src, 3), dst);
	strcpy(dst, "dest"); 
	printf("ft (%d)\t\t[%lu][%s]\n", 4, ft_strlcat(dst, src, 4), dst);
	strcpy(dst, "dest"); 
	printf("ft (%d)\t\t[%lu][%s]\n", 5, ft_strlcat(dst, src, 5), dst);
	strcpy(dst, "dest"); 
	printf("ft (%d)\t\t[%lu][%s]\n", 6, ft_strlcat(dst, src, 6), dst);
	strcpy(dst, "dest"); 
	printf("ft (%d)\t\t[%lu][%s]\n", 7, ft_strlcat(dst, src, 7), dst);
	strcpy(dst, "dest"); 
	printf("ft (%d)\t\t[%lu][%s]\n", 12, ft_strlcat(dst, src, 12), dst);
	strcpy(dst, "dest"); 
	printf("ft (%d)\t\t[%lu][%s]\n\n", 13, ft_strlcat(dst, src, 13), dst);
	strcpy(dst, "dest");

	printf("ft_null_src (%d)\t\t\t[%lu][%s]\n", 7, ft_strlcat(dst, src_null, 7), dst);
	strcpy(dst, "dest");
	printf("ft_null_dst (%d)\t\t\t[%lu][%s]\n", 7, ft_strlcat(dst_null, src, 7), dst_null);
	strcpy(dst_null, "");
	printf("ft_lack_size_of_dst (%d)\t\t[%lu][%s]\n", 1, ft_strlcat(dst_lack_size, src, 1), dst_lack_size);
	strcpy(dst_lack_size, "");
	printf("ft_lack_size_of_dst (%d)\t\t[%lu][%s]\n", 2, ft_strlcat(dst_lack_size, src, 2), dst_lack_size);
	strcpy(dst_lack_size, "");


	printf("\n------------------------------------------------\n");

	// strncmp
	printf("\n[strncmp]\n\n");

	char cmp1[30];
	char cmp2[30];
	size_t n;
	int rslt_origin;
	int rslt_ft;

	strcpy(cmp1, "abcde");
	strcpy(cmp2, "abcde");

	n = 0;
	rslt_origin = strncmp(cmp1, cmp2, n);
	rslt_ft = ft_strncmp(cmp1, cmp2, n);
	printf("%s vs %s (%zu)\t[%d][%d]\n", cmp1, cmp2, n, rslt_origin, rslt_ft);

	n = 1;
	rslt_origin = strncmp(cmp1, cmp2, n);
	rslt_ft = ft_strncmp(cmp1, cmp2, n);
	printf("%s vs %s (%zu)\t[%d][%d]\n", cmp1, cmp2, n, rslt_origin, rslt_ft);

	n = 5;
	rslt_origin = strncmp(cmp1, cmp2, n);
	rslt_ft = ft_strncmp(cmp1, cmp2, n);
	printf("%s vs %s (%zu)\t[%d][%d]\n", cmp1, cmp2, n, rslt_origin, rslt_ft);

	n = 6;
	rslt_origin = strncmp(cmp1, cmp2, n);
	rslt_ft = ft_strncmp(cmp1, cmp2, n);
	printf("%s vs %s (%zu)\t[%d][%d]\n", cmp1, cmp2, n, rslt_origin, rslt_ft);
	
	n = 7;
	rslt_origin = strncmp(cmp1, cmp2, n);
	rslt_ft = ft_strncmp(cmp1, cmp2, n);
	printf("%s vs %s (%zu)\t[%d][%d]\n\n", cmp1, cmp2, n, rslt_origin, rslt_ft);

	strcpy(cmp2, "abcdefg");

	n = 0;
	rslt_origin = strncmp(cmp1, cmp2, n);
	rslt_ft = ft_strncmp(cmp1, cmp2, n);
	printf("%s vs %s (%zu)\t[%d][%d]\n", cmp1, cmp2, n, rslt_origin, rslt_ft);

	n = 1;
	rslt_origin = strncmp(cmp1, cmp2, n);
	rslt_ft = ft_strncmp(cmp1, cmp2, n);
	printf("%s vs %s (%zu)\t[%d][%d]\n", cmp1, cmp2, n, rslt_origin, rslt_ft);

	n = 5;
	rslt_origin = strncmp(cmp1, cmp2, n);
	rslt_ft = ft_strncmp(cmp1, cmp2, n);
	printf("%s vs %s (%zu)\t[%d][%d]\n", cmp1, cmp2, n, rslt_origin, rslt_ft);

	n = 6;
	rslt_origin = strncmp(cmp1, cmp2, n);
	rslt_ft = ft_strncmp(cmp1, cmp2, n);
	printf("%s vs %s (%zu)\t[%d][%d]\n", cmp1, cmp2, n, rslt_origin, rslt_ft);
	
	n = 7;
	rslt_origin = strncmp(cmp1, cmp2, n);
	rslt_ft = ft_strncmp(cmp1, cmp2, n);
	printf("%s vs %s (%zu)\t[%d][%d]\n\n", cmp1, cmp2, n, rslt_origin, rslt_ft);
	
	strcpy(cmp2, "abc");

	n = 0;
	rslt_origin = strncmp(cmp1, cmp2, n);
	rslt_ft = ft_strncmp(cmp1, cmp2, n);
	printf("%s vs %s (%zu)\t[%d][%d]\n", cmp1, cmp2, n, rslt_origin, rslt_ft);

	n = 1;
	rslt_origin = strncmp(cmp1, cmp2, n);
	rslt_ft = ft_strncmp(cmp1, cmp2, n);
	printf("%s vs %s (%zu)\t[%d][%d]\n", cmp1, cmp2, n, rslt_origin, rslt_ft);

	n = 5;
	rslt_origin = strncmp(cmp1, cmp2, n);
	rslt_ft = ft_strncmp(cmp1, cmp2, n);
	printf("%s vs %s (%zu)\t[%d][%d]\n", cmp1, cmp2, n, rslt_origin, rslt_ft);

	n = 6;
	rslt_origin = strncmp(cmp1, cmp2, n);
	rslt_ft = ft_strncmp(cmp1, cmp2, n);
	printf("%s vs %s (%zu)\t[%d][%d]\n", cmp1, cmp2, n, rslt_origin, rslt_ft);
	
	n = 7;
	rslt_origin = strncmp(cmp1, cmp2, n);
	rslt_ft = ft_strncmp(cmp1, cmp2, n);
	printf("%s vs %s (%zu)\t[%d][%d]\n\n", cmp1, cmp2, n, rslt_origin, rslt_ft);

	strcpy(cmp2, "\0");

	n = 0;
	rslt_origin = strncmp(cmp1, cmp2, n);
	rslt_ft = ft_strncmp(cmp1, cmp2, n);
	printf("%s vs (null) (%zu)\t[%d][%d]\n", cmp1, n, rslt_origin, rslt_ft);

	n = 1;
	rslt_origin = strncmp(cmp1, cmp2, n);
	rslt_ft = ft_strncmp(cmp1, cmp2, n);
	printf("%s vs (null) (%zu)\t[%d][%d]\n", cmp1, n, rslt_origin, rslt_ft);

	n = 5;
	rslt_origin = strncmp(cmp1, cmp2, n);
	rslt_ft = ft_strncmp(cmp1, cmp2, n);
	printf("%s vs (null) (%zu)\t[%d][%d]\n", cmp1, n, rslt_origin, rslt_ft);

	n = 6;
	rslt_origin = strncmp(cmp1, cmp2, n);
	rslt_ft = ft_strncmp(cmp1, cmp2, n);
	printf("%s vs (null) (%zu)\t[%d][%d]\n", cmp1, n, rslt_origin, rslt_ft);
	
	n = 7;
	rslt_origin = strncmp(cmp1, cmp2, n);
	rslt_ft = ft_strncmp(cmp1, cmp2, n);
	printf("%s vs (null) (%zu)\t[%d][%d]\n\n", cmp1, n, rslt_origin, rslt_ft);

	strcpy(cmp1, "\0");
	strcpy(cmp2, "abcde");

	n = 0;
	rslt_origin = strncmp(cmp1, cmp2, n);
	rslt_ft = ft_strncmp(cmp1, cmp2, n);
	printf("(null) vs %s (%zu)\t[%d][%d]\n", cmp2, n, rslt_origin, rslt_ft);

	n = 1;
	rslt_origin = strncmp(cmp1, cmp2, n);
	rslt_ft = ft_strncmp(cmp1, cmp2, n);
	printf("(null) vs %s (%zu)\t[%d][%d]\n", cmp2, n, rslt_origin, rslt_ft);

	n = 5;
	rslt_origin = strncmp(cmp1, cmp2, n);
	rslt_ft = ft_strncmp(cmp1, cmp2, n);
	printf("(null) vs %s (%zu)\t[%d][%d]\n", cmp2, n, rslt_origin, rslt_ft);

	n = 6;
	rslt_origin = strncmp(cmp1, cmp2, n);
	rslt_ft = ft_strncmp(cmp1, cmp2, n);
	printf("(null) vs %s (%zu)\t[%d][%d]\n", cmp2, n, rslt_origin, rslt_ft);
	
	n = 7;
	rslt_origin = strncmp(cmp1, cmp2, n);
	rslt_ft = ft_strncmp(cmp1, cmp2, n);
	printf("(null) vs %s (%zu)\t[%d][%d]\n\n", cmp2, n, rslt_origin, rslt_ft);

	strcpy(cmp1, "\0");
	strcpy(cmp2, "\0");

	n = 1;
	rslt_origin = strncmp(cmp1, cmp2, n);
	rslt_ft = ft_strncmp(cmp1, cmp2, n);
	printf("(null) vs (null) (%zu)\t[%d][%d]\n\n", n, rslt_origin, rslt_ft);


	printf("\n------------------------------------------------\n");

	// strnstr
	printf("\n[strnstr]\n\n");

	char hay[30];
	char needle[30];
	char *rst_origin;
	char *rst_ft;

	strcpy(hay, "abcde");
	


	strcpy(needle, "a");

	n = 1;
	rst_origin = strnstr(hay, needle, n);
	rst_ft = ft_strnstr(hay, needle, n);
	printf("%s, %s (%zu)\t[%p][%p]\n", hay, needle, n, rst_origin, rst_ft);

	n = 3;
	rst_origin = strnstr(hay, needle, n);
	rst_ft = ft_strnstr(hay, needle, n);
	printf("%s, %s (%zu)\t[%p][%p]\n", hay, needle, n, rst_origin, rst_ft);

	n = 5;
	rst_origin = strnstr(hay, needle, n);
	rst_ft = ft_strnstr(hay, needle, n);
	printf("%s, %s (%zu)\t[%p][%p]\n", hay, needle, n, rst_origin, rst_ft);

	strcpy(needle, "c");

	n = 1;
	rst_origin = strnstr(hay, needle, n);
	rst_ft = ft_strnstr(hay, needle, n);
	printf("%s, %s (%zu)\t[%p][%p]\n", hay, needle, n, rst_origin, rst_ft);

	n = 3;
	rst_origin = strnstr(hay, needle, n);
	rst_ft = ft_strnstr(hay, needle, n);
	printf("%s, %s (%zu)\t[%p][%p]\n", hay, needle, n, rst_origin, rst_ft);

	n = 5;
	rst_origin = strnstr(hay, needle, n);
	rst_ft = ft_strnstr(hay, needle, n);
	printf("%s, %s (%zu)\t[%p][%p]\n", hay, needle, n, rst_origin, rst_ft);

	strcpy(needle, "e");

	n = 1;
	rst_origin = strnstr(hay, needle, n);
	rst_ft = ft_strnstr(hay, needle, n);
	printf("%s, %s (%zu)\t[%p][%p]\n", hay, needle, n, rst_origin, rst_ft);

	n = 3;
	rst_origin = strnstr(hay, needle, n);
	rst_ft = ft_strnstr(hay, needle, n);
	printf("%s, %s (%zu)\t[%p][%p]\n", hay, needle, n, rst_origin, rst_ft);

	n = 5;
	rst_origin = strnstr(hay, needle, n);
	rst_ft = ft_strnstr(hay, needle, n);
	printf("%s, %s (%zu)\t[%p][%p]\n\n", hay, needle, n, rst_origin, rst_ft);





	strcpy(needle, "ab");

	n = 1;
	rst_origin = strnstr(hay, needle, n);
	rst_ft = ft_strnstr(hay, needle, n);
	printf("%s, %s (%zu)\t[%p][%p]\n", hay, needle, n, rst_origin, rst_ft);

	n = 3;
	rst_origin = strnstr(hay, needle, n);
	rst_ft = ft_strnstr(hay, needle, n);
	printf("%s, %s (%zu)\t[%p][%p]\n", hay, needle, n, rst_origin, rst_ft);

	n = 5;
	rst_origin = strnstr(hay, needle, n);
	rst_ft = ft_strnstr(hay, needle, n);
	printf("%s, %s (%zu)\t[%p][%p]\n", hay, needle, n, rst_origin, rst_ft);

	strcpy(needle, "cd");

	n = 1;
	rst_origin = strnstr(hay, needle, n);
	rst_ft = ft_strnstr(hay, needle, n);
	printf("%s, %s (%zu)\t[%p][%p]\n", hay, needle, n, rst_origin, rst_ft);

	n = 3;
	rst_origin = strnstr(hay, needle, n);
	rst_ft = ft_strnstr(hay, needle, n);
	printf("%s, %s (%zu)\t[%p][%p]\n", hay, needle, n, rst_origin, rst_ft);

	n = 5;
	rst_origin = strnstr(hay, needle, n);
	rst_ft = ft_strnstr(hay, needle, n);
	printf("%s, %s (%zu)\t[%p][%p]\n", hay, needle, n, rst_origin, rst_ft);

	strcpy(needle, "de");

	n = 1;
	rst_origin = strnstr(hay, needle, n);
	rst_ft = ft_strnstr(hay, needle, n);
	printf("%s, %s (%zu)\t[%p][%p]\n", hay, needle, n, rst_origin, rst_ft);

	n = 3;
	rst_origin = strnstr(hay, needle, n);
	rst_ft = ft_strnstr(hay, needle, n);
	printf("%s, %s (%zu)\t[%p][%p]\n", hay, needle, n, rst_origin, rst_ft);

	n = 5;
	rst_origin = strnstr(hay, needle, n);
	rst_ft = ft_strnstr(hay, needle, n);
	printf("%s, %s (%zu)\t[%p][%p]\n\n", hay, needle, n, rst_origin, rst_ft);




	strcpy(needle, "1");

	n = 5;
	rst_origin = strnstr(hay, needle, n);
	rst_ft = ft_strnstr(hay, needle, n);
	printf("%s, %s (%zu)\t[%p][%p]\n", hay, needle, n, rst_origin, rst_ft);

	strcpy(needle, "123");

	n = 5;
	rst_origin = strnstr(hay, needle, n);
	rst_ft = ft_strnstr(hay, needle, n);
	printf("%s, %s (%zu)\t[%p][%p]\n", hay, needle, n, rst_origin, rst_ft);

	strcpy(needle, "a1");

	n = 5;
	rst_origin = strnstr(hay, needle, n);
	rst_ft = ft_strnstr(hay, needle, n);
	printf("%s, %s (%zu)\t[%p][%p]\n", hay, needle, n, rst_origin, rst_ft);

	strcpy(needle, "1a");

	n = 5;
	rst_origin = strnstr(hay, needle, n);
	rst_ft = ft_strnstr(hay, needle, n);
	printf("%s, %s (%zu)\t[%p][%p]\n\n", hay, needle, n, rst_origin, rst_ft);





	strcpy(needle, "c1");

	n = 5;
	rst_origin = strnstr(hay, needle, n);
	rst_ft = ft_strnstr(hay, needle, n);
	printf("%s, %s (%zu)\t[%p][%p]\n", hay, needle, n, rst_origin, rst_ft);

	strcpy(needle, "1c");

	n = 5;
	rst_origin = strnstr(hay, needle, n);
	rst_ft = ft_strnstr(hay, needle, n);
	printf("%s, %s (%zu)\t[%p][%p]\n", hay, needle, n, rst_origin, rst_ft);

	strcpy(needle, "e1");

	n = 5;
	rst_origin = strnstr(hay, needle, n);
	rst_ft = ft_strnstr(hay, needle, n);
	printf("%s, %s (%zu)\t[%p][%p]\n", hay, needle, n, rst_origin, rst_ft);

	strcpy(needle, "1e");

	n = 5;
	rst_origin = strnstr(hay, needle, n);
	rst_ft = ft_strnstr(hay, needle, n);
	printf("%s, %s (%zu)\t[%p][%p]\n\n", hay, needle, n, rst_origin, rst_ft);





	strcpy(hay, "abcde");
	strcpy(needle, "abcde");

	n = 0;
	rst_origin = strnstr(hay, needle, n);
	rst_ft = ft_strnstr(hay, needle, n);
	printf("%s, %s (%zu)\t[%p][%p]\n", hay, needle, n, rst_origin, rst_ft);


	strcpy(hay, "abcde");
	strcpy(needle, "\0");

	n = 0;
	rst_origin = strnstr(hay, needle, n);
	rst_ft = ft_strnstr(hay, needle, n);
	printf("%s, (null) (%zu)\t[%p][%p]\n", hay, n, rst_origin, rst_ft);

	strcpy(hay, "\0");
	strcpy(needle, "abcde");

	n = 0;
	rst_origin = strnstr(hay, needle, n);
	rst_ft = ft_strnstr(hay, needle, n);
	printf("(null), %s (%zu)\t[%p][%p]\n", needle, n, rst_origin, rst_ft);

	strcpy(hay, "\0");
	strcpy(needle, "\0");

	n = 0;
	rst_origin = strnstr(hay, needle, n);
	rst_ft = ft_strnstr(hay, needle, n);
	printf("(null), (null) (%zu)\t[%p][%p]\n", n, rst_origin, rst_ft);





	printf("\n------------------------------------------------\n");

	// strchr
	printf("\n[strchr]\n\n");

	strcpy(s1, "aabcde");
	strcpy(s2, "abccde");
	strcpy(s3, "abcdee");
	strcpy(s4, "");

	printf("\"%s\" (%c)\t\t[%s]\t[%s]\n", s1, 'a', strchr(s1, 'a'), ft_strchr(s1, 'a'));
	printf("\"%s\" (%c)\t\t[%s]\t\t[%s]\n", s2, 'c', strchr(s2, 'c'), ft_strchr(s2, 'c'));
	printf("\"%s\" (%c)\t\t[%s]\t\t[%s]\n", s3, 'e', strchr(s3, 'e'), ft_strchr(s3, 'e'));
	printf("\"%s\" (%c)\t\t[%s]\t[%s]\n", s3, 'z', strchr(s3, 'z'), ft_strchr(s3, 'z'));
	printf("\"%s\" (null)\t\t[%s]\t\t[%s]\n", s3, strchr(s3, '\0'), ft_strchr(s3, '\0'));
	printf("empty string (%c)\t[%s]\t[%s]\n", 'a', strchr(s4, 'a'), ft_strchr(s4, 'a'));
	printf("empty string (null)\t[%s]\t\t[%s]\n", strchr(s4, '\0'), ft_strchr(s4, '\0'));

	printf("\n------------------------------------------------\n");

	// strrchr
	printf("\n[strrchr]\n\n");

	// char multi_null[10] = "a\0b\0\0c\0";
	// char multi_null_full[5] = "\0\0\0\0\0";
	
	// printf("%lu %lu\n\n", sizeof(multi_null), sizeof(multi_null_full));
	// write(1, strrchr(multi_null, '\0'), 8);
	// write(1, "\n", 1);
	// write(1, ft_strrchr(multi_null, '\0'), 8);
	// write(1, "\n", 1);

	printf("\"%s\" (%c)\t\t[%s]\t\t[%s]\n", s1, 'a', strrchr(s1, 'a'), ft_strrchr(s1, 'a'));
	printf("\"%s\" (%c)\t\t[%s]\t\t[%s]\n", s2, 'c', strrchr(s2, 'c'), ft_strrchr(s2, 'c'));
	printf("\"%s\" (%c)\t\t[%s]\t\t[%s]\n", s3, 'e', strrchr(s3, 'e'), ft_strrchr(s3, 'e'));
	printf("\"%s\" (%c)\t\t[%s]\t[%s]\n", s3, 'z', strrchr(s3, 'z'), ft_strrchr(s3, 'z'));
	printf("\"%s\" (null)\t\t[%s]\t\t[%s]\n", s3, strrchr(s3, '\0'), ft_strrchr(s3, '\0'));
	printf("empty string (%c)\t[%s]\t[%s]\n", 'a', strrchr(s4, 'a'), ft_strrchr(s4, 'a'));
	printf("empty string (null)\t[%s]\t\t[%s]\n", strrchr(s4, '\0'), ft_strrchr(s4, '\0'));

	printf("\n------------------------------------------------\n");

	// atoi
	printf("\n[atoi]\n\n");

	char is1[] = "2147483647";
	char is2[] = "345";
	char is3[] = "0";
	char is4[] = "-345";
	char is5[] = "-2147483648";
	char is_over[] = "2147483650";
	char is_null[] = "\0";

	char is6[] = "+123";
	char is7[] = "-123";
	char is8[] = "+-123";
	char is9[] = "-+123";
	char is10[] = "\t\n\v\f\r 123";
	char is11[] = "  \t-123";
	char is12[] = "123abc";
	char is13[] = "123 456";

	char is14[] = "000123";
	char is15[] = "000123000";
	char is16[] = "123000";
	char is17[] = "+0123";
	char is18[] = "-0123";
	char is19[] = "+-0123";
	char is20[] = "00+123";
	char is21[] = "00-123";
	char is22[] = "00a123";
	char is23[] = "00 123";

	char is24[] = "abcde";
	char is25[] = "00000";

	printf("%s\t[%d]\t[%d]\n", is1, atoi(is1), ft_atoi(is1));
	printf("%s\t\t[%d]\t\t[%d]\n", is2, atoi(is2), ft_atoi(is2));
	printf("%s\t\t[%d]\t\t[%d]\n", is3, atoi(is3), ft_atoi(is3));
	printf("%s\t\t[%d]\t\t[%d]\n", is4, atoi(is4), ft_atoi(is4));
	printf("%s\t[%d]\t[%d]\n", is5, atoi(is5), ft_atoi(is5));
	printf("%s\t[%d]\t[%d]\n", is_over, atoi(is_over), ft_atoi(is_over));
	printf("(null)\t\t[%d]\t\t[%d]\n", atoi(is_null), ft_atoi(is_null));

	printf("\n");

	printf("%s\t\t[%d]\t\t[%d]\n", is6, atoi(is6), ft_atoi(is6));
	printf("%s\t\t[%d]\t\t[%d]\n", is7, atoi(is7), ft_atoi(is7));
	printf("%s\t\t[%d]\t\t[%d]\n", is8, atoi(is8), ft_atoi(is8));
	printf("%s\t\t[%d]\t\t[%d]\n", is9, atoi(is9), ft_atoi(is9));
	printf("\\t\\n\\v\\f\\r 123\t[%d]\t\t[%d]\n", atoi(is10), ft_atoi(is10));
	printf("  \\t-123\t[%d]\t\t[%d]\n", atoi(is11), ft_atoi(is11));
	printf("%s\t\t[%d]\t\t[%d]\n", is12, atoi(is12), ft_atoi(is12));
	printf("%s\t\t[%d]\t\t[%d]\n", is13, atoi(is13), ft_atoi(is13));

	printf("\n");

	printf("%s\t\t[%d]\t\t[%d]\n", is14, atoi(is14), ft_atoi(is14));
	printf("%s\t[%d]\t[%d]\n", is15, atoi(is15), ft_atoi(is15));
	printf("%s\t\t[%d]\t[%d]\n", is16, atoi(is16), ft_atoi(is16));
	printf("%s\t\t[%d]\t\t[%d]\n", is17, atoi(is17), ft_atoi(is17));
	printf("%s\t\t[%d]\t\t[%d]\n", is18, atoi(is18), ft_atoi(is18));
	printf("%s\t\t[%d]\t\t[%d]\n", is19, atoi(is19), ft_atoi(is19));
	printf("%s\t\t[%d]\t\t[%d]\n", is20, atoi(is20), ft_atoi(is20));
	printf("%s\t\t[%d]\t\t[%d]\n", is21, atoi(is21), ft_atoi(is21));
	printf("%s\t\t[%d]\t\t[%d]\n", is22, atoi(is22), ft_atoi(is22));
	printf("%s\t\t[%d]\t\t[%d]\n", is23, atoi(is23), ft_atoi(is23));

	printf("\n");

	printf("%s\t\t[%d]\t\t[%d]\n", is24, atoi(is24), ft_atoi(is25));
	printf("%s\t\t[%d]\t\t[%d]\n", is25, atoi(is25), ft_atoi(is25));

	printf("\n------------------------------------------------\n");

	// calloc
	printf("\n[calloc]\n\n");

	char *allocated_int_origin;
	char *allocated_int_ft;

	size_t count;
	size_t size;
	size_t idx;
	size_t over;

	count = 30;
	size = 1;
	over = 0;

	printf("input count\t[%zu]\n", count);
	printf("input size\t[%zu]\n", size);
	printf("over\t\t[%zu]\n", over);

	allocated_int_origin = (char *)ft_calloc(count, size);
	// allocated_int_origin = malloc(48);
	allocated_int_ft = (char *)calloc(count, size);

	printf("\n");

	printf("total size of mem allocated by origin\t[%zu]\n", malloc_size(allocated_int_origin));
	printf("each elem of mem allocated by origin\n");
	idx = 0;
	while (idx < ((count * size) / sizeof(*allocated_int_origin)) + over)
		printf("[%c]", allocated_int_origin[idx++]);
	printf("\n");

	printf("\n");

	printf("total size of mem allocated by ft\t[%zu]\n", malloc_size(allocated_int_ft));
	printf("each elem of mem allocated by ft\n");
	idx = 0;
	while (idx < ((count * size) / sizeof(*allocated_int_ft)) + over)
		printf("[%c]", allocated_int_ft[idx++]);
	printf("\n");

	printf("\n");

	size_t test;
	test = 4000000000400000000;
	printf("size_t overflow test\nexpecting result is (null)\n");
	printf("result %s\n", (char *)ft_calloc(test, 100)); 

	printf("\n");
	
	// printf("result of SIZE_MAX --- [%s]\n", (char *)calloc(SIZE_MAX, SIZE_MAX));
	// printf("result of SIZE_MAX --- [%s]\n", (char *)ft_calloc(SIZE_MAX, SIZE_MAX));

	printf("\n------------------------------------------------\n");

	// strdup
	printf("\n[strdup]\n\n");

	char *allocated_origin;
	char *allocated_ft;
	char str_to_cpy[] = "abcde";

	allocated_origin = strdup(str_to_cpy);
	allocated_ft = ft_strdup(str_to_cpy);

	printf("str to copy\t\t\t[%s]\n", str_to_cpy);
	printf("allocated str from origin\t[%s]\n", allocated_origin);
	printf("allocated str from ft\t\t[%s]\n", allocated_ft);




	return (0);	
}