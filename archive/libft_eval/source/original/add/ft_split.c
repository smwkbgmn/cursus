/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:12:25 by donghyu2          #+#    #+#             */
/*   Updated: 2023/10/15 00:51:05 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

size_t	get_cnt(char const *s, char c);
size_t	get_len(char const *s, char c, short flag);
char	*assign_word(char const **s, char c);
void	*free_malloc_failure(char **result, int p);

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	cnt_word;
	size_t	ptr;

	cnt_word = get_cnt(s, c);
	result = malloc(sizeof(char *) * (cnt_word + 1));
	if (result)
	{
		ptr = 0;
		while (ptr < cnt_word)
		{
			result[ptr] = assign_word(&s, c);
			if (result[ptr])
				ptr++;
			else
				return (free_malloc_failure(result, ptr));
		}
		result[ptr] = NULL;
	}
	return (result);
}

char	*assign_word(char const **s, char c)
{
	char	*word;
	size_t	len;

	*s += get_len(*s, c, 0);
	len = get_len(*s, c, 1);
	word = malloc(len + 1);
	if (word)
	{
		ft_strlcpy(word, *s, len + 1);
		*s += len;
	}
	return (word);
}

size_t	get_cnt(char const *s, char c)
{
	size_t	cnt_word;

	cnt_word = 0;
	if (s)
	{
		while (*s)
		{
			s += get_len(s, c, 0);
			if (*s)
				cnt_word++;
			s += get_len(s, c, 1);
		}
	}
	return (cnt_word);
}

size_t	get_len(char const *s, char c, short flag)
{
	size_t	idx;

	idx = 0;
	while ((s[idx] != c) == flag && s[idx])
		idx++;
	return (idx);
}

void	*free_malloc_failure(char **result, int ptr)
{
	while (ptr >= 0)
	{
		free(result[ptr]);
		ptr--;
	}
	free(result);
	return (0);
}
