/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmpi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:13:00 by donghyu2          #+#    #+#             */
/*   Updated: 2023/01/04 12:39:29 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*result;
	unsigned int		idx;

	result = malloc(ft_strlen(s) + 1);
	if (result)
	{
		idx = 0;
		while (*s)
		{
			result[idx] = f(idx, *s);
			idx++;
			s++;
		}
		result[idx] = 0;
	}
	return (result);
}
