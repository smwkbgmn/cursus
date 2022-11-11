/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_largest_square.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pji <pji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:37:22 by pji               #+#    #+#             */
/*   Updated: 2022/06/08 17:06:59 by pji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIND_LARGEST_SQUARE_H
# define FIND_LARGEST_SQUARE_H
# include "square.h"

t_square	find_largest_square(char **map, char *structure);
int			check_square(t_square point, char **map, char *structure);
int			find_point(t_square point, char **map, char *structure);
#endif
