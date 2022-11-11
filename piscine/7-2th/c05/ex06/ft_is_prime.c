/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghki2 <donghki2@student.42seoul>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:29:58 by donghki2          #+#    #+#             */
/*   Updated: 2022/06/05 18:42:53 by donghki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	number;

	if (nb <= 1)
		return (0);
	number = 2;
	while ((nb % number) != 0)
		number++;
	if (number == nb)
		return (1);
	return (0);
}
