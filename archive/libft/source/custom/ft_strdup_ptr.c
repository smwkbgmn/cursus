/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:44:21 by donghyu2          #+#    #+#             */
/*   Updated: 2023/09/19 18:45:08 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

void	copy_value(char *dup, char *start, char *end);

char	*ft_strdup_ptr(char *start, char *end)
{
	char	*dup;

	if (start && end && start != end)
	{
		dup = ft_calloc(end - start + 1, 1);
		if (dup)
			copy_value(dup, start, end);
		return (dup);
	}
	return (NULL);
}

void	copy_value(char *dup, char *start, char *end)
{
	if (start != end && *start)
	{
		*dup = *start;
		copy_value(dup + 1, start + 1, end);
	}
}
