/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 19:57:03 by donghyu2          #+#    #+#             */
/*   Updated: 2022/09/01 21:06:36 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_space(char letter);
int	is_digit(char letter);

int	ft_atoi(char *str)
{
	int	num;
	int	sign;

	while (is_space(*str) == 1)
		str++;
	sign = 1;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	num = 0;
	while (is_digit(*str) == 1)
	{
		num = (num * 10) + *str - '0';
		str++;
	}
	return (num * sign);
}

int	is_space(char letter)
{
	if (letter == '\t' || letter == '\n' || letter == '\v')
		return (1);
	else if (letter == '\f' || letter == '\r' || letter == ' ')
		return (1);
	else
		return (0);
}

int	is_digit(char letter)
{
	if ('0' <= letter && letter <= '9')
		return (1);
	else
		return (0);
}
