/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiryu <jiryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 14:26:29 by jiryu             #+#    #+#             */
/*   Updated: 2022/08/27 21:28:25 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	first_line(int x)
{
	int	i;

	ft_putchar('o');
	if (x > 1)
	{
		i = 0;
		while (i < x - 2)
		{
			ft_putchar('-');
			i++;
		}
		ft_putchar('o');
	}
	ft_putchar('\n');
}

void	mid_line(int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < y - 2)
	{
		j = 0;
		ft_putchar('|');
		if (x > 1)
		{
			while (j < x - 2)
			{
				ft_putchar(' ');
				j++;
			}
			ft_putchar('|');
		}
		ft_putchar('\n');
		i++;
	}
}

void	end_line(int x)
{
	int	i;

	ft_putchar('o');
	if (x > 1)
	{
		i = 0;
		while (i < x - 2)
		{
			ft_putchar('-');
			i++;
		}
		ft_putchar('o');
	}
	ft_putchar('\n');
}

void	rush00(int x, int y)
{
	int	i;

	i = 0;
	first_line(x);
	if (y > 2)
		mid_line(x, y);
	if (y > 1)
		end_line(x);
}
