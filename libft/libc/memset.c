/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:18:39 by donghyu2          #+#    #+#             */
/*   Updated: 2022/11/11 16:18:41 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char			*b_casted;
	unsigned char	c_casted;
	
	b_casted = (char)b;
	c_casted = (unsigned char)c;
	while (len-- > 0 && *b_casted)
		*b_casted = c_casted;
	return (b);
}