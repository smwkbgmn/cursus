/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ref.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 14:47:42 by donghyu2          #+#    #+#             */
/*   Updated: 2022/08/28 21:02:27 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_address(unsigned long address, int idx);
void	print_hex(char *str, int *size, int idx, int vald);
void	print_str(char *str, int *size, int idx);
void	hex_digit(int hex);

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	idx;
	int size_hex;
	int size_str;
	
	idx = 0;
	size_hex = (int)size;
	size_str = (int)size;
	while (idx < size)
	{
		print_address((unsigned long)&addr[idx], 0);
		write(1, ": ", 2);
		print_hex((char*)&addr[idx], &size_hex, 0, 0);
		print_str((char*)&addr[idx], &size_str, 0);
		write(1, "\n", 1);
		idx += 16;
	}
	return (addr);
}

void	print_address(unsigned long address, int idx)
{
	if (address > 15)
		print_address(address / 16, ++idx);
	while (address < 16 && ++idx < 16)
		write(1, "0", 1);
	hex_digit(address % 16);
}

void	print_hex(char *str, int *size, int idx, int vald)
{
	if (vald == 0 && *size > 0)
	{
		if (*str >= 16)
			hex_digit(*str / 16);
		else
			write(1, "0", 1);
		hex_digit(*str % 16);
		*size -= 1;
	}
	else
		write(1, "  ", 2);
	if (idx % 2 == 1)
		write (1, " ", 1);
	if (*str == 0)
		vald = 1;
	if (idx < 15)
		print_hex(++str, size, ++idx, vald); 
}

void	print_str(char *str, int *size, int idx)
{
	if (32 <= *str && *str <= 126)
		write(1, str, 1);
	else
		write(1, ".", 1);
	if (*str == 0)
		idx = 15;
	*size -= 1;
	if (idx < 15 && *size > 0)
		print_str(++str, size, ++idx);
}

void	hex_digit(int hex)
{
	write(1, &"0123456789abcdef"[hex], 1);
}
