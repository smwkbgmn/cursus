/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghki2 <donghki2@student.42seoul>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 23:03:25 by donghki2          #+#    #+#             */
/*   Updated: 2022/06/09 23:05:22 by donghki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	char	*tmp;

	tmp = dest;
	while (*dest)
		dest++;
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (tmp);
}

int	size_length(int size, char **strs, char *sep)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (i < size)
	{	
		len += ft_strlen(strs[i]);
		i++;
	}
	len += (size - 1) * ft_strlen(sep);
	return (len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		len;
	char	*line;

	if (size == 0)
	{
		line = (char *)malloc(sizeof(char) * 1);
		*line = '\0';
		return (line);
	}
	len = size_length(size, strs, sep);
	line = (char *)malloc(sizeof(char) * len + 1);
	if (!line)
		return (0);
	*line = '\0';
	i = -1;
	while (++i < size)
	{
		ft_strcat(line, strs[i]);
		if (i + 1 < size)
			ft_strcat(line, sep);
	}
	return (line);
}
