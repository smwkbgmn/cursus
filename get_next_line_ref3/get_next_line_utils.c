/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:07:17 by donghyu2          #+#    #+#             */
/*   Updated: 2023/01/31 18:01:06 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*init_list(int fd)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new)
	{
		new->next = 0;
		new->fd = fd;
		new->str = 0;
		new->ptr = 0;
	}
	return (new);
}

size_t	get_len(char *str)
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

short	is_there_nl(char *str)
{
	if (str)
	{
		while (*str != '\n' && *str)
			str++;
		return (*str == '\n');
	}
	else
		return (0);
}

void	ft_strncpy(char *dst, char *src, size_t n)
{
	if (src)
	{
		while (*src && n > 0)
		{
			*dst++ = *src++;
			n--;
		}
	}
}

void	set_str(t_list *node, char *str)
{
	if (node->str)
		free(node->str);
	node->str = str;
	node->ptr = str;
}
