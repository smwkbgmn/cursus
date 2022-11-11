/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghki2 <donghki2@student.42seoul>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:11:21 by donghki2          #+#    #+#             */
/*   Updated: 2022/06/09 02:36:37 by donghki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	long long	number;

	if (nb <= 0)
		return (0);
	else if (nb == 1)
		return (1);
	number = 1;
	while ((number * number) < nb)
		number++;
	if ((number * number) == nb)
		return ((int)number);
	else
		return (0);
}
