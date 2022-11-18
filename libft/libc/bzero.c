/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bzero.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:13:16 by donghyu2          #+#    #+#             */
/*   Updated: 2022/11/19 03:20:52 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

static void	*ft_memset(void *b, int c, size_t len);

void	ft_bzero(void *s, size_t n)
{
	if (n == 0)
		return ;
	ft_memset(s, 0, n);
}

static void	*ft_memset(void *b, int c, size_t len)
{
	char	*b_c;
	unsigned char	c_c;
	
	b_c = (char *)b;
	c_c = (unsigned char)c;
	while (len > 0 && *b_c)
	{
		*b_c++ = c_c;
		len--;
	}
	return (b);
}