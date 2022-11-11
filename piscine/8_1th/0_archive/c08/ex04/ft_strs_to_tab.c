/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 20:59:58 by donghyu2          #+#    #+#             */
/*   Updated: 2022/09/07 15:33:30 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int		ft_strlen(char *str);
char	*ft_strdup(char *src);

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			idx;
	t_stock_str	*new;

	new = malloc(sizeof(t_stock_str) * (ac + 1));
	if (new == 0)
		return (0);
	idx = 0;
	while (idx < ac)
	{
		new[idx].size = ft_strlen(av[idx]);
		new[idx].str = ft_strdup(av[idx]);
		new[idx].copy = ft_strdup(new[idx].str);
		idx++;
	}
	new[idx].str = 0;
	return (new);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

char	*ft_strdup(char *src)
{
	char	*str;
	int		idx;

	str = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (str == 0)
		return (0);
	idx = 0;
	while (src[idx])
	{
		str[idx] = src[idx];
		idx++;
	}
	str[idx] = 0;
	return (str);
}
