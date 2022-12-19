/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmpi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:13:00 by donghyu2          #+#    #+#             */
/*   Updated: 2022/12/20 00:16:13 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

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
