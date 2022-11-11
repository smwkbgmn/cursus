/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghki2 <donghki2@student.42seoul>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:35:46 by donghki2          #+#    #+#             */
/*   Updated: 2022/05/30 16:18:21 by donghki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	int	moving;
	int return_size;

	moving = 0;
	return_size =0;
	while (src[moving] && moving < size - 1)
	{
		dest[moving] = src[moving];
		moving++;
		return_size++;
	}
	return (return_size); 
}
