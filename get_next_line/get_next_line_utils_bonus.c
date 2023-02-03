/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:07:17 by donghyu2          #+#    #+#             */
/*   Updated: 2023/02/04 03:56:13 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "get_next_line_bonus.h"

char	*ft_strchr(char *s, int c)
{
	while (*s != c && *s)
		s++;
	if (*s == c)
		return (s);
	else
		return (NULL);
}

void	ft_strncpy(char *dst, char *src, size_t n)
{
	while (n > 0 && *src)
	{
		*dst++ = *src++;
		n--;
	}
}

char	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	len;
	size_t	idx;

	len = size * count;
	ptr = malloc(len);
	if (ptr)
	{
		idx = 0;
		while (idx < len)
			ptr[idx++] = 0;
	}
	return (ptr);
}

size_t	get_len(char *str)
{
	size_t	idx;

	if (!str || str == WRONG_FD)
		return (0);
	else
	{
		idx = 0;
		while (str[idx] != '\n' && str[idx])
			idx++;
		return (idx + (str[idx] == '\n'));
	}
}

void	adjust(t_list *node, char *new, size_t len_p, size_t len_n)
{
	if (new)
	{
		free(node->str);
		node->str = new;
		node->ptr = new + len_n;
	}
	else
	{
		node->ptr += len_p;
		if (*node->ptr == 0)
		{
			free(node->str);
			node->str = NULL;
			node->ptr = NULL;
		}
	}	
}
