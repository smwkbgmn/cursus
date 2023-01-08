/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 00:54:00 by donghyu2          #+#    #+#             */
/*   Updated: 2023/01/08 16:35:09 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libftprintf.h"

short	type_d(va_list *ptr, t_list	*head)
{
	char	*content;

	content = ft_itoa(va_arg(*ptr, int));
	if (content)
	{
		if (*content == '-')
		{
			ft_lstidx(head, 1)->content = ft_strdup("-");
			ft_lstidx(head, 3)->content = ft_strdup(content + 1);
			free(content);
		}
		else
			ft_lstidx(head, 3)->content = content;
		return (TRUE);
	}
	else
		return (FALSE);
}
