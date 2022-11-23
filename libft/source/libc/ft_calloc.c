/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 23:43:45 by donghyu2          #+#    #+#             */
/*   Updated: 2022/11/23 22:37:59 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	*set_zero(void *ptr, size_t size);

void	*ft_calloc(size_t count, size_t size)
{
	if (count == 0 || size == 0)
		return (0);
	else
		return (set_zero(malloc(count * size), count * size));
}

static void	*set_zero(void *ptr, size_t size)
{
	char	*ptr_cast;

	if (!ptr)
		return (0);
	ptr_cast = (char *)ptr;
	while (size > 0)
		ptr_cast[size--] = 0;
	return (ptr);
}
