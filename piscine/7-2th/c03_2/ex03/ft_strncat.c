/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghki2 <donghki2@student.42seoul>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 17:55:57 by donghki2          #+#    #+#             */
/*   Updated: 2022/06/07 22:13:55 by donghki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	dest_cnt;
	unsigned int	src_cnt;

	dest_cnt = 0;
	while (dest[dest_cnt])
		dest_cnt++;
	src_cnt = 0;
	while (src[src_cnt] && src_cnt < nb)
	{
		dest[dest_cnt] = src[src_cnt];
		dest_cnt++;
		src_cnt++;
	}
	dest[dest_cnt] = '\0';
	return (dest);
}
