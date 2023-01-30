/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:07:17 by donghyu2          #+#    #+#             */
/*   Updated: 2023/01/30 03:08:37 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	result = malloc(len_s1 + len_s2 + 1);
	if (result)
	{
		ft_memcpy(result, s1, len_s1);
		ft_memcpy(result + len_s1, s2, len_s2);
		result[len_s1 + len_s2] = 0;
	}
	return (result);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	len_s;
	size_t	len_r;

	len_s = ft_strlen(s);
	if (start < len_s && len > 0)
	{
		if (len_s - start < len)
			len_r = len_s - start;
		else
			len_r = len;
		result = malloc(len_r + 1);
		if (result)
			ft_strlcpy(result, s + start, len_r + 1);
	}
	else
		result = 0;
	return (result);
}

void	ft_memcpy(char *dst, char *src, size_t n)
{
	while (n > 0)
	{
		*dst++ = *src++;
		n--;
	}
}

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	len_src;

	len_src = ft_strlen(src);
	if (dstsize == 0)
		return (len_src);
	while (dstsize-- > 1 && *src)
		*dst++ = *src++;
	*dst = 0;
	return (len_src);
}

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

size_t	get_len_line(char *ptr)
{
	size_t	idx;

	idx = 0;
	while (ptr[idx] != '\n' && ptr[idx])
		idx++;
	return (idx + (ptr[idx] == '\n'));
}

size_t	ft_strlen(char *s)
{
	size_t	idx;

	idx = 0;
	while (s[idx])
		idx++;
	return (idx);
}

short	is_there_nl(char *str)
{
	while (*str != '\n' && *str)
		str++;
	return (*str == '\n');
}
