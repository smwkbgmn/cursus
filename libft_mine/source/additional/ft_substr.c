/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:13:07 by donghyu2          #+#    #+#             */
/*   Updated: 2022/12/18 18:37:28 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
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
		result = ft_calloc(1, 1);
	return (result);
}
