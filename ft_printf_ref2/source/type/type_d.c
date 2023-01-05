/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 00:54:00 by donghyu2          #+#    #+#             */
/*   Updated: 2023/01/04 12:42:21 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>

t_list	*spcf_d(va_list *ptr)
{
	t_list	*head;
	char	*content;

	head = 0;
	content = ft_itoa(va_arg(*ptr, int));
	if (content)
	{
		if (*content == '-')
		{
			head = ft_lstnew(ft_strdup("-"));
			ft_lstadd_back(&head, ft_lstnew(ft_strdup(content + 1)));
			free(content);
		}
		else
			head = ft_lstnew(content);
	}
	return (head);
}
