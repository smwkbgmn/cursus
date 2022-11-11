/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 21:29:52 by donghyu2          #+#    #+#             */
/*   Updated: 2022/09/06 01:07:20 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str);

char	*ft_strdup(char *src)
{
	char	*str;
	int		idx;

	str = (char *)malloc((ft_strlen(src) + 1) * sizeof(char));
	if (str == 0)
		return (0);
	idx = 0;
	while (src[idx])
	{
		str[idx] = src[idx];
		idx++;
	}
	str[idx] = 0;
	return (str);
}

int	ft_strlen(char *str)
{
	int	size;

	size = 0;
	while (*str)
	{
		size++;
		str++;
	}
	return (size);
}
