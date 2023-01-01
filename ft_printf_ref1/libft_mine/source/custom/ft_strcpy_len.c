/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 21:58:49 by donghyu2          #+#    #+#             */
/*   Updated: 2022/12/11 22:07:15 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strcpy_len(char *dest, char *src)
{
	size_t	len;

	len = 0;
	while (src[len])
	{
		dest[len] = src[len];
		len += 1;
	}
	return (len);
}
