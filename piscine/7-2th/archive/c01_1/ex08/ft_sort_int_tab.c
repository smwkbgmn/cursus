/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyun <donghyun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 10:14:24 by donghyun          #+#    #+#             */
/*   Updated: 2022/05/26 13:01:39 by donghki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	front;
	int	end;
	int	temp;

	front = 0;
	while (front <= size - 2)
	{
		end = size - 1;
		while (end > front)
		{
			if (tab[front] > tab[end])
			{
				temp = tab[front];
				tab[front] = tab[end];
				tab[end] = temp;
			}		
			end--;
		}
		front++;
	}
}
