/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghki2 <donghki2@student.42seoul>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 14:48:03 by donghki2          #+#    #+#             */
/*   Updated: 2022/05/30 15:01:57 by donghki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int	moving;

	moving = 0;
	while (str[moving])
	{
		if (str[moving] >= 97 && str[moving] <= 122)
			str[moving] -= 32;
		moving++;
	}
	return (str);
}
