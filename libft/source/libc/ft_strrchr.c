/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 22:25:20 by donghyu2          #+#    #+#             */
/*   Updated: 2022/11/23 17:57:11 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	idx;
	char	c_cast;

	idx = 0;
	while (s[idx])
		idx++;
	c_cast = (char)c;
	while (idx > 0 && s[idx] != c_cast)
		idx--;
	if (s[idx] == c_cast)
		return ((char *)(s + idx));
	else
		return (0);
}
