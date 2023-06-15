/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utill_list1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 13:07:57 by donghyu2          #+#    #+#             */
/*   Updated: 2023/05/14 19:13:25 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "ft_printf.h"

t_bool	init_list(t_list **head)
{
	t_list	*node;
	short	cnt;

	cnt = 0;
	*head = 0;
	while (cnt < 5)
	{
		node = ft_lstnew((void *)0);
		if (node)
			ft_lstadd_back(head, node);
		else
		{
			ft_lstclear(head, &free_content);
			return (FALSE);
		}
		cnt++;
	}
	return (TRUE);
}

int	write_list(t_list *head, short type)
{
	size_t	len_content;
	int		len_printed;

	len_printed = 0;
	while (head && len_printed != ERROR)
	{
		if (head->content)
		{
			if (type_c_with_null(type, head->content))
				len_content = 1;
			else
				len_content = ft_strlen(head->content);
			apply_len(write(1, head->content, len_content), &len_printed);
		}
		head = head->next;
	}
	return (len_printed);
}

void	free_content(void *content)
{
	if (content)
		free(content);
}
