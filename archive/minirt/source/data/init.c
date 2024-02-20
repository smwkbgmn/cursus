/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:20:38 by donghyu2          #+#    #+#             */
/*   Updated: 2024/02/01 17:27:07 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static int	open_file(char *fname);
static void	valid_fname(char *fname);
void		set_window(t_win *win, t_size size);

void	init(char *fname, t_render *data)
{
	ft_memset(data, NONE, sizeof(t_render));
	parse(open_file(fname), data);
	data->scene.img = image(16.0 / 9.0, WIN_WIDTH);
	data->scene.view = viewport(&data->scene);
	set_window(&data->window, data->scene.img.size);
}

static int	open_file(char *fname)
{
	int	fd;

	valid_fname(fname);
	fd = open(fname, O_RDONLY);
	if (fd == ERROR)
		err_sys("open");
	return (fd);
}

static void	valid_fname(char *fname)
{
	char	*extension;

	extension = ft_strrchr(fname, '.');
	if (!extension || ft_strncmp(extension, ".rt", 4) != MATCH)
		err_usr("ensure file extension is '.rt'");
}

void	set_window(t_win *win, t_size size)
{
	win->mlx = mlx_init();
	if (!win->mlx)
		err_usr("fail to mlx_init");
	win->ptr = mlx_new_window(win->mlx, (int)size.x, (int)size.y, "miniRT");
	if (!win->ptr)
		err_usr("fail to mlx_new_window");
}
