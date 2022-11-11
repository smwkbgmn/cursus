/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 14:13:40 by donghyu2          #+#    #+#             */
/*   Updated: 2022/08/29 13:15:36 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char letter);
int		is_non_printable(char letter);
void	print_hex(int decimal);

void	ft_putstr_non_printable(char *str)
{
	while (*str)
	{
		if (is_non_printable(*str) == 1)
		{
			ft_putchar('\\');
			if (*str < 16)
				ft_putchar('0');
			print_hex(*str);
		}
		else
			ft_putchar(*str);
		str++;
	}
}

void	ft_putchar(char letter)
{
	write(1, &letter, 1);
}

int	is_non_printable(char letter)
{
	if (32 <= letter && letter <= 126)
		return (0);
	else
		return (1);
}

void	print_hex(int decimal)
{
	if (decimal > 15)
		print_hex(decimal / 16);
	ft_putchar("0123456789abcdef"[decimal % 16]);
}
