/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 23:43:45 by donghyu2          #+#    #+#             */
/*   Updated: 2022/11/18 22:15:46 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

void	*set_zero(void *ptr, size_t size);

void	*ft_calloc(size_t count, size_t size)
{
	if (count == 0 || size == 0)
		return (set_zero(malloc(1), 1));
	else
		return (set_zero(malloc(count * size), count * size));
}

void	*set_zero(void *ptr, size_t size)
{
	char	*ptr_cast;

	if (!ptr)
		return (0);
	ptr_cast = (char *)ptr;
	while (size > 0)
		ptr_cast[size--] = 0;
	return (ptr);
}