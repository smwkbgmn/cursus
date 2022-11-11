/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghki2 <donghki2@student.42seoul>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 02:00:32 by donghki2          #+#    #+#             */
/*   Updated: 2022/06/07 23:41:29 by donghki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	size_d;
	unsigned int	size_s;
	unsigned int	cnt_d;
	unsigned int	cnt_s;

	size_d = 0;
	while (dest[size_d])
		size_d++;
	size_s = 0;
	while (src[size_s])
		size_s++;
	if (size < size_d || size == 0)
		return (size_s + size);
	cnt_d = size_d;
	cnt_s = 0;
	while (cnt_s + size_d + 1 < size)
	{
		dest[cnt_d] = src[cnt_s];
		cnt_d++;
		cnt_s++;
	}
	dest[cnt_d] = '\0';
	return (size_d + size_s);
}
