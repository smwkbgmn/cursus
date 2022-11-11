/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghki2 <donghki2@student.42seoul>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 16:49:33 by donghki2          #+#    #+#             */
/*   Updated: 2022/06/05 18:53:03 by donghki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	dest_cnt;
	int	src_cnt;

	dest_cnt = 0;
	while (dest[dest_cnt])
		dest_cnt++;
	src_cnt = 0;
	while (src[src_cnt])
	{
		dest[dest_cnt] = src[src_cnt];
		dest_cnt++;
		src_cnt++;
	}
	dest[dest_cnt] = '\0';
	return (dest);
}
