/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_row.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghki2 <donghki2@student.42seoul>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 19:42:16 by donghki2          #+#    #+#             */
/*   Updated: 2022/05/29 21:16:36 by donghki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap_row(int source, int target, int table[4][4])
{
	int	moving;
	int	temp;

	moving = 0;
	while (moving < 4)
	{
		temp = table[source][moving];
		table[source][moving] = table[target][moving];
		table[target][moving] = temp;
		moving++;
	}
}
