/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghki2 <donghki2@student.42seoul>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:35:46 by donghki2          #+#    #+#             */
/*   Updated: 2022/06/07 22:01:49 by donghki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	cnt;
	unsigned int	size_src;

	cnt = 0;
	size_src = 0;
	while (src[size_src])
		size_src++;
	if (size == 0)
		return (size_src);
	while (cnt < size - 1 && src[cnt])
	{
		dest[cnt] = src[cnt];
		cnt++;
	}
		dest[cnt] = '\0';
	return (size_src);
}
