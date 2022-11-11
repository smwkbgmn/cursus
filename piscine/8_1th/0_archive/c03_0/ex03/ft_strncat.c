/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:10:30 by donghyu2          #+#    #+#             */
/*   Updated: 2022/08/29 16:01:16 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	if (nb == 0)
		return (dest);
	while (*dest)
		dest++;
	while (*src && nb-- > 0)
		*dest++ = *src++;
	*dest = 0;
	return (dest);
}
