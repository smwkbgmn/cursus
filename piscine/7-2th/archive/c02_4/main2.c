/* ************************************************************************** */
/*                                                                            */
/*                                                       ::     :::::::   */
/*   main.c                                            +:     +:   +:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghki2 <donghki2@student.42seoul:        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:27:15 by donghki2          #+#    #+#             */
/*   Updated: 2022/06/01 17:46:18 by donghki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "./ex00/ft_strcpy.c"
#include "./ex01/ft_strncpy.c"
#include "./ex02/ft_str_is_alpha.c"
#include "./ex03/ft_str_is_numeric.c"
#include "./ex04/ft_str_is_lowercase.c"
#include "./ex05/ft_str_is_uppercase.c"
#include "./ex06/ft_str_is_printable.c"
#include "./ex07/ft_strupcase.c"
#include "./ex08/ft_strlowcase.c"
#include "./ex09/ft_strcapitalize.c"
#include "./ex10/ft_strlcpy.c"
#include "./ex11/ft_putstr_non_printable.c"
#include "./ex12/ft_print_memory.c"

void printStr(char *Str);

int main(int argc, char *testInput[50])
{
	char testStr[50];
	char testStr1[50] = "Test String1";
	char testStr2[50] = "aaaaaaaaaaaaa";
	char testStr3[50] = "aaaaaaaaaaaaa";
	char testStr4[50] = "ABcd";
	char testStr5[50] = "Ab65";
	char testStr6[50] = "";
	char testStr7[50] = "12345";
	char testStr8[50] = "abc123def";
	char testStr9[50] = "abcde";
	char testStr10[50] = "ABCDE";
	char testStr11[50] = {'1', 'a', 1};
	char testStr12[50] = "Coucou\ntu vas bien ?";
	char testStr13[] = "Bonjour les aminches\t\n\tc  est fou\ttout\tce qu on peut faire avec\t\n\tprint_memory\n\n\n\tlol.lol\n ";
	char testStr14[50] = "abc";

	int result;

/*
	// Ex00
	printf("\nEx00 Target String : ");
	printStr(testStr1);
	printf("\n");
	
	ft_strcpy(testStr2, testStr1);
	printf("After strcpy() : ");
	printStr(testStr2);
	printf("\n");

	// Ex01
	printf("\nEx01 Target String : ");
	printStr(testStr1);
	printf("\n");
	
	ft_strncpy(testStr3, testStr1, 5);
	printf("After srtncpy(size5) : ");
	printStr(testStr3);
	printf("\n");

	// Ex02
	printf("\n[Ex02 Alpha]\n");
	
	result = ft_str_is_alpha(testStr4);
	printf("ABcd : %d\n", result);

	result = ft_str_is_alpha(testStr5);
	printf("Ab65 : %d\n", result);
	
	result = ft_str_is_alpha(testStr6);
	printf("[empty] : %d\n", result);

	// Ex03
	printf ("\n[Ex03 Numeric]\n");

	result = ft_str_is_numeric(testStr7);
	printf ("12345 : %d\n", result);

	result = ft_str_is_numeric(testStr8);
	printf ("abc123def : %d\n", result);

	result = ft_str_is_numeric(testStr6);
	printf ("[empty] : %d\n", result);

	// Ex04
	printf ("\n[Ex04 Lowercase]\n");

	result = ft_str_is_lowercase(testStr4);
	printf ("ABcd : %d\n", result);

	result = ft_str_is_lowercase(testStr9);
	printf ("abcde : %d\n", result);

	result = ft_str_is_lowercase(testStr6);
	printf ("[empty] : %d\n", result);

	// Ex05
	printf ("\n[Ex05 Uppercase]\n");

	result = ft_str_is_uppercase(testStr4);
	printf ("ABcd : %d\n", result);

	result = ft_str_is_uppercase(testStr10);
	printf ("ABCDE : %d\n", result);

	result = ft_str_is_uppercase(testStr6);
	printf ("[empty] : %d\n", result);

	// Ex06
	printf ("\n[Ex06 Printable]\n");
	
	result = ft_str_is_printable(testStr10);
	printf ("ABCDE : %d\n", result);

	result = ft_str_is_printable(testStr11);
	printf ("(SOH)1a : %d\n", result);

	result = ft_str_is_printable(testStr6);	
	printf ("[empty] : %d\n", result);

	// Ex07
	printf ("\n[Ex07 Upcase]\n");

	printf ("ABcd : ");
	ft_strupcase (testStr4);
	printStr (testStr4);
	printf ("\n");

	printf ("abc123def : ");
	ft_strupcase (testStr8);
	printStr (testStr8);
	printf ("\n");

	// Ex08
	printf ("\n[Ex08 Lowcacse]\n");

	printf ("ABcd : ");
	ft_strlowcase (testStr4);
	printStr (testStr4);
	printf ("\n");

	printf ("ABCDE : ");
	ft_strlowcase (testStr10);
	printStr (testStr10);
	printf ("\n");

	// Ex09
	printf ("\n[Ex09 Capitalize]\n");

	printStr (*(testInput + 1));
	printf (" : ");
	ft_strcapitalize (*(testInput + 1));
	printStr (*(testInput + 1));
	printf ("\n");

	// Ex10
	printf ("\n[Ex10 strlcpy]\n");

	result = ft_strlcpy (testStr, *(testInput + 1), 6);
	printf ("Copy 5 characters from begining of input string\n");
	printStr (*(testInput + 1));
	printf (" : ");
	printStr (testStr);
	printf ("\n");
	printf ("Return %d\n", result);
*/
	// Ex11
	printf ("\n[Ex11 putstr_non_printable]\n");
	printStr (testStr12);
	printf ("\n");
	ft_putstr_non_printable (testStr12);
	printf ("\n");

	// Ex12
	//ft_print_memory (testStr13, sizeof(testStr13));

	return 0;
}


void printStr(char *Str)
{
	int Cnt = 0;

	while (Str[Cnt] > 0)
	{
		printf("%c", Str[Cnt]);
		Cnt++;
	}
}
