/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_hash.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:23:29 by donghyu2          #+#    #+#             */
/*   Updated: 2023/01/01 08:04:28 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static short	check_case(const char *str);

void	flag_hash(const char *str, t_list **head)
{
	t_list	*node_new;
	char	*sign;

	if (check_case(str))
		sign = ft_strdup("0X");
	else
		sign = ft_strdup("0x");
	node_new = ft_lstnew(sign);
	if (node_new)
		ft_lstadd_front(head, node_new);
}

static short	check_case(const char *str)
{
	while (get_spcf(*str) == -1)
		str++;
	return (*str == 'X');
}
