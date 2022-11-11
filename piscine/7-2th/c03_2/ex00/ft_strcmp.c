/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghki2 <donghki2@student.42seoul>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:54:14 by donghki2          #+#    #+#             */
/*   Updated: 2022/06/02 16:41:12 by donghki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	counter;

	counter = 0;
	while (s1[counter] == (s2[counter]))
	{
		if (s1[counter] == 0)
			return (0);
		counter++;
	}
	return ((unsigned char)s1[counter] - (unsigned char)s2[counter]);
}
