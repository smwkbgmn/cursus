/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c07_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 22:20:55 by donghyu2          #+#    #+#             */
/*   Updated: 2022/09/06 00:22:12 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "ex00/ft_strdup.c"
#include "ex01/ft_range.c"
#include "ex02/ft_ultimate_range.c"

int	main(void)
{
	char str[30];
	char *org;
	char *ft;

	strcpy(str, "Hello World");
	org = strdup(str);
	ft = ft_strdup(str);
	printf("%s\n||\n%s\n\n", org, ft);

	strcpy(str, "\0");
	org = strdup(str);
	ft = ft_strdup(str);
	printf("%s\n||\n%s\n\n", org, ft);

	free(org);
	free(ft);

//////////////////////////////////////////////////////////

	int *range;
	int idx;

	range = ft_range(3, 10);
	idx = 0;
	while (idx < 7)
		printf("%d ", range[idx++]);
	printf("\n\n");
		
	range = ft_range(-3, 3);
	idx = 0;
	while (idx < 6)
		printf("%d ", range[idx++]);
	printf("\n\n");
		
	range = ft_range(-10, -3);
	idx = 0;
	while (idx < 7)
		printf("%d ", range[idx++]);
	printf("\n\n");

	free(range);

//////////////////////////////////////////////////////////

	int *dp_range;

	dp_range = (int *)malloc(sizeof(int));

	ft_ultimate_range(&dp_range, 3, 10);
	idx = 0;
	while (idx < 7)
		printf("%d ", dp_range[idx++]);
	printf("\n\n");
		
	ft_ultimate_range(&dp_range, -3, 3);
	idx = 0;
	while (idx < 6)
		printf("%d ", dp_range[idx++]);
	printf("\n\n");
		
	ft_ultimate_range(&dp_range, -10, -3);
	idx = 0;
	while (idx < 7)
		printf("%d ", dp_range[idx++]);
	printf("\n\n");
		
	free(dp_range);

	return (0);
}
