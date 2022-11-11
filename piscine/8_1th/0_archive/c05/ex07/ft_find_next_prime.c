/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 19:39:53 by donghyu2          #+#    #+#             */
/*   Updated: 2022/08/31 22:07:00 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_prime(int nb);

int	ft_find_next_prime(int nb)
{
	if (nb <= 2)
		return (2);
	while (is_prime(nb) == 0)
		nb++;
	return (nb);
}

int	is_prime(int nb)
{
	long long	idx;

	idx = 2;
	while (idx * idx <= nb)
	{
		if (nb % idx == 0)
			return (0);
		idx++;
	}
	return (1);
}
