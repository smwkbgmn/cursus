/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 23:43:47 by donghyu2          #+#    #+#             */
/*   Updated: 2023/01/04 12:41:03 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*s1_new;
	size_t	len;

	len = ft_strlen(s1);
	s1_new = malloc(len + 1);
	if (s1_new)
		ft_memmove(s1_new, s1, len + 1);
	return (s1_new);
}
