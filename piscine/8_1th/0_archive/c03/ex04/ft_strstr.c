/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 17:31:54 by donghyu2          #+#    #+#             */
/*   Updated: 2022/08/31 15:18:01 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	idx;

	if (*to_find == 0)
		return (str);
	while (*str)
	{
		idx = 0;
		while (str[idx] == to_find[idx] && to_find[idx])
			idx++;
		if (to_find[idx] == 0)
			return (str);
		str++;
	}
	return (0);
}
