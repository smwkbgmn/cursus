/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghki2 <donghki2@student.42seoul>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:09:03 by donghki2          #+#    #+#             */
/*   Updated: 2022/06/02 21:13:06 by donghki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

void	initialize(char *str)
{
	int	moving;

	moving = 0;
	while (str[moving])
	{
		if (str[moving] >= 65 && str[moving] <= 90)
			str[moving] += 32;
		moving++;
	}
}

int	check(char letter)
{
	if (letter >= 48 && letter <= 57)
	{
		return (0);
	}
	else if (letter >= 65 && letter <= 90)
	{
		return (0);
	}
	else if (letter >= 97 && letter <= 122)
	{
		return (0);
	}
	else
		return (1);
}

char	*ft_strcapitalize(char *str)
{
	int	cnt;

	initialize (str);
	if (str[0] >= 97 && str[0] <= 122)
		str[0] = str[0] - 32;
	cnt = 0;
	while (str[cnt])
	{
		if (check (str[cnt]) == 1)
		{
			if (str[cnt + 1] >= 97 && str[cnt + 1] <= 122)
				str[cnt + 1] -= 32;
		}
		cnt++;
	}
	return (str);
}
