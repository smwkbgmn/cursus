/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:12:37 by donghyu2          #+#    #+#             */
/*   Updated: 2022/12/16 20:00:14 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin_free(char const *s1, char const *s2)
{
	char	*result;
	size_t	idx;
	size_t	ptr;

	result = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (result == 0)
		return (0);
	idx = 0;
	p = 0;
	while (s1[p])
		result[idx++] = *s1++;
	while (*s2)
		result[idx++] = *s2++;
	result[idx] = 0;
	return (result);
}
