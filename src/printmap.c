#include <fdf.h>

void	ft_printmap(t_mlx	*mlx)
{
	int				i;
	t_dot			**map;
	t_dot			*dot;

	map = mlx->map;
	while (map)
	{
		i = -1;
		dot = *map;
		while (dot)
		{
			mlx_pixel_put (mlx->mlx_instance, mlx->window, dot->x, dot->y, 0x00FF0000);
			dot++;
		}
		map++;
	}
}
