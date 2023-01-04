/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utill_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 13:07:57 by donghyu2          #+#    #+#             */
/*   Updated: 2023/01/04 12:42:47 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>

static t_list	*get_list_value(va_list *ptr, short idx_t);
static void		get_list_flag(const char *str, t_list **head);
static short	*get_switchs(const char *str);
static short	check_str(const char *str, short idx_f);

t_list	*get_list(const char *str, va_list *ptr, size_t len_f)
{
	t_list	*head;

	head = check_percent(str);
	if (!head)
		head = get_list_value(ptr, get_type(str[len_f]));
	if (head)
		get_list_flag(str, &head);
	return (head);
}

static t_list	*get_list_value(va_list *ptr, short idx_t)
{
	t_list		*(*types[9])(va_list *);

	set_type(types);
	return (types[idx_t](ptr));
}

static void	get_list_flag(const char *str, t_list **head)
{
	void	(*flags[7])(const char *, t_list **head);
	short	*switchs;
	short	idx_f;

	set_flag(flags);
	switchs = get_switchs(str);
	if (switchs)
	{
		idx_f = 0;
		while (idx_f < 7)
		{
			if (switchs[idx_f])
				flags[idx_f](str, head);
			idx_f++;
		}
		free(switchs);
	}
}

static short	*get_switchs(const char *str)
{
	short	*switchs;
	short	idx_f;

	switchs = ft_calloc(7, 4);
	if (switchs)
	{
		idx_f = -1;
		while (++idx_f < 7)
		{
			if ((idx_f == 1 || idx_f == 4) && switchs[idx_f - 1] == 1
				&& find_type(str) != 8)
				continue ;
			else if ((idx_f == 4 || idx_f == 6) && switchs[5] == 1)
				continue ;
			else if (idx_f == 6 && switchs[4] == 1)
				continue ;
			else
				switchs[idx_f] = check_str(str, idx_f);
		}
	}
	return (switchs);
}

static short	check_str(const char *str, short idx_f)
{
	while (get_type(*str) == -1)
	{
		if (idx_f == 4)
		{
			if (!(get_flag(*str) < 3))
				break ;
		}
		else if (idx_f == 6)
		{
			if (!(get_flag(*str) < 3 || *str == '0'))
				break ;
		}
		else
		{
			if (get_flag(*str) == idx_f)
				break ;
		}
		str++;
	}
	if (get_flag(*str) == idx_f)
		return (1);
	else
		return (0);
}
