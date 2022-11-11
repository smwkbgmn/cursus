/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c07_main_ex05.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 22:04:44 by donghyu2          #+#    #+#             */
/*   Updated: 2022/09/06 13:02:22 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char **ft_split(char *str, char *charset);

int	main(void)
{
	char str[] = "a, bcd1efg,w1 ,1123451\t\t  ";
	//char str[] = "a b,c , de  ";
	char sep[] = ", 1";
	char **split;

	split = ft_split(str, sep);
	printf("[a][bcd][efg][w][2345][\t\t] =\n");
	while (*split)
	{
		printf("[%s]", *split);
		split++;
	}
	return (0);
}
