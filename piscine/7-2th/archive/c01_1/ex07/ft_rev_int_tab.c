/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghki2 <donghki2@student.42seoul>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 20:12:26 by donghki2          #+#    #+#             */
/*   Updated: 2022/05/26 13:00:58 by donghki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	temp;
	int	front;
	int	end;

	front = 0;
	end = size - 1;
	while (front < size / 2)
	{
		temp = tab[front];
		tab[front] = tab[end];
		tab[end] = temp;
		front++;
		end--;
	}
}
