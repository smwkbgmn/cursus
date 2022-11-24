/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:13:07 by donghyu2          #+#    #+#             */
/*   Updated: 2022/11/24 15:28:09 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	*fill_rst(const char *s, char *result, long start, size_t size_r);

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
	return (fill_rst(s, result, start, size_r));
}

static char	*fill_rst(const char *s, char *result, long start, size_t size_r)
{
	size_t	idx;

	idx = 0;
	while (s[start] && idx < size_r)
		result[idx++] = s[start++];
	result[idx] = 0;
	return (result);
}
