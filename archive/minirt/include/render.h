/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 21:54:49 by donghyu2          #+#    #+#             */
/*   Updated: 2024/02/01 19:07:01 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "data.h"

# define WIN_WIDTH 1920
# define ON_DESTROY 17

// init.c
void	init(char *fname, t_render *data);

// render.c
void	render(const t_render *data);

// hook.c
void	activate_mlx(const t_render *data);

#endif