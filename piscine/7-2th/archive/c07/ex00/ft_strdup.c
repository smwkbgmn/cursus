/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghki2 <donghki2@student.42seoul>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 17:58:44 by donghki2          #+#    #+#             */
/*   Updated: 2022/06/09 20:23:42 by donghki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		idx;
	int		size;
	char	*str;

	size = 0;
	while (src[size])
		size++;
	if (size == 0)
		return (0);
	str = (char*) malloc (sizeof(char) * (size + 1));
	if (!str)
		return (0);
	idx = 0;
	while (size > 0)
	{
		str[idx] = src[idx];
		idx++;
		size--;
	}
	str[idx] = '\0';
	return (str);
}
