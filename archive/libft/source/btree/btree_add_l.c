/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_add_l.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:34:07 by donghyu2          #+#    #+#             */
/*   Updated: 2023/10/07 23:58:07 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	btr_add_l(t_btree **root, t_btree *node)
{
	t_btree	*last;

	if (!(*root))
		*root = node;
	else
	{
		last = *root;
		while (last)
			last = last->left;
		last->left = node;
	}
}
