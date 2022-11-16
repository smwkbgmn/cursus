#include "main.h"

int main(void)
{
	// // memcpy
	// printf("\n----------------------------------------\n");
	// printf("\n[memcpy]\n");

	// char s1[100] = "learningisfun";
	// char s2[100] = "learningisfun";
	// char *st1, *st2;

	// st1 = s1;
	// st2 = s2; 

	// printf ("before origin\t[%s]\n", st1);
	// printf ("before ft\t[%s]\n\n", st2);

	// memcpy(st1 + 8, st1, 10);
	// ft_memcpy(st2 + 8, st2, 10);

	// printf ("after origin\t[%s]\n", st1);
	// printf ("after ft\t[%s]\n", st2);


	// // memmove
	// printf("\n----------------------------------------\n");
	// printf("\n[memmove]\n");
	
	// strcpy(s1, "learningisfun");
	// strcpy(s2, "learningisfun");

	// printf ("before origin\t[%s]\n", st1);
	// printf ("before ft\t[%s]\n\n", st2);

	// memmove(st1 + 8, st1 + 0, 10);
	// ft_memmove(st2 + 8, st2 + 0, 10);

	// printf ("after origin\t[%s]\n", st1);
	// printf ("after ft\t[%s]\n", st2);

	// // memcmp
	// printf("\n----------------------------------------\n");
	// printf("\n[memcmp]\n");

	// char s3[50] = "learning";
	// char s4[50] = "a";
	// char s5[50] = "";
	// char s6[50] = "le";
	
	// strcpy(s1, "lear");
	// strcpy(s2, "lear");

	// printf("str1 vs str2\t\t(length)[origin][ft]\n\n");
	// printf("%s vs %s\t\t(3)[%d][%d]\n", s1, s2, memcmp(s1, s2, 3), ft_memcmp(s1, s2, 3));
	// printf("%s vs %s\t\t(4)[%d][%d]\n", s1, s2, memcmp(s1, s2, 4), ft_memcmp(s1, s2, 4));
	// printf("%s vs %s\t\t(5)[%d][%d]\n", s1, s2, memcmp(s1, s2, 5), ft_memcmp(s1, s2, 5));
	// printf("%s vs %s\t\t(6)[%d][%d]\n", s1, s2, memcmp(s1, s2, 6), ft_memcmp(s1, s2, 6));
	// printf("%s vs %s\t\t(100)[%d][%d]\n", s1, s2, memcmp(s1, s2, 100), ft_memcmp(s1, s2, 100));

	// printf("\n");

	// printf("%s vs %s\t\t(1)[%d][%d]\n", s1, s6, memcmp(s1, s6, 1), ft_memcmp(s1, s6, 1));
	// printf("%s vs %s\t\t(2)[%d][%d]\n", s1, s6, memcmp(s1, s6, 2), ft_memcmp(s1, s6, 2));
	// printf("%s vs %s\t\t(3)[%d][%d]\n", s1, s6, memcmp(s1, s6, 3), ft_memcmp(s1, s6, 3));
	// printf("%s vs %s\t\t(4)[%d][%d]\n", s1, s6, memcmp(s1, s6, 4), ft_memcmp(s1, s6, 4));

	// printf("\n");

	// printf("%s vs %s\t(4)[%d][%d]\n", s1, s3, memcmp(s1, s3, 4), ft_memcmp(s1, s3, 4));
	// printf("%s vs %s\t(5)[%d][%d]\n", s1, s3, memcmp(s1, s3, 5), ft_memcmp(s1, s3, 5));
	// printf("%s vs %s\t(6)[%d][%d]\n", s1, s3, memcmp(s1, s3, 6), ft_memcmp(s1, s3, 6));

	// printf("\n");

	// printf("%s vs %s\t\t(0)[%d][%d]\n", s1, s4, memcmp(s1, s4, 0), ft_memcmp(s1, s4, 0));
	// printf("%s vs %s\t\t(1)[%d][%d]\n", s1, s4, memcmp(s1, s4, 1), ft_memcmp(s1, s4, 1));
	// printf("%s vs %s\t\t(2)[%d][%d]\n", s1, s4, memcmp(s1, s4, 2), ft_memcmp(s1, s4, 2));
	// printf("%s vs %s\t\t(3)[%d][%d]\n", s1, s4, memcmp(s1, s4, 3), ft_memcmp(s1, s4, 3));

	// printf("\n");

	// printf("%s vs null\t\t(0)[%d][%d]\n", s1, memcmp(s1, s5, 0), ft_memcmp(s1, s5, 0));
	// printf("%s vs null\t\t(1)[%d][%d]\n", s1, memcmp(s1, s5, 1), ft_memcmp(s1, s5, 1));
	// printf("%s vs null\t\t(2)[%d][%d]\n", s1, memcmp(s1, s5, 2), ft_memcmp(s1, s5, 2));

	// printf("\n");

	// printf("null vs null\t\t(0)[%d][%d]\n", memcmp(s5, s5, 0), ft_memcmp(s5, s5, 0));
	// printf("null vs null\t\t(1)[%d][%d]\n", memcmp(s5, s5, 1), ft_memcmp(s5, s5, 1));
	// printf("null vs null\t\t(2)[%d][%d]\n", memcmp(s5, s5, 2), ft_memcmp(s5, s5, 2));

	// // strlcpy
	// printf("\n----------------------------------------\n");
	// printf("\n[strlcpy]\n");

	// char src[100] = "source";
	// char src_null[10] = "";

	// char dst1[10];
	// char dst2[10];
	// char dst3[10];
	// char dst4[10];
	// char dst9[10];

	// printf("src string\t[%s]\n\n", src);
	
	// printf("origin\t\t(%d)[%lu][%s]\n", 0, strlcpy(dst1, src, 0), dst1);
	// printf("origin\t\t(%d)[%lu][%s]\n", 6, strlcpy(dst2, src, 6), dst2);
	// printf("origin\t\t(%d)[%lu][%s]\n", 7, strlcpy(dst3, src, 7), dst3);
	// printf("origin\t\t(%d)[%lu][%s]\n", 8, strlcpy(dst4, src, 8), dst4);
	// printf("origin\t\t(%d)[%lu][%s]\n", 3, strlcpy(dst9, src_null, 3), dst9);

	// printf("\n");

	// char dst5[10];
	// char dst6[10];
	// char dst7[10];
	// char dst8[10];
	// char dst10[10];

	// printf("ft\t\t(%d)[%lu][%s]\n", 0, ft_strlcpy(dst5, src, 0), dst5);
	// printf("ft\t\t(%d)[%lu][%s]\n", 6, ft_strlcpy(dst6, src, 6), dst6);
	// printf("ft\t\t(%d)[%lu][%s]\n", 7, ft_strlcpy(dst7, src, 7), dst7);
	// printf("ft\t\t(%d)[%lu][%s]\n", 8, ft_strlcpy(dst8, src, 8), dst8);
	// printf("ft\t\t(%d)[%lu][%s]\n", 3, ft_strlcpy(dst10, src_null, 3), dst10);


	// // strlcat
	// printf("\n----------------------------------------\n");
	// printf("\n[strlcat]\n");

	// char dst[50] = "dest";
	// char dst_null[10] = "";
	// char dst_lack_size[2] = "";

	// printf("source string\t[%s]\n", src);
	// printf("dest string\t[%s]\n\n", dst);

	// printf("origin\t\t(%d)[%lu][%s]\n", 0, strlcat(dst, src, 0), dst);
	// strcpy(dst, "dest"); 
	// printf("origin\t\t(%d)[%lu][%s]\n", 3, strlcat(dst, src, 3), dst);
	// strcpy(dst, "dest"); 
	// printf("origin\t\t(%d)[%lu][%s]\n", 4, strlcat(dst, src, 4), dst);
	// strcpy(dst, "dest"); 
	// printf("origin\t\t(%d)[%lu][%s]\n", 5, strlcat(dst, src, 5), dst);
	// strcpy(dst, "dest"); 
	// printf("origin\t\t(%d)[%lu][%s]\n", 6, strlcat(dst, src, 6), dst);
	// strcpy(dst, "dest"); 
	// printf("origin\t\t(%d)[%lu][%s]\n", 7, strlcat(dst, src, 7), dst);
	// strcpy(dst, "dest"); 
	// printf("origin\t\t(%d)[%lu][%s]\n", 12, strlcat(dst, src, 12), dst);
	// strcpy(dst, "dest"); 
	// printf("origin\t\t(%d)[%lu][%s]\n\n", 13, strlcat(dst, src, 13), dst);
	// strcpy(dst, "dest");

	// printf("origin_null_src\t\t(%d)[%lu][%s]\n", 7, strlcat(dst, src_null, 7), dst);
	// strcpy(dst, "dest");
	// printf("origin_null_dst\t\t(%d)[%lu][%s]\n", 7, strlcat(dst_null, src, 7), dst_null);
	// strcpy(dst_null, "");
	// printf("origin_lack_size_of_dst\t(%d)[%lu][%s]\n", 1, strlcat(dst_lack_size, src, 1), dst_lack_size);
	// strcpy(dst_lack_size, "");
	// printf("origin_lack_size_of_dst\t(%d)[%lu][%s]\n", 2, strlcat(dst_lack_size, src, 2), dst_lack_size);
	// strcpy(dst_lack_size, "");
	
	// printf("\n");

	// printf("ft\t\t(%d)[%lu][%s]\n", 0, ft_strlcat(dst, src, 0), dst);
	// strcpy(dst, "dest"); 
	// printf("ft\t\t(%d)[%lu][%s]\n", 3, ft_strlcat(dst, src, 3), dst);
	// strcpy(dst, "dest"); 
	// printf("ft\t\t(%d)[%lu][%s]\n", 4, ft_strlcat(dst, src, 4), dst);
	// strcpy(dst, "dest"); 
	// printf("ft\t\t(%d)[%lu][%s]\n", 5, ft_strlcat(dst, src, 5), dst);
	// strcpy(dst, "dest"); 
	// printf("ft\t\t(%d)[%lu][%s]\n", 6, ft_strlcat(dst, src, 6), dst);
	// strcpy(dst, "dest"); 
	// printf("ft\t\t(%d)[%lu][%s]\n", 7, ft_strlcat(dst, src, 7), dst);
	// strcpy(dst, "dest"); 
	// printf("ft\t\t(%d)[%lu][%s]\n", 12, ft_strlcat(dst, src, 12), dst);
	// strcpy(dst, "dest"); 
	// printf("ft\t\t(%d)[%lu][%s]\n\n", 13, ft_strlcat(dst, src, 13), dst);
	// strcpy(dst, "dest");

	// printf("ft_null_src\t\t(%d)[%lu][%s]\n", 7, ft_strlcat(dst, src_null, 7), dst);
	// strcpy(dst, "dest");
	// printf("ft_null_dst\t\t(%d)[%lu][%s]\n", 7, ft_strlcat(dst_null, src, 7), dst_null);
	// strcpy(dst_null, "");
	// printf("ft_lack_size_of_dst\t(%d)[%lu][%s]\n", 1, ft_strlcat(dst_lack_size, src, 1), dst_lack_size);
	// strcpy(dst_lack_size, "");
	// printf("ft_lack_size_of_dst\t(%d)[%lu][%s]\n", 2, ft_strlcat(dst_lack_size, src, 2), dst_lack_size);
	// strcpy(dst_lack_size, "");


	// // strchr
	// printf("\n----------------------------------------\n");
	// printf("\n[strchr]\n");

	// strcpy(s1, "aabcde");
	// strcpy(s2, "abccde");
	// strcpy(s3, "abcdee");
	// strcpy(s4, "");

	// printf("origin\n");
	// printf("str %s\tchar %c\t\t[%s]\n", s1, 'a', strchr(s1, 'a'));
	// printf("str %s\tchar %c\t\t[%s]\n", s2, 'c', strchr(s2, 'c'));
	// printf("str %s\tchar %c\t\t[%s]\n", s3, 'e', strchr(s3, 'e'));
	// printf("str %s\tchar %c\t\t[%s]\n", s3, 'z', strchr(s3, 'z'));
	// printf("str %s\tchar (null)\t[%s]\n", s3, strchr(s3, '\0'));
	// printf("empty string\tchar %c\t\t[%s]\n", 'a', strchr(s4, 'a'));
	// printf("empty string\tchar (null)\t[%s]\n", strchr(s4, '\0'));

	// printf("\n");
	// printf("ft\n");
	// printf("str %s\tchar %c\t\t[%s]\n", s1, 'a', ft_strchr(s1, 'a'));
	// printf("str %s\tchar %c\t\t[%s]\n", s2, 'c', ft_strchr(s2, 'c'));
	// printf("str %s\tchar %c\t\t[%s]\n", s3, 'e', ft_strchr(s3, 'e'));
	// printf("str %s\tchar %c\t\t[%s]\n", s3, 'z', ft_strchr(s3, 'z'));
	// printf("str %s\tchar (null)\t[%s]\n", s3, ft_strchr(s3, '\0'));
	// printf("empty string\tchar %c\t\t[%s]\n", 'a', ft_strchr(s4, 'a'));
	// printf("empty string\tchar (null)\t[%s]\n", ft_strchr(s4, '\0'));


	// // strrchr
	// printf("\n----------------------------------------\n");
	// printf("\n[strrchr]\n");

	// // char multi_null[10] = "a\0b\0\0c\0";
	// // char multi_null_full[5] = "\0\0\0\0\0";
	
	// // printf("%lu %lu\n\n", sizeof(multi_null), sizeof(multi_null_full));
	// // write(1, strrchr(multi_null, '\0'), 8);
	// // write(1, "\n", 1);
	// // write(1, ft_strrchr(multi_null, '\0'), 8);
	// // write(1, "\n", 1);

	// printf("origin\n");
	// printf("str %s\tchar %c\t\t[%s]\n", s1, 'a', strrchr(s1, 'a'));
	// printf("str %s\tchar %c\t\t[%s]\n", s2, 'c', strrchr(s2, 'c'));
	// printf("str %s\tchar %c\t\t[%s]\n", s3, 'e', strrchr(s3, 'e'));
	// printf("str %s\tchar %c\t\t[%s]\n", s3, 'z', strrchr(s3, 'z'));
	// printf("str %s\tchar (null)\t[%s]\n", s3, strrchr(s3, '\0'));
	// printf("empty string\tchar %c\t\t[%s]\n", 'a', strrchr(s4, 'a'));
	// printf("empty string\tchar (null)\t[%s]\n", strrchr(s4, '\0'));

	// printf("\n");
	// printf("ft\n");
	// printf("str %s\tchar %c\t\t[%s]\n", s1, 'a', ft_strrchr(s1, 'a'));
	// printf("str %s\tchar %c\t\t[%s]\n", s2, 'c', ft_strrchr(s2, 'c'));
	// printf("str %s\tchar %c\t\t[%s]\n", s3, 'e', ft_strrchr(s3, 'e'));
	// printf("str %s\tchar %c\t\t[%s]\n", s3, 'z', ft_strrchr(s3, 'z'));
	// printf("str %s\tchar (null)\t[%s]\n", s3, ft_strrchr(s3, '\0'));
	// printf("empty string\tchar %c\t\t[%s]\n", 'a', ft_strrchr(s4, 'a'));
	// printf("empty string\tchar (null)\t[%s]\n", ft_strrchr(s4, '\0'));

	// atoi
	printf("\n----------------------------------------\n");
	printf("\n[atoi]\n");

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
	

	return (0);	
}