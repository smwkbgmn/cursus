/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghki2 <donghki2@student.42seoul>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 16:15:07 by donghki2          #+#    #+#             */
/*   Updated: 2022/06/02 11:43:38 by donghki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	cnt;
	int	size;
	int	check;

	cnt = 0;
	size = 0;
	check = 0;
	while (str[cnt])
	{
		if (str[cnt] >= 'A' && str[cnt] <= 'Z')
			check++;
		else if (str[cnt] >= 'a' && str[cnt] <= 'z')
			check++;
		size++;
		cnt++;
	}
	if (size == check)
		return (1);
	else
		return (0);
}
