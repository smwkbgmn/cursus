/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main05.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 21:20:32 by gaeokim           #+#    #+#             */
/*   Updated: 2022/06/09 00:24:17 by donghki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex00/ft_iterative_factorial.c"
#include "ex01/ft_recursive_factorial.c"
#include "ex02/ft_iterative_power.c"
#include "ex03/ft_recursive_power.c"
#include "ex04/ft_fibonacci.c"
#include "ex05/ft_sqrt.c"
#include "ex06/ft_is_prime.c"
#include "ex07/ft_find_next_prime.c"
//#include "ex08/ft_ten_queens_puzzle.c"

#include <stdio.h>


int main()
{
	{
		printf("======ex00======\n");
		printf("0 : %d\n", ft_iterative_factorial(-10));
		printf("1 : %d\n", ft_iterative_factorial(0));
		printf("1 : %d\n", ft_iterative_factorial(1));
		printf("3628800 : %d\n", ft_iterative_factorial(10));
	}
	{
		printf("======ex01======\n");
		printf("0 : %d\n", ft_recursive_factorial(-10));
		printf("1 : %d\n", ft_recursive_factorial(0));
		printf("1 : %d\n", ft_recursive_factorial(1));
		printf("3628800 : %d\n", ft_recursive_factorial(10));
	}
	{
		printf("======ex02======\n");
		printf("0 : %d\n", ft_iterative_power(-1, -1));
		printf("1 : %d\n", ft_iterative_power(-1, 2));
		printf("0 : %d\n", ft_iterative_power(2, -1));
		printf("1 : %d\n", ft_iterative_power(2, 0));
		printf("0 : %d\n", ft_iterative_power(0, 2));
		printf("1 : %d\n", ft_iterative_power(0, 0));
		printf("4 : %d\n", ft_iterative_power(2, 2));
		printf("-251658240 : %d\n", ft_iterative_power(12, 12));
	}
	{
		printf("======ex03======\n");
		printf("0 : %d\n", ft_recursive_power(-1, -1));
		printf("1 : %d\n", ft_recursive_power(-1, 2));
		printf("0 : %d\n", ft_recursive_power(2, -1));
		printf("1 : %d\n", ft_recursive_power(2, 0));
		printf("0 : %d\n", ft_recursive_power(0, 2));
		printf("1 : %d\n", ft_recursive_power(0, 0));
		printf("4 : %d\n", ft_recursive_power(2, 2));
		printf("-251658240 : %d\n", ft_recursive_power(12, 12));
	}
	{
		printf("======ex04======\n");
		printf("-1: %d\n", ft_fibonacci(-5));
		printf("0 : %d\n", ft_fibonacci(0));
		printf("1 : %d\n", ft_fibonacci(1));
		printf("55 : %d\n", ft_fibonacci(10));
	}
	{
		printf("======ex05======\n");
		printf("1 : %d\n", ft_sqrt(1));
		printf("0 : %d\n", ft_sqrt(2));
		printf("10 : %d\n", ft_sqrt(100));
		printf("0 : %d\n", ft_sqrt(2147483647));
	}
	{
		printf("======ex06======\n");
		printf("0 : %d\n", ft_is_prime(0));
		printf("0 : %d\n", ft_is_prime(1));
		printf("1 : %d\n", ft_is_prime(2));
		printf("0 : %d\n", ft_is_prime(10));
		printf("1 : %d\n", ft_is_prime(2147483647));
	}
	{
		printf("======ex07======\n");
		printf("2 : %d\n", ft_find_next_prime(0));
		printf("2 : %d\n", ft_find_next_prime(1));
		printf("2 : %d\n", ft_find_next_prime(2));
		printf("11 : %d\n", ft_find_next_prime(10));
		printf("11 : %d\n", ft_find_next_prime(11));
		printf("13 : %d\n", ft_find_next_prime(12));
		printf("3 : %d\n", ft_find_next_prime(3));
		printf("2147483647 : %d\n", ft_find_next_prime(2147483647));
	}
/*	{
		printf("======ex08======\n");
		printf("724 : %d\n", ft_ten_queens_puzzle());
	}*/
}
