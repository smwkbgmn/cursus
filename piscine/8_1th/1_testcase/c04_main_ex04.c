/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c04_main_ex04.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 21:07:09 by donghyu2          #+#    #+#             */
/*   Updated: 2022/09/01 20:24:29 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

//#include "ex03/ft_atoi.c"
#include "ex04/ft_putnbr_base.c"
//#include "ex05/ft_atoi_base.c"

int	main(void)
{
	char base[50];
	int n1 = -2147483648;
	int n2 = -345;
	int n3 = 0;
	int n4 = 345;
	int n5 = 2147483647;

	// ex03
	//printf("\n[ex03]\n");
	//char str_num[50];
	//int num;
/*	
	strcpy(str_num, "-2147483648");
	num = ft_atoi(str_num);
	printf("input : %s, atoi_num : %d\n", str_num, num);

	strcpy(str_num, "-345");
	num = ft_atoi(str_num);
	printf("input : %s, atoi_num : %d\n", str_num, num);

	strcpy(str_num, "0");
	num = ft_atoi(str_num);
	printf("input : %s, atoi_num : %d\n", str_num, num);

	strcpy(str_num, "345");
	num = ft_atoi(str_num);
	printf("input : %s, atoi_num : %d\n", str_num, num);

	strcpy(str_num, "2147483647");
	num = ft_atoi(str_num);
	printf("input : %s, atoi_num : %d\n", str_num, num);
	
	strcpy(str_num, "2147483650");
	num = ft_atoi(str_num);
	printf("input : %s, atoi_num : %d\n", str_num, num);
	*/
	// ex04
	printf("\n[ex04]\n");

	strcpy(base, "abc");
	printf("base : %s\n\n", base);

	printf("input : %d\n", n1);
	ft_putnbr_base(n1, base);
	printf("\n");

	printf("input : %d\n", n2);
	ft_putnbr_base(n2, base);
	printf("\n");

	printf("input : %d\n", n3);
	ft_putnbr_base(n3, base);
	printf("\n");
	
	printf("input : %d\n", n4);
	ft_putnbr_base(n4, base);
	printf("\n");

	printf("input : %d\n", n5);
	ft_putnbr_base(n5, base);
	printf("\n");

/*	// ex05
	printf("\n[ex05]\n");
	
	
	strcpy(base, "0123456789");
	printf("base : %s\n\n", base);

	strcpy(str_num, "-2147483648");
	num = ft_atoi_base(str_num, base);
	printf("input : %s, atoi_num : %d\n", str_num, num);

	strcpy(str_num, "-345");
	num = ft_atoi_base(str_num, base);
	printf("input : %s, atoi_num : %d\n", str_num, num);

	strcpy(str_num, "0");
	num = ft_atoi_base(str_num, base);
	printf("input : %s, atoi_num : %d\n", str_num, num);

	strcpy(str_num, "345");
	num = ft_atoi_base(str_num, base);
	printf("input : %s, atoi_num : %d\n", str_num, num);

	strcpy(str_num, "2147483647");
	num = ft_atoi_base(str_num, base);
	printf("input : %s, atoi_num : %d\n", str_num, num);
*/	
	return (0);
}
