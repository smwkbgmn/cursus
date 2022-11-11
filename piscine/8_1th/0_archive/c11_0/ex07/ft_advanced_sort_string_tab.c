/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:44:51 by donghyu2          #+#    #+#             */
/*   Updated: 2022/09/12 14:02:48 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap_point(char **a1, char **a2);

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int	i1;
	int	i2;

	i1 = 0;
	while (tab[i1 + 1])
	{
		i2 = i1 + 1;
		while (tab[i2])
		{
			if (cmp(tab[i1], tab[i2]) > 0)
				swap_point(&tab[i1], &tab[i2]);
			i2++;
		}
		i1++;
	}
}

void	swap_point(char **a1, char **a2)
{
	char	*tmp;

	tmp = *a1;
	*a1 = *a2;
	*a2 = tmp;
}
