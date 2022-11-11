/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c04_main_ex03.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 21:07:09 by donghyu2          #+#    #+#             */
/*   Updated: 2022/09/01 20:30:36 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

#include "ex03/ft_atoi.c"
//#include "ex04/ft_putnbr_base.c"
//#include "ex05/ft_atoi_base.c"

int	main(void)
{
	// ex03
	printf("\n[ex03]\n");
	char str_num[50];
	int num;

	strcpy(str_num, "-2147483648");
	num = ft_atoi(str_num);
	printf("input : %s\natoi_num : %d\n\n", str_num, num);

	strcpy(str_num, "-345");
	num = ft_atoi(str_num);
	printf("input : %s\natoi_num : %d\n\n", str_num, num);

	strcpy(str_num, "0");
	num = ft_atoi(str_num);
	printf("input : %s\natoi_num : %d\n\n", str_num, num);

	strcpy(str_num, "345");
	num = ft_atoi(str_num);
	printf("input : %s\natoi_num : %d\n\n", str_num, num);

	strcpy(str_num, "2147483647");
	num = ft_atoi(str_num);
	printf("input : %s\natoi_num : %d\n\n", str_num, num);
	
	strcpy(str_num, "2147483650");
	num = ft_atoi(str_num);
	printf("input : %s\natoi_num : %d\n\n", str_num, num);
	
	strcpy(str_num, "+-+123");
	num = ft_atoi(str_num);
	printf("input : %s\natoi_num : %d\n\n", str_num, num);
	
	strcpy(str_num, " 123");
	num = ft_atoi(str_num);
	printf("input : %s\natoi_num : %d\n\n", str_num, num);
	
	strcpy(str_num, "---123ab123");
	num = ft_atoi(str_num);
	printf("input : %s\natoi_num : %d\n\n", str_num, num);
	
	strcpy(str_num, "-a-a-123ab123");
	num = ft_atoi(str_num);
	printf("input : %s\natoi_num : %d\n\n", str_num, num);
	
	return (0);
}
