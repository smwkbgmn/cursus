/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 14:47:42 by donghyu2          #+#    #+#             */
/*   Updated: 2022/08/29 02:11:43 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_address(long long address, int idx);
void	print_hex(char letter, char *str, int *vald);
void	print_str(char *str);
void	hex_digit(int hex);

void	*ft_print_memory(void *addr, unsigned int size)
{
	char	str[17];
	unsigned int	idx1;
	unsigned int	idx2;
	int vald;

	idx1 = 0;
	idx2 = 0;
	vald = 0;
	while (idx1 < size)
	{
		print_address((long long)&addr[idx1], 0);
		while (idx1 < (idx2 + 1) * 16)
		{
			if (vald == 0)
				print_hex(*(char*)&addr[idx1], &str[idx1 % 16], &vald);
			else
				write(1, "  ", 2);
			if (idx1++ % 2 == 1)
				write( 1, " ", 1);
		}
		print_str(str);
		write(1, "\n", 1);
		if (vald == 1)
			return (addr);
		idx2++;
	}
	return (addr);
}

void	print_address(long long address, int idx)
{
	if (address >= 16)
		print_address(address / 16, ++idx);
	while (address < 16 && ++idx < 16)
		write(1, "0", 1);
	hex_digit(address % 16);
	if (idx == 1)
		write(1, ": ", 2);
}

void	print_hex(char letter, char *str, int *vald)
{
	*str = letter;
	if (letter > 15)
		hex_digit(letter / 16);
	else
		write(1, "0", 1);
	hex_digit(letter % 16);
	if (letter == 0)
		*vald = 1;
}

void	print_str(char *str)
{
	int idx;

	idx = 0;
	while (str[idx])
	{
		if (32 <= str[idx] && str[idx] <= 126)
			write(1, &str[idx], 1);
		else
			write(1, ".", 1);
		idx++;
	}
	if (str[idx] == 0 && idx != 16)
		write(1, ".", 1);
}

void	hex_digit(int hex)
{
	write(1, &"0123456789abcdef"[hex], 1);
}
