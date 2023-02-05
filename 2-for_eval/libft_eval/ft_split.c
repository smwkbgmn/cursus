/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:12:25 by donghyu2          #+#    #+#             */
/*   Updated: 2022/11/26 02:12:53 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	**scissor(char const *s, char c, size_t cnt);
size_t	get_cnt_word(char const *s, char c);
size_t	get_len(char const *s, char c);
void	*free_malloc_failure(char **result, int p);

char	**ft_split(char const *s, char c)
{
	return (scissor(s, c, get_cnt_word(s, c)));
}

char	**scissor(char const *s, char c, size_t cnt)
{
	char	**result;
	size_t	p;
	size_t	pp;

	result = malloc(sizeof(char *) * (cnt + 1));
	if (result == 0)
		return (0);
	p = 0;
	while (p < cnt)
	{
		while (*s == c && *s)
			s++;
		result[p] = malloc(get_len(s, c) + 1);
		if (result[p] == 0)
			return (free_malloc_failure(result, p));
		pp = 0;
		while (*s != c && *s)
			result[p][pp++] = *s++;
		result[p][pp] = 0;
		p++;
	}
	result[p] = 0;
	return (result);
}

size_t	get_cnt_word(char const *s, char c)
{
	size_t	cnt;

	cnt = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
			cnt++;
		while (*s != c && *s)
			s++;
	}
	return (cnt);
}

size_t	get_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] != c && s[len])
		len++;
	return (len);
}

void	*free_malloc_failure(char **result, int p)
{
	while (p >= 0)
		free(result[p--]);
	free(result);
	return (0);
}
