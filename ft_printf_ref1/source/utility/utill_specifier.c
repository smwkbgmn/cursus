/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utill_specifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:35:25 by donghyu2          #+#    #+#             */
/*   Updated: 2023/01/03 21:05:38 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

#include <stdlib.h>

void	set_spcf(t_list *(*specifiers[8])(va_list *))
{
	specifiers[0] = &spcf_c;
	specifiers[1] = &spcf_d;
	specifiers[2] = &spcf_i;
	specifiers[3] = &spcf_p;
	specifiers[4] = &spcf_s;
	specifiers[5] = &spcf_u;
	specifiers[6] = &spcf_x_lower;
	specifiers[7] = &spcf_x_upper;
}

short	get_spcf(char c)
{
	char	spcf_set[10];
	short	idx;

	ft_strlcpy(spcf_set, "cdipsuxX%", 10);
	idx = 0;
	while (spcf_set[idx])
	{
		if (spcf_set[idx] == c)
			return (idx);
		idx++;
	}
	return (-1);
}

short	find_spcf(const char *str)
{
	while (get_spcf(*str) == -1)
		str++;
	return (get_spcf(*str));
}

t_list	*check_percent(const char *str)
{
	t_list	*head;
	char	*str_percent;

	head = 0;
	while (get_spcf(*str) == -1)
		str++;
	if (get_spcf(*str) == 8)
	{
		str_percent = malloc(2);
		if (str_percent)
		{
			str_percent[0] = '%';
			str_percent[1] = 0;
			head = ft_lstnew(str_percent);
		}
	}
	return (head);
}
