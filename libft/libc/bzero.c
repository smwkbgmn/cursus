/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bzero.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:13:16 by donghyu2          #+#    #+#             */
/*   Updated: 2022/11/11 16:13:18 by donghyu2         ###   ########.fr       */
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
	char			*b_casted;
	unsigned char	c_casted;
	
	b_casted = (char)b;
	c_casted = (unsigned char)c;
	while (len-- > 0 && *b_casted)
		*b_casted = c_casted;
	return (b);
}