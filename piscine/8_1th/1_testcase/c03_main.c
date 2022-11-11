/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c03_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 13:39:47 by donghyu2          #+#    #+#             */
/*   Updated: 2022/09/04 13:24:07 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

//#include "ex00/ft_strcmp.c"
//#include "ex01/ft_strncmp.c"
//#include "ex02/ft_strcat.c"
//#include "ex03/ft_strncat.c"
#include "ex04/ft_strstr.c"
//#include "ex05/ft_strlcat.c"

int	main(void)
{
//	char s1[] = "abcde";
//	char s3[] = "abcde";
//	char s2[] = "abcdefg";
//	char s4[] = "abc";
//	char s5[] = " ";
//	char s6[] = "";
//	char s7[] = "xyz";
/*
	// ex00
	printf("\n[ex00]\n");
	
	int rt1, rt2;

	rt1 = strcmp(s1, s2);
	rt2 = ft_strcmp(s1, s2);
	printf("%d : %d (%s, %s)\n", rt1, rt2, s1, s2);

	rt1 = strcmp(s1, s3);
	rt2 = ft_strcmp(s1, s3);
	printf("%d : %d (%s, %s)\n", rt1, rt2, s1, s3);

	rt1 = strcmp(s1, s4);
	rt2 = ft_strcmp(s1, s4);
	printf("%d : %d (%s, %s)\n", rt1, rt2, s1, s4);

	rt1 = strcmp(s1, s5);
	rt2 = ft_strcmp(s1, s5);
	printf("%d : %d (%s, [SPACE])\n", rt1, rt2, s1);

	rt1 = strcmp(s1, s6);
	rt2 = ft_strcmp(s1, s6);
	printf("%d : %d (%s, [NULL])\n", rt1, rt2, s1);

	// ex01
	printf("\n[ex01]\n");
	
	int n;

	n = 0;
	rt1 = strncmp(s1, s7, n);
	rt2 = ft_strncmp(s1, s7, n);
	printf("%d : %d (%s, %s, n=%d)\n", rt1, rt2, s1, s7, n);

	n = 1;
	rt1 = strncmp(s1, s2, n);
	rt2 = ft_strncmp(s1, s2, n);
	printf("%d : %d (%s, %s, n=%d)\n", rt1, rt2, s1, s2, n);
	
	n = 4;
	rt1 = strncmp(s1, s2, n);
	rt2 = ft_strncmp(s1, s2, n);
	printf("%d : %d (%s, %s, n=%d)\n", rt1, rt2, s1, s2, n);

	n = 5;
	rt1 = strncmp(s1, s2, n);
	rt2 = ft_strncmp(s1, s2, n);
	printf("%d : %d (%s, %s, n=%d)\n", rt1, rt2, s1, s2, n);

	n = 6;
	rt1 = strncmp(s1, s2, n);
	rt2 = ft_strncmp(s1, s2, n);
	printf("%d : %d (%s, %s, n=%d)\n", rt1, rt2, s1, s2, n);

	n = 10;
	rt1 = strncmp(s1, s2, n);
	rt2 = ft_strncmp(s1, s2, n);
	printf("%d : %d (%s, %s, n=%d)\n", rt1, rt2, s1, s2, n);
	
	n = 5;
	rt1 = strncmp(s1, s5, n);
	rt2 = ft_strncmp(s1, s5, n);
	printf("%d : %d (%s, SPACE, n=%d)\n", rt1, rt2, s1, n);

	n = 5;
	rt1 = strncmp(s1, s6, n);
	rt2 = ft_strncmp(s1, s6, n);
	printf("%d : %d (%s, NULL, n=%d)\n", rt1, rt2, s1, n);

	// ex02
	printf("\n[ex02]\n");
	
	char de1[50] = "empty";
	char de2[50] = "empty";
	char src1[] = "abc";
	char src2[] = " ";
	char src3[] = "";

	strcat(de1, src1);
	ft_strcat(de2, src1);
	printf("%s : %s\n", de1, de2);

	strcat(de1, src2);
	ft_strcat(de2, src2);
	printf("%s : %s\n", de1, de2);

	strcat(de1, src3);
	ft_strcat(de2, src3);
	printf("%s : %s\n", de1, de2);

	// ex03
	printf("\n[ex03]\n");
	
	char de3[50] = "empty";
	char de4[50] = "empty";
	char def[] = "empty";
	char src4[] = " 1234";

	n = 0;
	strncat(de3, src4, n);
	ft_strncat(de4, src4, n);
	printf("%s : %s (n=%d)\n", de3, de4, n);

	strcpy(de3, def);
	strcpy(de4, def);
	n = 1;
	strncat(de3, src4, n);
	ft_strncat(de4, src4, n);
	printf("%s : %s (n=%d)\n", de3, de4, n);
	
	strcpy(de3, def);
	strcpy(de4, def);
	n = 2;
	strncat(de3, src4, n);
	ft_strncat(de4, src4, n);
	printf("%s : %s (n=%d)\n", de3, de4, n);

	strcpy(de3, def);
	strcpy(de4, def);
	n = 3;
	strncat(de3, src4, n);
	ft_strncat(de4, src4, n);
	printf("%s : %s (n=%d)\n", de3, de4, n);

	strcpy(de3, def);
	strcpy(de4, def);
	n = 4;
	strncat(de3, src4, n);
	ft_strncat(de4, src4, n);
	printf("%s : %s (n=%d)\n", de3, de4, n);

	strcpy(de3, def);
	strcpy(de4, def);
	n = 5;
	strncat(de3, src4, n);
	ft_strncat(de4, src4, n);
	printf("%s : %s (n=%d)\n", de3, de4, n);
*/
	// ex4
	printf("\n[ex04]\n");
	
	char haystack[] = "abc123";
	char needle1[] = "1";
	char needle2[] = "xyz";
	char needle3[] = "";
	char needle4[] = "def";
	char needle5[] = "123";

	char *rt_p1, *rt_p2;

	rt_p1 = &haystack[0];
	rt_p2 = &haystack[0];
	printf("Before strstr : %s = %s\n", rt_p1, rt_p2);
	rt_p1 = strstr(haystack, needle1);
	rt_p2 = ft_strstr(haystack, needle1);
	printf("After strstr : %s = %s\n\n", rt_p1, rt_p2);
	
	rt_p1 = &haystack[0];
	rt_p2 = &haystack[0];
	printf("Before strstr : %s = %s\n", rt_p1, rt_p2);
	rt_p1 = strstr(haystack, needle2);
	rt_p2 = ft_strstr(haystack, needle2);
	printf("After strstr : %s = %s\n\n", rt_p1, rt_p2);

	rt_p1 = &haystack[0];
	rt_p2 = &haystack[0];
	printf("Before strstr : %s = %s\n", rt_p1, rt_p2);
	rt_p1 = strstr(haystack, needle3);
	rt_p2 = ft_strstr(haystack, needle3);
	printf("After strstr : %s = %s\n\n", rt_p1, rt_p2);

	rt_p1 = &haystack[0];
	rt_p2 = &haystack[0];
	printf("Before strstr : %s = %s\n", rt_p1, rt_p2);
	rt_p1 = strstr(haystack, needle4);
	rt_p2 = ft_strstr(haystack, needle4);
	printf("After strstr : %s = %s\n\n", rt_p1, rt_p2);

	rt_p1 = &haystack[0];
	rt_p2 = &haystack[0];
	printf("Before strstr : %s = %s\n", rt_p1, rt_p2);
	rt_p1 = strstr(haystack, needle5);
	rt_p2 = ft_strstr(haystack, needle5);
	printf("After strstr : %s = %s\n\n", rt_p1, rt_p2);
	/*
	// ex05
	printf("\n[ex05]\n");

	strcpy(de3, def);
	strcpy(de4, def);
	n = 0;
	rt1 = strlcat(de3, src4, n);
	rt2 = ft_strlcat(de4, src4, n);
	printf("%s : %s (n=%d) %d : %d\n", de3, de4, n, rt1, rt2);

	strcpy(de3, def);
	strcpy(de4, def);
	n = 6;
	rt1 = strlcat(de3, src4, n);
	rt2 = ft_strlcat(de4, src4, n);
	printf("%s : %s (n=%d) %d : %d\n", de3, de4, n, rt1, rt2);
	
	strcpy(de3, def);
	strcpy(de4, def);
	n = 7;
	rt1 = strlcat(de3, src4, n);
	rt2 = ft_strlcat(de4, src4, n);
	printf("%s : %s (n=%d) %d : %d\n", de3, de4, n, rt1, rt2);

	strcpy(de3, def);
	strcpy(de4, def);
	n = 8;
	rt1 = strlcat(de3, src4, n);
	rt2 = ft_strlcat(de4, src4, n);
	printf("%s : %s (n=%d) %d : %d\n", de3, de4, n, rt1, rt2);

	strcpy(de3, def);
	strcpy(de4, def);
	n = 9;
	rt1 = strlcat(de3, src4, n);
	rt2 = ft_strlcat(de4, src4, n);
	printf("%s : %s (n=%d) %d : %d\n", de3, de4, n, rt1, rt2);

	strcpy(de3, def);
	strcpy(de4, def);
	n = 10;
	rt1 = strlcat(de3, src4, n);
	rt2 = ft_strlcat(de4, src4, n);
	printf("%s : %s (n=%d) %d : %d\n", de3, de4, n, rt1, rt2);

*/
	return (0);
}

