/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 21:44:58 by donghyu2          #+#    #+#             */
/*   Updated: 2022/09/06 01:22:53 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	idx;
	int	size;

	size = max - min;
	if (min >= max)
	{
		*range = (void *)0;
		return (0);
	}
	*range = (int *)malloc(sizeof(int) * size);
	if (range == 0)
		return (-1);
	idx = 0;
	while (min < max)
	{
		range[0][idx] = min;
		idx++;
		min++;
	}
	return (size);
}
