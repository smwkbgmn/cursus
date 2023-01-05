/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 00:54:11 by donghyu2          #+#    #+#             */
/*   Updated: 2023/01/04 12:36:24 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_list	*spcf_p(va_list *ptr)
{
	t_list	*head;
	char	*content;

	head = 0;
	content = ft_itoa_address((unsigned long)va_arg(*ptr, void *));
	if (content)
		head = ft_lstnew(content);
	return (head);
}
