/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghki2 <donghki2@student.42seoul>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 19:59:27 by donghki2          #+#    #+#             */
/*   Updated: 2022/06/01 17:21:24 by donghki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdint.h>

char	get_char(int hex, char letter)
{
	if (hex == -1)
	{
		write (1, &letter, 1);
		return (0);
	}
	else
	{
		if ('0' + hex > '9')
			return ('a' + hex - 10);
		else
			return ('0' + hex);
	}
}

void	print_address(uintptr_t address)
{
	int	counter;

	counter = (sizeof(address) << 3) - 4;
	while (counter >= 0)
	{
		get_char (-1, get_char((address >> counter) & 0xf, 0));
		counter -= 4;
	}
	get_char (-1, ':');
	get_char (-1, ' ');
}

void	print_string_hex(char *str, int counter)
{
	int	end;
	int	start;
	int	delimiter;

	start = counter * 16;
	end = (counter + 1) * 16;
	while (start < end && str[start])
	{
		if (str[start] < 16)
			get_char (-1, '0');
		else
			get_char (-1, get_char(str[start] / 16, 0));
		get_char (-1, get_char(str[start] % 16, 0));
		if (start % 2 == 1)
			get_char (-1, ' ');
		start++;
	}
	if (str[start] == '\0')
	{
		get_char (-1, '0');
		get_char (-1, '0');
	}
	while (start++ < end)
		get_char (-1, ' ');
}

void	print_string(char *str, int counter)
{
	int	end;
	int	start;

	start = counter * 16;
	end = (counter + 1) * 16;
	while (start < end && str[start])
	{
		if (str[start] < 32 || str[start] > 127)
			get_char (-1, '.');
		else
			get_char (-1, str[start]);
		start++;
	}
	if (str[start] == '\0')
		get_char (-1, '.');
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	int				counter;
	uintptr_t		hex_addr[100];
	char			*str[100];

	*str = (char *)addr;
	if (size != 0)
	{
		counter = 0;
		while (counter < size / 16 + 1)
		{
			hex_addr[counter] = (uintptr_t)addr + (counter * 16);
			print_address (hex_addr[counter]);
			print_string_hex (*str, counter);
			print_string (*str, counter);
			get_char (-1, '\n');
			counter++;
		}
	}
	return (addr);
}
