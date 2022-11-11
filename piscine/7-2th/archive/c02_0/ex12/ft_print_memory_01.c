/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghki2 <donghki2@student.42seoul>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 19:59:27 by donghki2          #+#    #+#             */
/*   Updated: 2022/05/31 20:04:26 by donghki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdint.h>

char	get_char_hex(int hex, char letter)
{
	if (hex < 0)
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
		get_char_hex (-1, get_char_hex((address >> counter) & 0xf, 0));
		counter -= 4;
	}
	ft_putchar (':');
	ft_putchar (' ');
}

void	print_string_hex(char *str, int counter)
{
	int	end;
	int	start;
	int	delimiter;

	start = counter * 16;
	end = (counter + 1) * 16;
	while (start < end && str[start] > 0)
	{
		if (str[start] < 16)
			ft_putchar ('0');
		else
			ft_putchar (get_char_hex(str[start] / 16));
		ft_putchar (get_char_hex(str[start] % 16));
		if (start % 2 == 1)
			ft_putchar (' ');
		start++;
	}
	while (start++ < end)
		ft_putchar (' ');
}

void	print_string(char *str, int counter)
{
	int	end;
	int	start;

	start = counter * 16;
	end = (counter + 1) * 16;
	while (start < end && str[start] > 0)
	{
		if (str[start] < 32 || str[end] > 127)
			ft_putchar ('.');
		else
			ft_putchar (str[start]);
		start++;
	}
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
			ft_putchar ('\n');
			counter++;
		}
	}
	return (addr);
}
