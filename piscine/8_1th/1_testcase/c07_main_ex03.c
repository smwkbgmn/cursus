/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c07_main_ex03.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 00:23:39 by donghyu2          #+#    #+#             */
/*   Updated: 2022/09/06 00:56:58 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char *ft_strjoin(int size, char **strs, char *sep);

int main(int argc, char **argv)
{
	char *str;
	int idx;
	
	if (argc < 2)
		return (0);

	argv++; 

	idx = 0;
	while (argv[idx])
		idx++;

	str = ft_strjoin(idx, argv, ", ");
	printf("%s\n", str);

	str = ft_strjoin(0, argv, ", ");
	printf("%s\n", str);

	return (0);
}
