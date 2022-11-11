/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:10:30 by donghyu2          #+#    #+#             */
/*   Updated: 2022/08/31 15:17:29 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int	size_d;
	int	idx;

	if (nb == 0)
		return (dest);
	size_d = 0;
	while (dest[size_d])
		size_d++;
	idx = 0;
	while (src[idx] && nb-- > 0)
	{
		dest[size_d + idx] = src[idx];
		idx++;
	}
	dest[size_d + idx] = 0;
	return (dest);
}
