/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 14:47:42 by donghyu2          #+#    #+#             */
/*   Updated: 2022/08/28 23:32:32 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_address(long long address, int idx);
void	print_hex(char *letter, int *null_check);
void	print_str(char *letter, int *null_check);
void	hex_digit(int hex);

void	*ft_print_memory(void *addr, unsigned int size)
{
	int	idx1;
	int	idx2;
	int	null_check;

	idx1 = -1;
	idx2 = -1;
	null_check = 0;
	while (++idx1 < ((int)size + 16 - 1) / 16 && (int)size != 0)
	{
		print_address((long long)&addr[idx1 * 16], 0);
		write(1, ": ", 2);
		while (++idx2 < (idx1 + 1) * 16)
		{
			if (idx2 < (int)size && null_check == 0)
				print_hex((char*)&addr[idx2], &null_check);
			else
				write(1, "  ", 2);
			if (idx2 % 2 == 1)
				write(1, " ", 1);
		}
		null_check = 0;
		idx2 -= 17;
		while (++idx2 < (idx1 + 1) * 16 && idx2 < (int)size && null_check == 0)
			print_str((char*)&addr[idx2], &null_check);
		idx2--;
		write(1, "\n", 1);
	}
	return (addr);
}

void	print_address(long long address, int idx)
{
	if (address > 15)
		print_address(address / 16, ++idx);
	while (address < 16 && ++idx < 16)
		write(1, "0", 1);
	hex_digit(address % 16);
}

void	print_hex(char *letter, int *null_check)
{
	if (*letter > 15)
		hex_digit(*letter / 16);
	else
		write(1, "0", 1);
	hex_digit(*letter % 16);
	if (*letter == 0)
		*null_check = 1;
}

void	print_str(char *letter, int *null_check)
{
	if (32 <= *letter && *letter <= 126)
		write(1, letter, 1);
	else
		write(1, ".", 1);
	if (*letter == 0)
		*null_check = 1;
}

void	hex_digit(int hex)
{
	write(1, &"0123456789abcdef"[hex], 1);
}
