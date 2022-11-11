/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghki2 <donghki2@student.42seoul>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:19:56 by donghki2          #+#    #+#             */
/*   Updated: 2022/06/01 16:26:52 by donghki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	moving;
	int	check;

	moving = 0;
	check = 0;
	while (str[moving])
	{
		if (str[moving] < 97 || str[moving] > 122)
			check ++;
		moving++;
	}
	if (check == 0)
		return (1);
	else
		return (0);
}
