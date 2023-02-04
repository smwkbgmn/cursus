/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:07:17 by donghyu2          #+#    #+#             */
/*   Updated: 2023/02/05 06:50:49 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = get_len(s1);
	len_s2 = get_len(s2);
	result = malloc(len_s1 + len_s2 + 1);
	if (result)
	{
		ft_memcpy(result, s1, len_s1);
		ft_memcpy(result + len_s1, s2, len_s2);
		result[len_s1 + len_s2] = '\0';
	}
	return (result);
}

void	ft_memcpy(char *dst, char *src, size_t n)
{
	if (n > 0)
	{
		while (n-- > 1)
			*dst++ = *src++;
		*dst = *src;
	}
}

char	*ft_strchr(char *s, int c)
{
	while (*s != c && *s)
		s++;
	if (*s == c)
		return (s);
	else
		return (NULL);
}

size_t	get_len(char *str)
{
	size_t	idx;

	if (!str || str == EOF)
		return (0);
	else
	{
		idx = 0;
		while (str[idx] != '\n' && str[idx])
			idx++;
		return (idx + (str[idx] == '\n'));
	}
}

void	adjust(t_list *node, char *new)
{
	size_t	len_ptr;
	size_t	len_new;

	len_ptr = get_len(node->ptr);
	len_new = get_len(new);
	if (len_new == 0)
		node->ptr += len_ptr;
	else
	{
		free(node->str);
		node->str = new;
		node->ptr = new + len_new;
	}
	if (*node->ptr == 0)
	{
		free(node->str);
		node->str = NULL;
	}
}
