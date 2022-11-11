/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghki2 <donghki2@student.42seoul>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 03:23:59 by donghki2          #+#    #+#             */
/*   Updated: 2022/06/09 03:37:22 by donghki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	find_prime(int nb)
{
	int	cnt;

	cnt = 2;
	if (nb <= 1)
		return (0);
	else if (nb == 2)
		return (1);
	else
	{
		while (cnt * cnt <= nb && cnt * cnt > 0)
		{
			if (nb % cnt == 0)
				return (0);
			cnt++;
		}
		return (1);
	}
}

int	ft_find_next_prime(int nb)
{
	if (nb < 3)
		return (2);
	while (!find_prime(nb))
		nb++;
	return (nb);
}
