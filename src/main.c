#include <fdf.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
	t_mlx	mlx;
	t_dot	**map;
	int		fd;

	ft_bzero((void*)&mlx, sizeof(mlx));
	if (argc != 2)
		ft_error(USAGE);
	else if (-1 == (fd = ft_open(argv[1])))
		ft_error(FILENOTFOUND);
	else if (-1 == ft_parse(fd, &mlx))
		ft_error(PARSEERROR);
	ft_fdf(&mlx);
	map = mlx.map;
	ft_freesafe((void**)mlx.map, mlx.lines);
	ft_freesafe((void**)&(mlx.map), 1);
}
