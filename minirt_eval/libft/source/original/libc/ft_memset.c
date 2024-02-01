/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:18:39 by donghyu2          #+#    #+#             */
/*   Updated: 2022/12/18 18:40:03 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*b_c;
	unsigned char	c_c;

	b_c = (unsigned char *)b;
	c_c = (unsigned char)c;
	while (len > 0)
	{
		*b_c++ = c_c;
		len--;
	}
	return (b);
}
