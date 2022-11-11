/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghki2 <donghki2@student.42seoul>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 19:59:27 by donghki2          #+#    #+#             */
/*   Updated: 2022/06/03 01:07:39 by donghki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char	get_char(int hex, char letter, int repeat)
{
	int	cnt;
	
	if (hex == -1)
	{
		cnt = 0;
		while (cnt++ < repeat)
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

void	print_address(long address)
{
	int	counter;

	counter = (sizeof(address) << 3) - 4;
	while (counter >= 0)
	{
		get_char (-1, get_char((address >> counter) & 0xf, 0, 1), 1);
		counter -= 4;
	}
	get_char (-1, ':', 1);
	get_char (-1, ' ', 1);
}

void	print_string_hex(char *str, int counter)
{
	int	end;
	int	start;

	start = counter * 16;
	end = (counter + 1) * 16;
	while (start < end)
	{
		if (str[start])
		{
			if (str[start] < 16)
				get_char (-1, '0', 1);
			else
				get_char (-1, get_char(str[start] / 16, 0, 0), 1);
			get_char (-1, get_char(str[start] % 16, 0, 0), 1);
		}
		else if (str[start] == '\0' && str[start - 1] != '\0')
			get_char (-1, '\0', 1);
		else
			get_char (-1, ' ', 2);
		if (start % 2 == 1)
			get_char (-1, ' ', 2);
		start++;
	}
}

void	print_string(char *str, int counter)
{
	int	end;
	int	start;

	start = counter * 16;
	end = (counter + 1) * 16;
	while (start < end && str[start])
	{
		if (str[start] < 32 || str[start] == 127)
			get_char (-1, '.', 1);
		else
			get_char (-1, str[start], 1);
		start++;
	}
	if (str[start] == '\0')
		get_char (-1, '.', 1);
}

int	valid(char *str)
{
	unsigned int	size;
	
	size = 0;
	while (str[size])
		size++;
	return (size);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	counter;
	long			hex_addr[100];
	char			*str[100];
	unsigned int				i;
	*str = (char *)addr;
	//size = valid (*str);
	i = 0;
	while (str[i])
		i++;
	printf ("size : %d\n", i);
	if (size != 0)
	{
		counter = 0;
		while (counter < i / 16 + 1)
		{
			hex_addr[counter] = (long)addr + (counter * 16);
			print_address (hex_addr[counter]);
			print_string_hex (*str, counter);
			print_string (*str, counter);
			get_char (-1, '\n', 1);
			counter++;
		}
	}
	return (addr);
}
