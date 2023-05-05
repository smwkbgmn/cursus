/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 22:29:33 by donghyu2          #+#    #+#             */
/*   Updated: 2023/05/06 01:24:50 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	void	*mlx;
	void	*mlx_window;
	char	*filename = "./assets/Grass_01.png";
	void	*tile;
	int		x;
	int		y;

	mlx = mlx_init();
	mlx_window = mlx_new_window(mlx, 1920, 1080, "HELL");
	tile = mlx_png_file_to_image(mlx, filename, &x, &y);
	mlx_put_image_to_window(mlx, mlx_window, tile, 0, 0);
	mlx_loop(mlx);
	return (0);
}
