/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_percent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:16:09 by donghyu2          #+#    #+#             */
/*   Updated: 2023/01/06 16:19:55 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

short	type_percent(t_list *head)
{
	char	*content;

	content = ft_calloc(2, 1);
	if (content)
	{
		content[0] = '%';
		ft_lstidx(head, 3)->content = content;
		return (SUCCESS);
	}
	else
		return (ERROR);
}
