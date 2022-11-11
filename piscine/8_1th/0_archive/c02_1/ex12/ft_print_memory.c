/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 14:47:42 by donghyu2          #+#    #+#             */
/*   Updated: 2022/08/30 19:30:21 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_address(unsigned long long address, int idx);
void	print_hex(unsigned char *addr, unsigned char *str, int size, int *vald);
void	print_str(unsigned char *str, int size);
void	hex_digit(int hex);

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned char	str[17];
	unsigned int	idx;
	int				vald;

	idx = 0;
	vald = 0;
	while (idx < size && vald == 0)
	{
		print_address((unsigned long long)&addr[idx], 0);
		print_hex((unsigned char *)&addr[idx], str, (int)size - idx, &vald);
		print_str(str, (int)size - idx);
		write(1, "\n", 1);
		idx += 16;
	}
	return (addr);
}

void	print_address(unsigned long long address, int idx)
{
	if (address >= 16)
		print_address(address / 16, ++idx);
	while (address < 16 && ++idx < 16)
		write(1, "0", 1);
	hex_digit(address % 16);
	if (idx == 1)
		write(1, ": ", 2);
}

void	print_hex(unsigned char *addr, unsigned char *str, int size, int *vald)
{
	int	idx;

	idx = 0;
	while (idx < 16)
	{
		if (*vald == 0 && idx < size)
		{
			if (*addr > 15)
				hex_digit(*addr / 16);
			else
				write(1, "0", 1);
			hex_digit(*addr % 16);
			if (*addr == 0)
				*vald = 1;
			*str++ = *addr++;
		}
		else
			write(1, "  ", 2);
		if (idx % 2 == 1)
			write(1, " ", 1);
		idx++;
	}
}

void	print_str(unsigned char *str, int size)
{
	int	idx;

	idx = 0;
	while (str[idx] && idx < 16 && idx < size)
	{
		if (32 <= str[idx] && str[idx] <= 126)
			write(1, &str[idx], 1);
		else
			write(1, ".", 1);
		idx++;
	}
	if (idx != 16 && idx < size && str[idx] == 0)
		write(1, ".", 1);
}

void	hex_digit(int hex)
{
	write(1, &"0123456789abcdef"[hex], 1);
}
