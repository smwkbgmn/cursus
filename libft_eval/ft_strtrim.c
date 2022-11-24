/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:13:04 by donghyu2          #+#    #+#             */
/*   Updated: 2022/11/24 15:26:43 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char		*find_end(const char *s1, const char *set, char *start);
static int		is_set(const char c, char const *set);
static size_t	get_len(char *start, char *end);
static char		*fill_result(char *result, char *start, char *end);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	char	*start;
	char	*end;

	while (is_set(*s1, set) == 1)
		s1++;
	if (*s1 == 0)
		return ((char *)ft_calloc(1, 1));
	start = (char *)s1;
	end = find_end(s1, set, start);
	result = malloc(get_len(start, end) + 1);
	if (!result)
		return (0);
	return (fill_result(result, start, end));
}		

static char	*find_end(const char *s1, const char *set, char *start)
{
	while (*(s1 + 1))
		s1++;
	while (is_set(*s1, set) == 1 && s1 != start)
		s1--;
	return ((char *)s1);
}

static int	is_set(const char c, char const *set)
{
	while (*set != c && *set)
		set++;
	if (*set != 0)
		return (1);
	else
		return (0);
}

static size_t	get_len(char *start, char *end)
{
	size_t	len;

	len = 0;
	while (start++ <= end)
		len++;
	return (len);
}

static char	*fill_result(char *result, char *start, char *end)
{
	size_t	idx;

	idx = 0;
	while (start <= end)
		result[idx++] = *(char *)start++;
	result[idx] = 0;
	return (result);
}
