/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghki2 <donghki2@student.42seoul>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:35:46 by donghki2          #+#    #+#             */
/*   Updated: 2022/06/01 22:33:37 by donghki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	int	cnt;
	int	return_size;

	if ((int)size <= 0)
		return (0);
	cnt = 0;
	return_size = 0;
	while (src[cnt] && cnt < size - 1)
	{
		dest[cnt] = src[cnt];
		cnt++;
		return_size++;
	}
	dest[cnt] = '\0';
	return (return_size);
}
