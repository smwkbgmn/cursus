/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 13:54:56 by donghyu2          #+#    #+#             */
/*   Updated: 2022/09/06 15:25:43 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	word_cnt(char *str, char *charset);
int	length(char *str, char *charset);	
int	is_sep(char letter, char *charset);

char	**ft_split(char *str, char *charset)
{
	char	**addr;
	int		word;
	int		r;
	int		c;

	word = word_cnt(str, charset);
	addr = (char **)malloc(sizeof(char *) * (word + 1));
	if (addr == 0)
		return (0);
	r = 0;
	while (r < word)
	{
		while (is_sep(*str, charset) == 1)
			str++;
		addr[r] = (char *)malloc(sizeof(char) * (length(str, charset) + 1));
		if (addr[r] == 0)
			return (0);
		c = 0;
		while (is_sep(*str, charset) == 0 && *str)
			addr[r][c++] = *str++;
		addr[r][c] = 0;
		r++;
	}
	addr[r] = 0;
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

int	word_cnt(char *str, char *charset)
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
