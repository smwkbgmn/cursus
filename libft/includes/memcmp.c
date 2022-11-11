/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:26:25 by donghyu2          #+#    #+#             */
/*   Updated: 2022/11/11 16:48:25 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

int	memcmp(const void *s1, const void *s2, size_t n)
{
	// what should happen when the value of n is equal to zero?
	unsigned char	*s1_casted;
	unsigned char 	*s2_casted;

	if (n == 0)
		return (0);
	s1_casted = (char *)s1;
	s2_casted = (char *)s2; 
	while (*s1_casted == *s2_casted && n > 0)
	{
		if (*s1_casted == 0)
			return (0);
		s1_casted++;
		s2_casted++;
		n--;
	}
	return (*s1_casted -  *s2_casted);
}