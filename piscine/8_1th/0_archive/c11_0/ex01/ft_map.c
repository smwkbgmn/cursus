/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 23:27:38 by donghyu2          #+#    #+#             */
/*   Updated: 2022/09/12 18:31:35 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*mapped;
	int	idx;

	mapped = (int *)malloc(sizeof(int) * length);
	idx = 0;
	while (idx < length)
	{
		mapped[idx] = (*f)(tab[idx]);
		idx++;
	}
	return (mapped);
}
