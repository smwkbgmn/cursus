/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:53:50 by donghyu2          #+#    #+#             */
/*   Updated: 2022/11/23 17:55:13 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1_c;
	const unsigned char	*s2_c;

	s1_c = (const unsigned char *)s1;
	s2_c = (const unsigned char *)s2;
	if (n == 0)
		return (0);
	while (n > 0 && *s1_c++ == *s2_c++)
		n--;
	return (*(s1_c - 1) - *(s2_c - 1));
}
