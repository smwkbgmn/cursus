/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 01:53:02 by donghyu2          #+#    #+#             */
/*   Updated: 2022/08/30 19:01:43 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	src_size;

	src_size = 0;
	while (src[src_size])
		src_size++;
	if (size == 0)
		return (src_size);
	while (size > 1 && *src)
	{
		*dest++ = *src++;
		size--;
	}
	if (size == 1)
		*dest = 0;
	return (src_size);
}
