/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_seeing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghki2 <donghki2@student.42seoul>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 19:20:07 by donghki2          #+#    #+#             */
/*   Updated: 2022/05/29 21:42:13 by donghki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_seeing_row(int table[4][4], int offset, int moving, int *max)
{
	if (table[offset][moving] > *max)
	{
		*max = table[offset][moving];
		return (1);
	}
	else
		return (0);
}
