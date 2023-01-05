/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spcf_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 00:54:28 by donghyu2          #+#    #+#             */
/*   Updated: 2023/01/03 14:13:25 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_list	*spcf_s(va_list *ptr)
{
	t_list	*head;
	char	*content;

	content = va_arg(*ptr, char *);
	if (content)
		head = ft_lstnew(ft_strdup(content));
	else
		head = ft_lstnew(ft_strdup("(null)"));
	return (head);
}
