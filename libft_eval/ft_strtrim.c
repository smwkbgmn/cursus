/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:13:04 by donghyu2          #+#    #+#             */
/*   Updated: 2022/12/15 18:08:40 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char		*find_start(const char *s1, const char *set);
static char		*find_end(char *start, const char *set);
static int		is_set(char c, const char *set);
static size_t	get_len(char *start, char *end);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	char	*start;
	char	*end;

	if (!s1 || !set)
		return (0);
	start = find_start(s1, set);
	if (*start == 0)
		return ((char *)ft_calloc(1, 1));
	end = find_end(start, set);
	result = malloc(get_len(start, end) + 1);
	if (!result)
		return (0);
	ft_strlcpy(result, start, get_len(start, end) + 1);
	return (result);
}

static char	*find_start(const char *s1, const char *set)
{
	while (is_set(*s1, set) == 1)
		s1++;
	return ((char *)s1);
}

static char	*find_end(char *start, const char *set)
{
	char	*ptr;

	ptr = start;
	while (*(ptr + 1))
		ptr++;
	while (is_set(*ptr, set) == 1 && ptr != start)
		ptr--;
	return ((char *)ptr);
}

static int	is_set(char letter, char const *set)
{
	while (*set != letter && *set)
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
