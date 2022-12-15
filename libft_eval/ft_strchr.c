/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 21:14:46 by donghyu2          #+#    #+#             */
/*   Updated: 2022/12/15 18:06:07 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	c_cast;

	c_cast = (char)c;
	while (*s && *s != c_cast)
		s++;
	if (*s == c_cast)
		return ((char *)s);
	else
		return (0);
}
