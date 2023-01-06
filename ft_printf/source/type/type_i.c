/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_i.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 00:54:03 by donghyu2          #+#    #+#             */
/*   Updated: 2023/01/06 16:45:53 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

#include <stdlib.h>

short	type_i(va_list *ptr, t_list *head)
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
		}
		else
		{
			sign = ft_strdup("\0");
			content = value;
		}
		if (sign && content)
		{
			ft_lstidx(head, 1)->content = sign;
			ft_lstidx(head, 3)->content = content;
			return (SUCCESS);
		}
	}
	return (ERROR);
}

// short	type_i(va_list *ptr, t_list *head)
// {
// 	char	*value;
// 	char	*sign;
// 	char	*content;

// 	value = ft_itoa(va_arg(*ptr, int));
// 	if (value)
// 	{
// 		if (*value == '-')
// 		{
// 			sign = ft_strdup("-");
// 			content = ft_strdup(value + 1);
// 			free(value);
// 			if (sign && content)
// 			{
// 				ft_lstidx(head, 1)->content = sign;
// 				ft_lstidx(head, 3)->content = content;
// 			}
// 			else
// 				return (ERROR);
// 		}
// 		else
// 			ft_lstidx(head, 3)->content = value;
// 		return (SUCCESS);
// 	}
// 	return (ERROR);
// }
