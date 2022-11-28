/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:13:07 by donghyu2          #+#    #+#             */
/*   Updated: 2022/11/26 02:25:20 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	size_s;
	size_t	size_r;

	size_s = ft_strlen(s);
	if (start >= size_s || len == 0)
		return (ft_calloc(1, 1));
	if (size_s - start < len)
		size_r = size_s - start;
	else
		size_r = len;
	result = malloc(size_r + 1);
	if (!result)
		return (0);
	ft_strlcpy(result, s + start, size_r + 1);
	return (result);
}
