/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 10:40:15 by donghyu2          #+#    #+#             */
/*   Updated: 2022/08/25 20:40:25 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(int *n1, int *n2);

void	ft_rev_int_tab(int *tab, int size)
{
	int	idx;

	idx = 0;
	while (idx < size / 2)
	{
		swap(&tab[idx], &tab[size - idx - 1]);
		idx++;
	}
}

void	swap(int *n1, int *n2)
{
	int	temp;

	temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}
