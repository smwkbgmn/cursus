/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:05:13 by donghyu2          #+#    #+#             */
/*   Updated: 2022/08/30 17:19:56 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str);

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	size_d;
	unsigned int	size_s;

	size_d = ft_strlen(dest);
	size_s = ft_strlen(src);
	if (size == 0)
		return (size_s);
	if (size <= size_d + 1)
		return (size_d + size_s);
	while (*dest)
		dest++;
	size -= (size_d + 1);
	while (*src && size > 0)
	{
		*dest++ = *src++;
		size--;
	}
	*dest = 0;
	return (size_d + size_s);
}

unsigned int	ft_strlen(char *str)
{
	unsigned int	size;

	size = 0;
	while (*str++)
		size++;
	return (size);
}
