/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghki2 <donghki2@student.42seoul>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:09:03 by donghki2          #+#    #+#             */
/*   Updated: 2022/05/31 12:15:45 by donghki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	initialize(char *str)
{
	int moving;
	
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
	int	moving;
	int	is_first;

	initialize (str);
	if (str[0] >= 97  && str[0] <= 122)
		str[0] -= 32;

	moving = 0;
	while (str[moving])
	{
		if (str[moving] == 32 || str[moving] == 43)
		{
			if (str[moving + 1]	>= 97 && str[moving + 1] <= 122)
				str[moving + 1] -= 32;
		}

		moving++;
	}
	return (str);
}
