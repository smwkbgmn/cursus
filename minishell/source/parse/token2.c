/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 13:16:33 by donghyu2          #+#    #+#             */
/*   Updated: 2023/09/15 14:50:39 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_metachar	get_metachar(char *str)
{
	int	value;

	if (*str == AMPRSND || *str == PIPE || *str == DOLR
		|| *str == RDR_IN || *str == RDR_OUT
		|| *str == PRNTSIS_OPN || *str == PRNTSIS_CLS)
	{
		value = (*str << 8) + *(str + 1);
		if (value == AND || value == OR
			|| value == HRDC || value == RDR_OUT_APND)
			return (value);
		else if (*str != AMPRSND)
			return (*str);
	}
	return (NONE);
}

t_bool	hit_delimit(char c, char *delim)
{
	if (*delim)
	{
		if (c == *delim || c == '\0')
			return (TRUE);
		else
			return (hit_delimit(c, delim + 1));
	}
	else
		return (FALSE);
}

t_bool	is_literal(char c, t_bool qte_sgl, t_bool qte_dbl)
{
	return ((c != QTE_SGL && c != QTE_DBL)
		|| ((c == QTE_SGL && qte_dbl == TRUE)
			|| (c == QTE_DBL && qte_sgl == TRUE)));
}
