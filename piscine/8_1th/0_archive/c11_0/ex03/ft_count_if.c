/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 23:30:27 by donghyu2          #+#    #+#             */
/*   Updated: 2022/09/10 00:16:19 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char *))
{
	int	idx;
	int	cnt;

	idx = 0;
	cnt = 0;
	while (idx < length)
	{
		if ((*f)(tab[idx]) != 0)
				cnt++;
		idx++;
	}
	return (cnt);
}
