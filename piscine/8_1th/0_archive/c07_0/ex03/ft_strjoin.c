/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 23:48:04 by donghyu2          #+#    #+#             */
/*   Updated: 2022/09/06 01:05:23 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		length_sep(char *sep);
int		length_strs(char **strs);
void	join(char **strs, char *str, char *sep);
char	*cat_sep(char *str, char *sep);

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		size_str;

	if (size == 0)
	{
		str = (char *)malloc(sizeof(char));
		return (str);
	}
	size_str = (length_strs(strs) + (length_sep(sep) * (size - 1)) + 1);
	str = (char *)malloc(size_str * sizeof(char));
	if (str == 0)
		return (0);
	join(strs, str, sep);
	return (str);
}

void	join(char **strs, char *str, char *sep)
{
	while (*strs)
	{
		while (**strs)
		{
			*str = **strs;
			str++;
			*strs += 1;
		}
		strs++;
		if (*strs != 0)
			str = cat_sep(str, sep);
	}
}

char	*cat_sep(char *str, char *sep)
{
	while (*sep)
		*str++ = *sep++;
	return (str);
}

int	length_strs(char **strs)
{
	int	idx1;
	int	idx2;
	int	size;

	size = 0;
	idx1 = 0;
	while (strs[idx1])
	{
		idx2 = 0;
		while (strs[idx1][idx2])
		{
			size++;
			idx2++;
		}
		idx1++;
	}
	return (size);
}

int	length_sep(char *sep)
{
	int	size;

	size = 0;
	while (*sep++)
		size++;
	return (size);
}
