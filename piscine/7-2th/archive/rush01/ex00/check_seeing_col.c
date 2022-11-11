/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_seeing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghki2 <donghki2@student.42seoul>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 19:20:07 by donghki2          #+#    #+#             */
/*   Updated: 2022/05/29 22:35:15 by donghki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_seeing_col(int table[4][4], int offset, int moving, int *max)
{
	if (table[moving][offset] > *max)
	{
		*max = table[moving][offset];
		return (1);
	}
	else
		return (0);
}
