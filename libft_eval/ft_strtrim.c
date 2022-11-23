/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:13:04 by donghyu2          #+#    #+#             */
/*   Updated: 2022/11/24 01:25:32 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char		*find_start_end(const char *s1, const char *set, int flag);
static int		is_set(const char c, char const *set);
static char		*fill_rst(char *result, char *start, char *end);
static size_t	get_len(char *start, char *end);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	char	*start;
	char	*end;

	while (is_set(*s1, set) == 1)
		s1++;
	if (*s1 == 0)
	{
		result = malloc(1);
		if (!result)
			return (0);
		*result = 0;
		return (result);
	}
	start = find_start_end(s1, set, 0);
	end = find_start_end(s1, set, 1);
	result = malloc(get_len(start, end) + 1);
	if (!result)
		return (0);
	return (fill_rst(result, start, end));
}		

static char	*find_start_end(const char *s1, const char *set, int flag)
{
	char	*start;

	while (is_set(*s1, set) == 1 && *(s1 + 1))
		s1++;
	if (flag == 0)
		return ((char *)s1);
	start = (char *)s1;
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

static char	*fill_rst(char *result, char *start, char *end)
{
	size_t	idx;

	idx = 0;
	while (start <= end)
		result[idx++] = *(char *)start++;
	result[idx] = 0;
	return (result);
}

static size_t	get_len(char *start, char *end)
{
	size_t	len;

	len = 0;
	while (start++ <= end)
		len++;
	return (len);
}
