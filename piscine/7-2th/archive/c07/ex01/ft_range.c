/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghki2 <donghki2@student.42seoul>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 18:43:34 by donghki2          #+#    #+#             */
/*   Updated: 2022/06/08 19:21:49 by donghki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int	idx;
	int size;
	int	*numbers;

	if (min >= max)
		return ((void*)0);
	if (min < 0)
		size = (max - min) * -1;
	else
		size = max - min;
	numbers = (int*) malloc (sizeof(int) * size);
	if (!numbers)
		return (numbers);
	idx = 0;
	while (min < max)
		numbers[idx++] = min++;
	return (numbers);
}
