/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_width.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:23:55 by donghyu2          #+#    #+#             */
/*   Updated: 2023/01/01 22:38:46 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static size_t	get_len_full_str(t_list *head);

void	flag_width(const char *str, t_list **head)
{
	t_list	*node_new;
	char	*spaces;
	int		width;

	str += pass_flag(str);
	width = ft_atoi(str) - get_len_full_str(*head);
	if (width > 0)
	{
		spaces = get_str_fill_char(width, ' ');
		if (spaces)
		{
			node_new = ft_lstnew(spaces);
			if (node_new)
				ft_lstadd_front(head, node_new);
		}
	}
}

static size_t	get_len_full_str(t_list *head)
{
	size_t	len;

	len = 0;
	while (head)
	{
		len += ft_strlen(head->content);
		head = head->next;
	}
	return (len);
}

// {
// 	char	*result;
// 	int		width;

// 	result = value;
// 	if (*(str - 1) != '0' || check_is_flag_zero(str))
// 	{
// 		width = ft_atoi(str) - ft_strlen(value);
// 		if (width > 0)
// 			result = pad_space(value, width);
// 	}
// 	return (result);
// }

// static	short	check_is_flag_zero(const char *str)
// {
// 	while (get_spcf(*str) == -1)
// 	{
// 		if (get_spcf(*str) == 3)
// 			return (0);
// 		str++;
// 	}
// 	return (1);
// }

// static	char	*pad_space(char *value, int width)
// {
// 	char	*result;
// 	char	*spaces;

// 	result = 0;
// 	spaces = malloc(width + 1);
// 	if (spaces)
// 	{
// 		ft_memset(spaces, ' ', width);
// 		result = ft_strjoin(spaces, value);
// 		free(value);
// 		free(spaces);
// 	}
// 	return (result);
// }