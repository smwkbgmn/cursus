/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 21:54:49 by donghyu2          #+#    #+#             */
/*   Updated: 2023/11/03 14:29:07 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "libft.h"
# include "mlx.h"

typedef struct s_mlx	t_mlx;

void	init_mlx(t_mlx *mlx);

void	*try(void *ptr);
void	err_sys(char *msg);
void	err_usr(char *msg);

struct s_mlx
{
	void	*ptr;
	void	*win;
};

#endif