/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghki2 <donghki2@student.42seoul>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 18:21:15 by donghki2          #+#    #+#             */
/*   Updated: 2022/06/05 18:43:15 by donghki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_prime(int number);

int	ft_find_next_prime(int nb)
{
	long	number;
	int		check;

	if (nb < 0)
		return (0);
	else if (nb == 0 || nb == 1)
		return (2);
	number = nb;
	check = 0;
	while (check == 0)
	{
		check = check_prime(number);
		number += 1;
	}
	return (number - 1);
}

int	check_prime(int number)
{
	int	checker;

	checker = 2;
	while ((number % checker) != 0)
		checker++;
	if (number == checker)
		return (1);
	return (0);
}
