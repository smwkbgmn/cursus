/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 06:13:42 by donghyu2          #+#    #+#             */
/*   Updated: 2024/01/25 08:05:53 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

void	delete(const t_render *data)
{
	if (data->world.objs)
		ft_lstclear((t_list **)&data->world.objs, &ft_free);
	ft_lstclear((t_list **)&data->world.lights, &ft_free);
}
