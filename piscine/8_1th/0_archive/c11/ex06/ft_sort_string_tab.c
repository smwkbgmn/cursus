/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:04:49 by donghyu2          #+#    #+#             */
/*   Updated: 2022/09/12 13:44:06 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap_point(char **a1, char **a2);
int		ft_strcmp(char *s1, char *s2);

void	ft_sort_string_tab(char **tab)
{
	int	idx;
	int	cmp;

	idx = 0;
	while (tab[idx + 1])
	{
		cmp = idx + 1;
		while (tab[cmp])
		{
			if (ft_strcmp(tab[idx], tab[cmp]) > 0)
				swap_point(&tab[idx], &tab[cmp]);
			cmp++;
		}
		idx++;
	}
}	

void	swap_point(char **a1, char **a2)
{
	char	*tmp;

	tmp = *a1;
	*a1 = *a2;
	*a2 = tmp;
}

int	ft_strcmp(char *s1, char *s2)
{	
	while (*s1 == *s2)
	{
		if (*s1 == 0)
			return (0);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
