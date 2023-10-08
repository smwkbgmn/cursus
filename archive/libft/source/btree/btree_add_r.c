/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_add_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 23:51:40 by donghyu2          #+#    #+#             */
/*   Updated: 2023/10/07 23:59:16 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	btr_add_r(t_btree **root, t_btree *node)
{
	t_btree	*last;

	if (!(*root))
		*root = node;
	else
	{
		last = *root;
		while (last)
			last = last->right;
		last->right = node;
	}
}
