/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 10:45:24 by donghyu2          #+#    #+#             */
/*   Updated: 2022/08/25 20:40:40 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(int *n1, int *n2);

void	ft_sort_int_tab(int *tab, int size)
{
	int	idx1;
	int	idx2;

	idx1 = 0;
	while (idx1 < size - 1)
	{
		idx2 = idx1 + 1;
		while (idx2 < size)
		{
			if (tab[idx1] > tab[idx2])
				swap(&tab[idx1], &tab[idx2]);
			idx2++;
		}
		idx1++;
	}
}

void	swap(int *n1, int *n2)
{
	int	temp;

	temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}
