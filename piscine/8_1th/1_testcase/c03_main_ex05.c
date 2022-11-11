/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c03_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 13:39:47 by donghyu2          #+#    #+#             */
/*   Updated: 2022/08/31 17:30:29 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

#include "ex05/ft_strlcat.c"

int	main(void)
{
	// ex05
	int n, rt1, rt2;
	
	char de3[50] = "empty";
	char de4[50] = "empty";
	char def[] = "empty";
	char src4[] = "1234";

	printf("\n[ex05]\n");

	strcpy(de3, def);
	strcpy(de4, def);
	n = 0;
	rt1 = strlcat(de3, src4, n);
	rt2 = ft_strlcat(de4, src4, n);
	printf("%s : %s (n=%d) %d, %d\n", de3, de4, n, rt1, rt2);

	strcpy(de3, def);
	strcpy(de4, def);
	n = 1;
	rt1 = strlcat(de3, src4, n);
	rt2 = ft_strlcat(de4, src4, n);
	printf("%s : %s (n=%d) %d, %d\n", de3, de4, n, rt1, rt2);

	strcpy(de3, def);
	strcpy(de4, def);
	n = 2;
	rt1 = strlcat(de3, src4, n);
	rt2 = ft_strlcat(de4, src4, n);
	printf("%s : %s (n=%d) %d, %d\n", de3, de4, n, rt1, rt2);

	strcpy(de3, def);
	strcpy(de4, def);
	n = 3;
	rt1 = strlcat(de3, src4, n);
	rt2 = ft_strlcat(de4, src4, n);
	printf("%s : %s (n=%d) %d, %d\n", de3, de4, n, rt1, rt2);

	strcpy(de3, def);
	strcpy(de4, def);
	n = 4;
	rt1 = strlcat(de3, src4, n);
	rt2 = ft_strlcat(de4, src4, n);
	printf("%s : %s (n=%d) %d, %d\n", de3, de4, n, rt1, rt2);

	strcpy(de3, def);
	strcpy(de4, def);
	n = 5;
	rt1 = strlcat(de3, src4, n);
	rt2 = ft_strlcat(de4, src4, n);
	printf("%s : %s (n=%d) %d, %d\n", de3, de4, n, rt1, rt2);

	strcpy(de3, def);
	strcpy(de4, def);
	n = 6;
	rt1 = strlcat(de3, src4, n);
	rt2 = ft_strlcat(de4, src4, n);
	printf("%s : %s (n=%d) %d, %d\n", de3, de4, n, rt1, rt2);

	strcpy(de3, def);
	strcpy(de4, def);
	n = 7;
	rt1 = strlcat(de3, src4, n);
	rt2 = ft_strlcat(de4, src4, n);
	printf("%s : %s (n=%d) %d, %d\n", de3, de4, n, rt1, rt2);

	strcpy(de3, def);
	strcpy(de4, def);
	n = 10;
	rt1 = strlcat(de3, src4, n);
	rt2 = ft_strlcat(de4, src4, n);
	printf("%s : %s (n=%d) %d, %d\n", de3, de4, n, rt1, rt2);

	return (0);
}

