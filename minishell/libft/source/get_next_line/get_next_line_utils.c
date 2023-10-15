/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:07:17 by donghyu2          #+#    #+#             */
/*   Updated: 2023/05/15 16:11:34 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	get_len(char *str);

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*result;
	size_t	len_1;
	size_t	len_2;

	len_1 = get_len(s1);
	len_2 = get_len(s2);
	result = malloc(len_1 + len_2 + 1);
	if (result)
	{
		gnl_memcpy(result, s1, len_1);
		gnl_memcpy(result + len_1, s2, len_2);
		result[len_1 + len_2] = '\0';
	}
	return (result);
}

void	adjust_node(t_fd *node, char *new)
{
	if (!new)
		node->ptr += get_len(node->ptr);
	else
	{
		free(node->str);
		node->str = new;
		node->ptr = new + get_len(new);
	}
	if (*node->ptr == '\0')
	{
		free(node->str);
		node->str = NULL;
	}
}

void	gnl_memcpy(char *dst, char *src, size_t n)
{
	while (n > 0)
	{
		*dst++ = *src++;
		n--;
	}
}

char	*gnl_strchr(char *s, int c)
{
	while (*s != c && *s)
		s++;
	return ((char *)((unsigned long)s * (*s == c)));
}

static size_t	get_len(char *str)
{
	size_t	idx;

	if (!str)
		return (0);
	else
	{
		idx = 0;
		while (str[idx] != '\n' && str[idx])
			idx++;
		return (idx + (str[idx] == '\n'));
	}
}
