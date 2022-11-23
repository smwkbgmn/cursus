/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:12:25 by donghyu2          #+#    #+#             */
/*   Updated: 2022/11/23 15:12:27 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	**scissor(char const *s, char c, int cnt);
int		get_cnt_word(char const *s, char c);
int		get_len(char const *s, char c);
void	*free_malloc_failure(char **result, int r);

char	**ft_split(char const *s, char c)
{
	return (scissor(s, c, get_cnt_word(s, c)));
}

char	**scissor(char const *s, char c, int cnt)
{
	char	**result;
	int		p;
	int		pp;

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

int	get_cnt_word(char const *s, char c)
{
	int	cnt;

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

int	get_len(char const *s, char c)
{
	int	len;

	len = 0;
	while (*s++ != c && *s)
		len++;
	return (len);
}

void	*free_malloc_failure(char **result, int r)
{
	while (r >= 0)
		free(result[r--]);
	free(result);
	return (0);
}
