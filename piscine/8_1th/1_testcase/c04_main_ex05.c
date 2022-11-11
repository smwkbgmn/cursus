/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c04_main_ex05.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 21:07:09 by donghyu2          #+#    #+#             */
/*   Updated: 2022/09/01 20:43:26 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

#include "ex05/ft_atoi_base.c"

int	main(void)
{
	char base[50];
	char str_num[50];
	int num;

	// ex05
	printf("\n[ex05]\n");

	strcpy(base, "12");
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
	
	return (0);
}
