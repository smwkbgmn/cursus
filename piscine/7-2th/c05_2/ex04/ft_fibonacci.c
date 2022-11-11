/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghki2 <donghki2@student.42seoul>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:41:17 by donghki2          #+#    #+#             */
/*   Updated: 2022/06/05 18:41:48 by donghki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_number(int *numbers, int index);

int	ft_fibonacci(int index)
{
	int	numbers[3];

	numbers[0] = 0;
	numbers[1] = 1;
	if (index < 0)
		return (-1);
	else if (index == 0)
		return (0);
	else if (index == 1)
		return (1);
	else if (index > 1)
		return (get_number (numbers, index));
	else
		return (0);
}

int	get_number(int *numbers, int index)
{
	if (index > 1)
	{
		numbers[2] = numbers[0] + numbers[1];
		numbers[0] = numbers[1];
		numbers[1] = numbers[2];
		get_number (numbers, index - 1);
	}
	return (numbers[2]);
}
