/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c05_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 14:02:24 by donghyu2          #+#    #+#             */
/*   Updated: 2022/09/04 00:19:16 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "ex00/ft_iterative_factorial.c"
#include "ex01/ft_recursive_factorial.c"
#include "ex02/ft_iterative_power.c"
#include "ex03/ft_recursive_power.c"
#include "ex04/ft_fibonacci.c"
#include "ex05/ft_sqrt.c"
#include "ex06/ft_is_prime.c"
//#include "ex07/ft_find_next_prime.c"

int	main(void)
{
	// ex00
	printf("\n[ex00]\n");

	int n;
	
	n = ft_iterative_factorial(-1);
	printf("0 : %d\n\n", n);

	n = ft_iterative_factorial(0);
	printf("1 : %d\n\n", n);
	
	n = ft_iterative_factorial(1);
	printf("1 : %d\n\n", n);
	
	n = ft_iterative_factorial(2);
	printf("2 : %d\n\n", n);
	
	n = ft_iterative_factorial(5);
	printf("120 : %d\n\n", n);
	
	n = ft_iterative_factorial(7);
	printf("5040 : %d\n\n", n);

	// ex01
	printf("\n[ex01]\n");

	n = ft_recursive_factorial(-1);
	printf("0 : %d\n\n", n);

	n = ft_recursive_factorial(0);
	printf("1 : %d\n\n", n);
	
	n = ft_recursive_factorial(1);
	printf("1 : %d\n\n", n);
	
	n = ft_recursive_factorial(2);
	printf("2 : %d\n\n", n);
	
	n = ft_recursive_factorial(5);
	printf("120 : %d\n\n", n);
	
	n = ft_recursive_factorial(7);
	printf("5040 : %d\n\n", n);
	
	// ex02
	printf("\n[ex02]\n");
	
	int m;
	
	n = 0;
	m = 0;
	printf("input %d, %d\n", n, m);
	n = ft_iterative_power(n, m);
	printf("1 : %d\n\n", n);
	
	n = 1;
	m = 0;
	printf("input %d, %d\n", n, m);
	n = ft_iterative_power(n, m);
	printf("1 : %d\n\n", n);
	
	n = 2;
	m = 1;
	printf("input %d, %d\n", n, m);
	n = ft_iterative_power(n, m);
	printf("2 : %d\n\n", n);
	
	n = 2;
	m = 5;
	printf("input %d, %d\n", n, m);
	n = ft_iterative_power(n, m);
	printf("32 : %d\n\n", n);
	
	// ex03
	printf("\n[ex03]\n");
	
	n = 0;
	m = 0;
	printf("input %d, %d\n", n, m);
	n = ft_recursive_power(n, m);
	printf("1 : %d\n\n", n);
	
	n = 1;
	m = 0;
	printf("input %d, %d\n", n, m);
	n = ft_recursive_power(n, m);
	printf("1 : %d\n\n", n);
	
	n = 2;
	m = 1;
	printf("input %d, %d\n", n, m);
	n = ft_recursive_power(n, m);
	printf("2 : %d\n\n", n);
	
	n = 2;
	m = 5;
	printf("input %d, %d\n", n, m);
	n = ft_recursive_power(n, m);
	printf("32 : %d\n\n", n);
	
	// ex04
	printf("\n[ex04]\n");

	n = ft_fibonacci(-1);
	printf("-1 : %d\n", n);
	
	n = ft_fibonacci(0);
	printf("0 : %d\n", n);
	
	n = ft_fibonacci(1);
	printf("1 : %d\n", n);
	
	n = ft_fibonacci(2);
	printf("1 : %d\n", n);
	
	n = ft_fibonacci(3);
	printf("2 : %d\n", n);
	
	n = ft_fibonacci(4);
	printf("3 : %d\n", n);
	
	n = ft_fibonacci(5);
	printf("5 : %d\n", n);

	// ex05
	printf("\n[ex05]\n");
	
	n = ft_sqrt(0);
	printf("0 : %d\n", n);

	n = ft_sqrt(1);
	printf("1 : %d\n", n);

	n = ft_sqrt(2);
	printf("0 : %d\n", n);

	n = ft_sqrt(4);
	printf("2 : %d\n", n);

	n = ft_sqrt(-5);
	printf("0 : %d\n", n);

	n = ft_sqrt(2147483647);
	printf("0 : %d\n", n);

	n = ft_sqrt(1600000000);
	printf("40000 : %d\n", n);

	// ex06
	printf("\n[ex06]\n");
	
	n = ft_is_prime(0);
	printf("0 : %d\n", n);
	
	n = ft_is_prime(1);
	printf("0 : %d\n", n);
	
	n = ft_is_prime(2);
	printf("1 : %d\n", n);
	
	n = ft_is_prime(3);
	printf("1 : %d\n", n);
	
	n = ft_is_prime(15);
	printf("0 : %d\n", n);
	
	n = ft_is_prime(19);
	printf("1 : %d\n", n);
/*
	// ex07
	printf("\n[ex07]\n");
	
	n = ft_find_next_prime(0);
	printf("2 : %d\n", n);
	
	n = ft_find_next_prime(1);
	printf("2 : %d\n", n);
	
	n = ft_find_next_prime(2);
	printf("2 : %d\n", n);
	
	n = ft_find_next_prime(3);
	printf("3 : %d\n", n);
	
	n = ft_find_next_prime(4);
	printf("5 : %d\n", n);
	
	n = ft_find_next_prime(9);
	printf("11 : %d\n", n);
	
	n = ft_find_next_prime(2147483647);
	printf("2147483647 : %d\n", n);
*/	

	return (0);
}
