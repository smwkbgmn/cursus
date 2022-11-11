/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghki2 <donghki2@student.42seoul>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 12:36:34 by donghki2          #+#    #+#             */
/*   Updated: 2022/06/01 16:26:56 by donghki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	moving;
	int	check;

	moving = 0;
	check = 0;
	while (str[moving])
	{
		if (str[moving] < 48 || str[moving] > 57)
			check ++;
		moving++;
	}
	if (check == 0)
		return (1);
	else
		return (0);
}
