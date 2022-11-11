/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:44:51 by donghyu2          #+#    #+#             */
/*   Updated: 2022/09/12 22:35:04 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap_point(char **a1, char **a2);
int		get_line(char **av);

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int	cnt;
	int	idx;
	int	loop;
	int	max;

	cnt = 1;
	max = get_line(tab);
	loop = max;
	while (cnt < loop)
	{
		idx = 0;
		while (idx < max - 1)
		{
			if ((*cmp)(tab[idx], tab[idx + 1]) > 0)
				swap_point(&tab[idx], &tab[idx + 1]);
			idx++;
		}
		max--;
		cnt++;
	}
}

void	swap_point(char **a1, char **a2)
{
	char	*tmp;

	tmp = *a1;
	*a1 = *a2;
	*a2 = tmp;
}

int	get_line(char **tab)
{
	int	line;

	line = 0;
	while (tab[line])
		line++;
	return (line);
}
