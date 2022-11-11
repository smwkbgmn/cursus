/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c00_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 12:54:01 by donghyu2          #+#    #+#             */
/*   Updated: 2022/08/25 16:31:05 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
/*
#include "./ex00/ft_putchar.c"
#include "./ex01/ft_print_alphabet.c"
#include "./ex02/ft_print_reverse_alphabet.c"
#include "./ex03/ft_print_numbers.c"
#include "./ex04/ft_is_negative.c"
#include "./ex05/ft_print_comb.c"
#include "./ex06/ft_print_comb2.c"*/
#include "./ex07/ft_putnbr.c"
#include "./ex08/ft_print_combn.c"

int	main()
{
/*	// ex00
	printf("[ex00]\n");
	char	c = 'a';
	ft_putchar(c);
	printf("\n\n");

	// ex01
	printf("[ex01]\n");
	ft_print_alphabet();	
	printf("\n\n");

	// ex02
	printf("[ex02]\n");
	ft_print_reverse_alphabet();
	printf("\n\n");

	// ex03
	printf("[ex03]\n");
	ft_print_numbers();
	printf("\n\n");

	// ex04
	printf("[ex04]\n");
	int	n = 1;
	printf(" (n = 1)");
	ft_is_negative(n);
	printf("\n");

	n = -1;
	printf(" (n = -1)");
	ft_is_negative(n);
	printf("\n");

	n = 0;
	printf(" (n = 0)");
	ft_is_negative(n);
	printf("\n\n");

	// ex05
	printf("[ex05]\n");
	ft_print_comb();
	printf("\n\n");

	// ex06
	printf("[ex06]\n");
	ft_print_comb2();
	printf("\n\n");

*/	// ex07
	int n;
	printf("[ex07]\n");

	n = -2147483648;
	ft_putnbr(n);
	printf(" = -2147483648\n");

	n = -1356;
	ft_putnbr(n);
	printf(" = -1356\n");

	n = 0;
	ft_putnbr(n);
	printf(" = 0\n");

	n = 1356;
	ft_putnbr(n);
	printf(" = 1356\n");

	n = 2147483647;
	ft_putnbr(n);
	printf(" = 2147483647\n\n");

	// ex08
	printf("[ex08]\n");
	ft_print_combn(1);
	printf(" (n=1)\n\n");

	ft_print_combn(5);
	printf(" (n=5)\n\n");

	ft_print_combn(9);
	printf(" (n=9)\n\n");
}
