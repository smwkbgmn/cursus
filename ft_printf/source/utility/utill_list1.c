/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utill_list1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 13:07:57 by donghyu2          #+#    #+#             */
/*   Updated: 2023/01/08 16:35:39 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "libftprintf.h"

short	init_list(t_list **head)
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

int	write_list(t_list *head, short idx_t)
{
	size_t	len_s;
	int		len_w;

	len_w = 0;
	while (head && len_w != ERROR)
	{
		if (head->content)
		{
			if (idx_t == 0 && ft_memcmp(head->content, "\0", 1) == 0)
				len_s = 1;
			else
				len_s = ft_strlen(head->content);
			apply_len(write(1, head->content, len_s), &len_w);
		}
		head = head->next;
	}
	return (len_w);
}

void	free_content(void *content)
{
	if (content)
		free(content);
}
