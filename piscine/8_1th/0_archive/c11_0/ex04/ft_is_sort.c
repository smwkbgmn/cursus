/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 23:31:55 by donghyu2          #+#    #+#             */
/*   Updated: 2022/09/12 17:59:59 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	idx;

	if (length == 0 || length == 1)
		return (1);
	idx = 0;
	while (tab[idx] == tab[idx + 1] && idx < length - 1)
		idx++;
	if (f(tab[idx], tab[idx + 1]) < 0)
	{
		while (f(tab[idx], tab[idx + 1]) <= 0 && idx < length - 1)
			idx++;
	}
	else
	{
		while (f(tab[idx], tab[idx + 1]) >= 0 && idx < length - 1)
			idx++;
	}
	if (idx == length - 1)
		return (1);
	return (0);
}
