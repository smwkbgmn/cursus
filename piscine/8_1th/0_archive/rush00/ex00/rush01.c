/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42Seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 14:40:30 by geonwule          #+#    #+#             */
/*   Updated: 2022/08/27 20:04:14 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush01_out(int x, int y, int i, int j)
{
	if ((i == 0 && j == 0) || ((i == x - 1 && j == y - 1) && j * i != 0))
		ft_putchar('/');
	else if ((i == x - 1 && j == 0) || (i == 0 && j == y - 1))
		ft_putchar('\\');
	else if (j == 0 || j == y - 1 || i == 0 || i == x - 1)
		ft_putchar('*');
	else
		ft_putchar(' ');
}

void	rush01(int x, int y)
{
	int	i;
	int	j;

	j = 0;
	while (j < y)
	{
		i = 0;
		while (i < x)
		{
			rush01_out(x, y, i, j);
			i++;
		}
		ft_putchar('\n');
		j++;
	}
}
