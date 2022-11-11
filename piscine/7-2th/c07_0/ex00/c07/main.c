/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main07.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 15:01:39 by gaeokim           #+#    #+#             */
/*   Updated: 2022/06/09 20:20:15 by donghki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex00/ft_strdup.c"
#include "ex01/ft_range.c"
#include "ex02/ft_ultimate_range.c"
#include "ex03/ft_strjoin.c"
#include "ex04/ft_convert_base.c"
#include "ex04/ft_convert_base2.c"
#include "ex05/ft_split.c"

#include <stdio.h>
#include <string.h> 

int main()
{
	char *temp;
	{
		printf("======ex00======\n");
		char str[50] = "hello world";
		temp = ft_strdup(str);
		printf("%s %s\n", strdup(str), temp);
		free ((char*)temp);
	}
	{
		printf("======ex01======\n");
		int *arr = ft_range(3, 5);
		int i = 0;
		while (arr[i] != '\0')
		{
			printf("%d ", arr[i]);
			i++;
		}
		printf("\n");
	}
	{
		printf("======ex02======\n");
		int *arr;
		printf("%d\n", ft_ultimate_range(&arr, -5, 3));
		int n = 0;
		while (n < 8)
		{
			printf ("%d\n", arr[n]);
			n++;
		}
	}
	
/*	{
		printf("======ex03======\n");
		char *strs[] = {"hello","4242", "world","gaeon", "nojam"};
		char sep[10] = " : ";
		int	size = 5;
		printf("%s\n", ft_strjoin(size, strs, sep));
	}
	{
		printf("======ex04======\n");
		char str[5] = "101";
		char base_form[10] = "01";
		char base_to[10] = "01234";
		printf("%s\n", ft_convert_base(str, base_form, base_to));

	}
	{
		printf("======ex05======\n");
		char charset[10] = "!@#$^&";
		char str[100] = "hello!world!!@happy#thurs^&day";
		char **strs = ft_split(str, charset);
		int i = 0;
		while (strs[i] != NULL)
		{
			printf("%s\n", strs[i]);
			i++;
		}
	}*/
}

