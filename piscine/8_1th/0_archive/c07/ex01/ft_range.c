/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 21:36:06 by donghyu2          #+#    #+#             */
/*   Updated: 2022/09/05 23:18:16 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*num;
	int	idx;

	if (min >= max)
		return ((void *)0);
	num = (int *)malloc(sizeof(int) * (max - min));
	if (num == 0)
		return (0);
	idx = 0;
	while (min < max)
	{
		num[idx] = min;
		idx++;
		min++;
	}
	return (num);
}
