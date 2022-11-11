/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_defaul.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghki2 <donghki2@student.42seoul>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 20:42:32 by donghki2          #+#    #+#             */
/*   Updated: 2022/05/29 21:10:41 by donghki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	set_default(int *moving, int *seeing, int direction)
{
	if (direction == 0)
		*moving = 0;
	else
		*moving = 3;
	*seeing = 1;
}	
