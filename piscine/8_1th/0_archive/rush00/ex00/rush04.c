/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:28:25 by jiryu             #+#    #+#             */
/*   Updated: 2022/08/27 21:29:09 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	first_line2(int x)
{
	int	i;

	ft_putchar('A');
	if (x > 1)
	{
		i = 0;
		while (i < x - 2)
		{
			ft_putchar('B');
			i++;
		}
		ft_putchar('C');
	}
	ft_putchar('\n');
}

void	mid_line2(int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < y - 2)
	{
		j = 0;
		ft_putchar('B');
		if (x > 1)
		{
			while (j < x - 2)
			{
				ft_putchar(' ');
				j++;
			}
			ft_putchar('B');
		}
		ft_putchar('\n');
		i++;
	}
}

void	end_line2(int x)
{
	int	i;

	ft_putchar('C');
	if (x > 1)
	{
		i = 0;
		while (i < x - 2)
		{
			ft_putchar('B');
			i++;
		}
		ft_putchar('A');
	}
	ft_putchar('\n');
}

void	rush04(int x, int y)
{
	int	i;

	i = 0;
	if (x < 1 || y < 1)
		return ;
	first_line2(x);
	if (y > 2)
		mid_line2(x, y);
	if (y > 1)
		end_line2(x);
}
