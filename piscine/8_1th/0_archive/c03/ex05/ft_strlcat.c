/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:05:13 by donghyu2          #+#    #+#             */
/*   Updated: 2022/11/16 21:13:40 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str);

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	size_d;
	unsigned int	size_s;

	size_d = ft_strlen(dest);
	size_s = ft_strlen(src);
	if (size == 0 || size <= size_d)
		return (size_s + size);
	while (*dest)
		dest++;
	size -= size_d;
	while (*src && size-- > 1)
		*dest++ = *src++;
	*dest = 0;
	return (size_d + size_s);
}

unsigned int	ft_strlen(char *str)
{
	unsigned int	size;

	size = 0;
	while (str[size])
		size++;
	return (size);
}
