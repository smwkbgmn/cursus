/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:22:55 by donghyu2          #+#    #+#             */
/*   Updated: 2023/10/02 17:32:47 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree	*btr_new(void *val)
{
	t_btree	*new;

	new = ft_calloc(1, sizeof(t_btree));
	if (new)
	{
		new->value = val;
		new->left = NULL;
		new->right = NULL;
		return (new);
	}
	else
		return (NULL);
}
