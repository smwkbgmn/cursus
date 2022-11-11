/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghki2 <donghki2@student.42seoul>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:28:34 by donghki2          #+#    #+#             */
/*   Updated: 2022/06/05 18:52:42 by donghki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	counter;

	counter = 0;
	while (s1[counter] == s2[counter] && counter < n)
	{
		if (s1[counter] == '\0')
			return (0);
		else if (counter == n - 1)
			return (0);
		counter++;
	}
	return ((unsigned char)s1[counter] - (unsigned char)s2[counter]);
}
