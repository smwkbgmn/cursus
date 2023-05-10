#include "mlx.h"

int 	main(void)
{
	void	*mlx;
	void	*win;
	void	*img;
	int		x;
	int		y;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "new");
	img = mlx_png_file_to_image(mlx, "../assets/tile/empty.png", &x, &y);
	mlx_put_image_to_window(mlx, win, img, 234, 234);
	mlx_loop(mlx);
	return (0);
}