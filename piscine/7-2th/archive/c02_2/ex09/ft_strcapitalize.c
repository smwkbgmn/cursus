/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghki2 <donghki2@student.42seoul>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:09:03 by donghki2          #+#    #+#             */
/*   Updated: 2022/06/01 22:21:46 by donghki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

void	initialize(char *str)
{
	int	moving;

	moving = 0;
	while (str[moving])
	{
		if (str[moving] >= 'A' && str[moving] <= 'Z')
			str[moving] += 32;
		moving++;
	}
}

char	*ft_strcapitalize(char *str)
{
	int		cnt;
	int		is_first;

	initialize (str);
	if (str[0] >= 97 && str[0] <= 122)
		str[0] -= 32;
	cnt = 0;
	while (str[cnt])
	{
		if ((str[cnt] > 'a' && str[cnt] < 'z') == false)
		{
			if ((str[cnt] > 'A' && str[cnt] < 'Z') == false)
			{
				if ((str[cnt] > '0' && str[cnt] < '9') == false)
				{
					if (str[cnt + 1] >= 97 && str[cnt + 1] <= 122)
						str[cnt + 1] -= 32;
				}
			}
		}
		cnt++;
	}
	return (str);
}
