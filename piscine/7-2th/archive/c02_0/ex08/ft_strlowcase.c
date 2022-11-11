/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghki2 <donghki2@student.42seoul>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:02:31 by donghki2          #+#    #+#             */
/*   Updated: 2022/05/30 15:07:00 by donghki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	moving;

	moving = 0;
	while (str[moving])
	{
		if (str[moving] >= 65 && str[moving] <= 90)
			str[moving] += 32;
		moving++;
	}
	return (str);
}
