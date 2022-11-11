/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c01_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 18:03:54 by donghyu2          #+#    #+#             */
/*   Updated: 2022/08/25 20:38:15 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex00/ft_ft.c"
//#include "ex01/ft_ultimate_ft.c"
#include "ex02/ft_swap.c"
#include "ex03/ft_div_mod.c"
#include "ex04/ft_ultimate_div_mod.c"
#include "ex05/ft_putstr.c"
#include "ex06/ft_strlen.c"
#include "ex07/ft_rev_int_tab.c"
//#include "ex08/ft_sort_int_tab.c"

#include <stdio.h>

void	print_int(int *num);

int	main()
{
	int a;
	int b;
	int c;
	int d;
	int	n1[5] = {5, 4, 3, 2, 1};
//	int	n2[5] = {5, 4, 3, 2, 1};
//	int	n3[5] = {3, 1, 2, 5, 4};
//	int	n4[5] = {2, 1, 3, 1, 2};
	int	n5[5] = {0, -45, 31, 11, -1};
	char	str[30] = "Hello there baby";

	// ex00
	printf("[ex00]\n");
	ft_ft(&a);
	printf("42 : %d\n\n", a);

	// ex01
	printf("[ex01]\n");
	printf("Count '*', 9 is answer\n\n");

	// ex02
	printf("[ex02]\n");
	a = 5;
	b = 13;
	printf("Before swap %d %d\n", a, b);
	ft_swap(&a, &b);
	printf("After swap %d %d\n\n", a, b);

	// ex03
	printf("[ex03]\n");
	a = 16;
	b = 5;
	ft_div_mod(a, b, &c, &d);
	printf("A : %d, B : %d\nA/B : %d, AmB : %d\n\n", a, b, c, d);

	// ex04
	printf("[ex04]\n");
	printf("A : %d, B : %d\n", a, b);
	ft_ultimate_div_mod(&a, &b);
	printf("A/B : %d, AmB : %d\n\n", a, b);

	// ex05
	printf("[ex05]\n");
	ft_putstr(str);
	printf("\n\n");

	// ex06
	printf("[ex06]\n");
	a = ft_strlen(str);
	printf("16 : %d\n\n", a);

	// ex07
	printf("[ex07]\n");
	printf("Before reverse : ");
	print_int(n1);
	printf("\n");
	ft_rev_int_tab(n1, 5);
	printf("After reverse : ");
	print_int(n1);
	printf("\n\n");

	printf("Before reverse : ");
	print_int(n5);
	printf("\n");
	ft_rev_int_tab(n5, 5);
	printf("After reverse : ");
	print_int(n5);
	printf("\n\n");
/*	
	// ex08
	printf("[ex8]\n");
	print_int(n1);
	printf(">> ");
	ft_sort_int_tab(n1, 5);
	print_int(n1);
	printf("\n");

	print_int(n2);
	printf(">> ");
	ft_sort_int_tab(n2, 5);
	print_int(n2);
	printf("\n");

	print_int(n3);
	printf(">> ");
	ft_sort_int_tab(n3, 5);
	print_int(n3);
	printf("\n");

	print_int(n4);
	printf(">> ");
	ft_sort_int_tab(n4, 5);
	print_int(n4);
	printf("\n");

	print_int(n5);
	printf(">> ");
	ft_sort_int_tab(n5, 5);
	print_int(n5);
	printf("\n");
*/
	return (0);
}

void	print_int(int *num)
{
	int	idx;

	idx = 0;
	while (idx < 5)
	{
		printf("%d ", num[idx]);
		idx++;
	}
}

