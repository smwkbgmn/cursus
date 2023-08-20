/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 00:18:01 by donghyu2          #+#    #+#             */
/*   Updated: 2023/07/28 19:43:52 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	init_game(t_map map)
{
	t_game	game;

	game.collected = 0;
	game.goal = game_goal(map);
	game.win = FALSE;
	return (game);
}
