/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 21:54:49 by donghyu2          #+#    #+#             */
/*   Updated: 2024/01/24 09:21:25 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "libft.h"
# include "draw.h"
# include "error.h"

# define LOOP 1
# define MATCH 0

# define WIN_WIDTH 1720

// init.c
void	init(char *fname, t_render *data);

// parse.c
void	parse(int fd, t_render *data);

// utill.c
t_vec	get_vec(char *arg, t_intvl intvl);
t_point	get_point(char *arg);
t_color	get_color(char *arg);
t_scl	get_scl(char *arg, t_intvl intvl);

#endif