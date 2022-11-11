/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghki2 <donghki2@student.42seoul>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:38:49 by donghki2          #+#    #+#             */
/*   Updated: 2022/06/01 16:26:02 by donghki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	int	cnt;

	cnt = 0;
	while (cnt <= n - 1)
	{
		if (src[cnt])
		{
			dest[cnt] = src[cnt];
		}
		cnt++;
	}
	return (dest);
}
