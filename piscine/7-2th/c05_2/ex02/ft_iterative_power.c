/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghki2 <donghki2@student.42seoul>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:07:33 by donghki2          #+#    #+#             */
/*   Updated: 2022/06/05 18:39:22 by donghki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	number;

	if ((power == 0 && nb == 0) || power == 0)
		return (1);
	else if (power < 0)
		return (0);
	number = nb;
	while (--power > 0)
		number *= nb;
	return (number);
}
