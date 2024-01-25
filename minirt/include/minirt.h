/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 21:54:49 by donghyu2          #+#    #+#             */
/*   Updated: 2024/01/25 09:27:48 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "libft.h"
# include "data.h"
# include "mlx.h"

# define LOOP 1
# define MATCH 0

# define ON_DESTROY 17

/* draw.c */
void	render(const t_render *data);

// hook.c
void	activate_mlx(const t_render *data);

#endif