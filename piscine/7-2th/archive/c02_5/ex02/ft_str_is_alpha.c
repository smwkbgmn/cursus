/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghki2 <donghki2@student.42seoul>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 16:15:07 by donghki2          #+#    #+#             */
/*   Updated: 2022/06/02 13:57:34 by donghki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	cnt;

	cnt = 0;
	while (str[cnt])
	{
		if (str[cnt] >= 'A' && str[cnt] <= 'Z')
			cnt++;
		else if (str[cnt] >= 'a' && str[cnt] <= 'z')
			cnt++;
		else
			return (0);
	}
	return (1);
}
