/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghki2 <donghki2@student.42seoul>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 16:15:07 by donghki2          #+#    #+#             */
/*   Updated: 2022/06/01 16:26:13 by donghki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	cnt;
	int	check;

	cnt = 0;
	check = 0;
	while (str[cnt])
	{
		if (str[cnt] < 65)
			check++;
		else if (str[cnt] >= 90 && str[cnt] <= 97)
			check++;
		else if (str[cnt] > 122)
			check++;
		cnt++;
	}
	if (check == 0)
		return (1);
	return (0);
}
