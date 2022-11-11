/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c02_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 21:07:23 by donghyu2          #+#    #+#             */
/*   Updated: 2022/08/30 01:39:41 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

//#include "ex00/ft_strcpy.c"
#include "ex01/ft_strncpy.c"
//#include "ex02/ft_str_is_alpha.c"
//#include "ex03/ft_str_is_numeric.c"
//#include "ex04/ft_str_is_lowercase.c"
//#include "ex05/ft_str_is_uppercase.c"
//#include "ex06/ft_str_is_printable.c"
//#include "ex07/ft_strupcase.c"
//#include "ex08/ft_strlowcase.c"
//#include "ex09/ft_strcapitalize.c"
//#include "ex10/ft_strlcpy.c"
//#include "ex11/ft_putstr_non_printable.c"
//#include "ex12/ft_print_memory.c"
int	main()
{
	
	char	ec1[50];
	char	ec2[50];
	char	ec3[50];
	char	ec4[50];
//	char	ec5[30] = "empty";
//	char	ec6[30] = "empty";
//	char	c1[] = "Hi";
//	char	c2[] = "There?";
	char	c3[] = " ";
	char	c4[] = "";

/*	// ex00
	printf("\n[ex00]\n");

	strcpy(ec1, c1);
	ft_strcpy(ec2, c1);
	printf("%s : %s\n", ec1, ec2);

	strcpy(ec1, c3);
	ft_strcpy(ec2, c3);
	printf("%s : %s\n", ec1, ec2);

	strcpy(ec1, c4);
	ft_strcpy(ec2, c4);
	printf("%s : %s\n", ec1, ec2);
*/
	// ex01
	printf("\n[ex01]\n");
/*
	strncpy(ec1, c1, 3);
	ft_strncpy(ec2, c1, 3);
	printf("%s : %s (n=3)\n", ec1, ec2);

	strncpy(ec1, c2, 3);
	ft_strncpy(ec2, c2, 3);
	printf("%s : %s (n=3)\n", ec1, ec2);

	strncpy(ec1, c2, 6);
	ft_strncpy(ec2, c2, 6);
	printf("%s : %s (n=6)\n", ec1, ec2);
*/
	strncpy(ec3, c3, 0);
	ft_strncpy(ec4, c3, 0);
	printf("%s : %s (n=0)\n", ec3, ec4);

	strncpy(ec1, c4, 1);
	ft_strncpy(ec2, c4, 1);
	printf("%s : %s (n=1)\n", ec1, ec2);

	strncpy(ec3, c3, 1);
	ft_strncpy(ec4, c3, 1);
	printf("%s : %s (n=1)\n", ec3, ec4);
/*
	// ex02
	printf("\n[ex02]\n");
	
	int rt;
	char alpha1[] = "abcABC";
	rt = ft_str_is_alpha(alpha1);
	printf("(%s) : %d\n", alpha1, rt);

	char alpha2[] = "abc ABC";
	rt = ft_str_is_alpha(alpha2);
	printf("(%s) : %d\n", alpha2, rt);

	char alpha3[] = "1abcABC";
	rt = ft_str_is_alpha(alpha3);
	printf("(%s) : %d\n", alpha3, rt);

	char alpha4[] = "abcABC-";
	rt = ft_str_is_alpha(alpha4);
	printf("(%s) : %d\n", alpha4, rt);

	char alpha5[] = " ";
	rt = ft_str_is_alpha(alpha5);
	printf("( ) : %d\n", rt);

	char alpha6[] = "";
	rt = ft_str_is_alpha(alpha6);
	printf("() : %d\n", rt);

	char alpha7[] = "\0";
	rt = ft_str_is_alpha(alpha7);
	printf("(NULl) : %d\n", rt);

	// ex07
	printf("\n[ex07]\n");
	
	char ex071[] = "123 abcABC";
	printf("%s\n", ex071);
	ft_strupcase(ex071);
	printf("%s\n", ex071);
	
	// ex08
	printf("\n[ex08]\n");

	char ex081[] = "123 abcABC";
	printf("%s\n", ex081);
	ft_strlowcase(ex081);
	printf("%s\n", ex081);

	// ex09
	printf("\n[ex09]\n");

	char test1[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	
	printf("%s\n", test1);
	ft_strcapitalize(test1);
	printf("%s\n", test1);
	

	// ex10
	printf("\n[ex10]\n");

	int	size1;
	int	size2;

	size1 = strlcpy(ec1, c1, 3);
	size2 = ft_strlcpy(ec2, c1, 3);
	printf("%s, %d : %s, %d (n=3)\n", ec1, size1, ec2, size2);

	size1 = strlcpy(ec1, c2, 3);
	size2 = ft_strlcpy(ec2, c2, 3);
	printf("%s, %d : %s, %d (n=3)\n", ec1, size1, ec2, size2);

	size1 = strlcpy(ec1, c2, 6);
	size2 = ft_strlcpy(ec2, c2, 6);
	printf("%s, %d : %s, %d (n=6)\n", ec1, size1, ec2, size2);

	size1 = strlcpy(ec1, c2, 8);
	size2 = ft_strlcpy(ec2, c2, 8);
	printf("%s, %d : %s, %d (n=8)\n", ec1, size1, ec2, size2);

	size1 = strlcpy(ec5, c1, 0);
	size2 = ft_strlcpy(ec6, c1, 0);
	printf( "%s, %d : %s, %d (n=0)\n", ec5, size1, ec6, size2);

	size1 = strlcpy(ec1, c4, 1);
	size2 = ft_strlcpy(ec2, c4, 1);
	printf("%s, %d : %s, %d (n=1)\n", ec1, size1, ec2, size2);

	size1 = strlcpy(ec1, c3, 1);
	size2 = ft_strlcpy(ec2, c3, 1);
	printf("%s, %d : %s, %d (n=1)\n", ec1, size1, ec2, size2);

	// ex11
	printf("\n[ex11]\n");

	char	non_printable[] = "Coucou\ntu vas bien ?";
	ft_putstr_non_printable(non_printable);
	
	// ex12
	printf("\n[ex12]\n");
	
	//char str1[] = "Hello There guy!Hello\n\n";
	char str2[] = "Hello There guy!Hello There guy!\n\0\n Hello!";

	ft_print_memory(str2, 32-2);
	printf("\n\n");

	ft_print_memory(str2, 32-1);
	printf("\n\n");

	ft_print_memory(str2, 32);
	printf("\n\n");

	ft_print_memory(str2, 32+1);
	printf("\n\n");

	ft_print_memory(str2, 32+2);
	printf("\n\n");

	ft_print_memory(str2, 32+3);
	printf("\n\n");
*/
	return (0);
}
