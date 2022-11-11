/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 13:54:56 by donghyu2          #+#    #+#             */
/*   Updated: 2022/09/06 01:03:46 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	word(char *str, char *charset);
int	length(char *str, char *charset);	
int	is_sep(char letter, char *charset);

char	**ft_split(char *str, char *charset)
{
	char	**addr;
	int		idx1;
	int		idx2;

	addr = (char **)malloc((word(str, charset) + 1) * sizeof(char *));
	if (addr == 0)
		return (0);
	idx1 = 0;
	while (*str)
	{
		while (is_sep(*str, charset) == 1)
			str++;
		addr[idx1] = (char *)malloc(length(str, charset) * sizeof(char) + 1);
		if (addr[idx1] == 0)
			return (0);
		idx2 = 0;
		while (is_sep(*str, charset) == 0 && *str)
			addr[idx1][idx2++] = *str++;
		addr[idx1][idx2] = 0;
		idx1++;
	}
	addr[idx1] = 0;
	return (addr);
}

int	is_sep(char letter, char *charset)
{
	while (*charset)
	{
		if (letter == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	word(char *str, char *charset)
{
	int	counter;

	counter = 0;
	while (*str)
	{
		while (is_sep(*str, charset) == 1)
			str++;
		if (*str)
			counter++;
		while (is_sep(*str, charset) == 0 && *str)
			str++;
	}
	return (counter);
}

int	length(char *str, char *charset)
{
	int	length;

	length = 0;
	while (is_sep(*str, charset) == 0 && *str)
	{
		length++;
		str++;
	}
	return (length);
}
