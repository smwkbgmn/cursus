/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 23:43:47 by donghyu2          #+#    #+#             */
/*   Updated: 2022/11/18 23:25:38 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include "libft.h"

static size_t	ft_strlen(const char *s);

char	*ft_strdup(const char *s1)
{
	char	*s1_new;
	size_t	len;
	size_t	idx;
	
	len = ft_strlen(s1);
	s1_new = malloc(len + 1);
	if (!s1_new)
		return (0);
	idx = 0;
	while (idx <= len)
	{
		s1_new[idx] = s1[idx];
		idx++;
	}
	return (s1_new);
}

static size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}
