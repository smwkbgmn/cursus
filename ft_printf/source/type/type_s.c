/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 00:54:28 by donghyu2          #+#    #+#             */
/*   Updated: 2023/01/04 17:35:07 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

short	type_s(va_list *ptr, t_list *head)
{
	char	*content;

	content = va_arg(*ptr, char *);
	if (content)
		ft_lstidx(head, 3)->content = ft_strdup(content);
	else
		ft_lstidx(head, 3)->content = ft_strdup("(null)");
	return (SUCCESS);
}
