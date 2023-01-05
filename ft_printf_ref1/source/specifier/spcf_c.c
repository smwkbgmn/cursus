/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spcf_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:09:29 by donghyu2          #+#    #+#             */
/*   Updated: 2023/01/02 17:36:45 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

#include <stdlib.h>

t_list	*spcf_c(va_list *ptr)
{
	t_list	*head;
	char	*str_c;

	head = 0;
	str_c = ft_calloc(2, 1);
	if (str_c)
	{
		str_c[0] = va_arg(*ptr, int);
		str_c[1] = 0;
		head = ft_lstnew(str_c);
	}
	return (head);
}
