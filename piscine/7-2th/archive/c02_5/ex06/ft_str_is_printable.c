/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghki2 <donghki2@student.42seoul>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 14:32:37 by donghki2          #+#    #+#             */
/*   Updated: 2022/06/01 21:26:54 by donghki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	moving;
	int	check;

	moving = 0;
	check = 0;
	while (str[moving])
	{
		if (str[moving] < 32 || str[moving] > 126)
			check ++;
		moving++;
	}
	if (check == 0)
		return (1);
	else
		return (0);
}
