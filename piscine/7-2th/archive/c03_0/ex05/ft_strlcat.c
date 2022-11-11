/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghki2 <donghki2@student.42seoul>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 02:00:32 by donghki2          #+#    #+#             */
/*   Updated: 2022/06/05 18:54:25 by donghki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	int	size_final;
	int	size_dest;
	int	size_src;
	int	cnt_dest;
	int	cnt_src;

	size_dest = 0;
	size_src = 0;
	while (dest[size_dest])
		size_dest++;
	while (dest[size_src])
		size_src++;
	size_final = size - size_dest;
	if (size_final <= 0)
		return (size_src + size);
	cnt_dest = size_dest;
	cnt_src = 0;
	while (src[cnt_src] && cnt_src < size_final - 1)
	{
		dest[cnt_dest] = src[cnt_src];
		cnt_dest++;
		cnt_src++;
	}
	return (size_dest + size_src);
}
