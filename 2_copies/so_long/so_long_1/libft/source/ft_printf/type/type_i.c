/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_i.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 00:54:03 by donghyu2          #+#    #+#             */
/*   Updated: 2023/05/14 19:02:57 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_printf.h"

static t_bool	apply_to_list(t_list *head, char *sign, char *content);

t_bool	type_i(va_list *ptr, t_list *head)
{
	char	*value;
	char	*sign;
	char	*content;

	value = ft_itoa(va_arg(*ptr, int));
	if (value)
	{
		if (*value == '-')
		{
			sign = ft_strdup("-");
			content = ft_strdup(value + 1);
			free(value);
			return (apply_to_list(head, sign, content));
		}
		else
		{
			ft_lstidx(head, 3)->content = value;
			return (TRUE);
		}
	}
	return (FALSE);
}

static t_bool	apply_to_list(t_list *head, char *sign, char *content)
{
	if (sign && content)
	{
		ft_lstidx(head, 1)->content = sign;
		ft_lstidx(head, 3)->content = content;
		return (TRUE);
	}
	else
	{
		if (sign)
			free(sign);
		if (content)
			free(content);
		return (FALSE);
	}
}
