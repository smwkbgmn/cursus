/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:19:35 by donghyu2          #+#    #+#             */
/*   Updated: 2022/08/31 15:17:16 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	size_d;
	int	idx;

	size_d = 0;
	while (dest[size_d])
		size_d++;
	idx = 0;
	while (src[idx])
	{
		dest[size_d + idx] = src[idx];
		idx++;
	}
	dest[size_d + idx] = 0;
	return (dest);
}
