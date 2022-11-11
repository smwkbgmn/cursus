/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 23:48:04 by donghyu2          #+#    #+#             */
/*   Updated: 2022/09/06 15:14:34 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		length_sep(char *sep);
int		length_strs(char **strs, int word);
void	join(char **strs, char *str, char *sep, int word);
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
	size_str = (length_strs(strs, size) + (length_sep(sep) * (size - 1)) + 1);
	str = (char *)malloc(size_str * sizeof(char));
	if (str == 0)
		return (0);
	join(strs, str, sep, size);
	return (str);
}

void	join(char **strs, char *str, char *sep, int word)
{
	while (*strs && word > 0)
	{
		while (**strs)
		{
			*str = **strs;
			str++;
			*strs += 1;
		}
		*str = 0;
		if (word > 1)
			str = cat_sep(str, sep);
		strs++;
		word--;
	}
}

char	*cat_sep(char *str, char *sep)
{
	while (*sep)
		*str++ = *sep++;
	return (str);
}

int	length_strs(char **strs, int word)
{
	int	r;
	int	c;
	int	size;

	size = 0;
	r = 0;
	while (strs[r] && word > 0)
	{
		c = 0;
		while (strs[r][c])
		{
			size++;
			c++;
		}
		r++;
		word--;
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
