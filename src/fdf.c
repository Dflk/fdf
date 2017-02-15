#include <fdf.h>

void	ft_fdf(t_mlx *mlx)
{
	if (!(mlx->mlx_instance = mlx_init()))
		return ;
	if (!(mlx->window = mlx_new_window (mlx->mlx_instance,
			(mlx->lines) + 100, (mlx->lines) + 100, "Some test")))
		return ;
	ft_printmap(mlx);
	mlx_loop(mlx);
}
