/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:22:13 by donghyu2          #+#    #+#             */
/*   Updated: 2022/11/11 16:28:52 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void	*memchr(const void *s, int c, size_t n)
{
	char	*s_casted;
	char	c_casted;

	while (*s_casted != c_casted && n > 0 && *s_casted)
	{
		s_casted++;
		n--;
	}
	if (s_casted != 0)
		return ((void *)s_casted);
	else
		return (0);
}