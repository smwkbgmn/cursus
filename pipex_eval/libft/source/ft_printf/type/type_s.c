/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 00:54:28 by donghyu2          #+#    #+#             */
/*   Updated: 2023/05/14 19:02:40 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_bool	type_s(va_list *ptr, t_list *head)
{
	char	*value;
	char	*content;

	value = va_arg(*ptr, char *);
	if (value)
		content = ft_strdup(value);
	else
		content = ft_strdup("(null)");
	if (content)
	{
		ft_lstidx(head, 3)->content = content;
		return (TRUE);
	}
	else
		return (FALSE);
}
