#ifndef _FDF_
# define _FDF_

# include	<mlx.h>
# include	<mlx_int.h>
# include	<sys/types.h>
# include	<sys/stat.h>
# include	<fcntl.h>
# include	<libft.h>

/*
** Errors define
*/
# define USAGE			"Usage: {PATH}/fdf some_file.fdf"
# define READERROR		"Read error"
# define PARSEERROR		"Parse error"
# define FILENOTFOUND	"File not found or wrong format"

typedef struct	s_dot
{
	int	x;
	int	y;
	int	z;
	int	color;
}				t_dot;

typedef struct	s_mlx
{
	void	*mlx_instance;
	void	*window;
	int		lines;
	t_dot	**map;
}				t_mlx;

/*
**open.c
*/
int		ft_open(char *path);

/*
**parse.c
*/
int		ft_parse(int fd, t_mlx *mlx);

/*
**error.c
*/
void	ft_error(char *error);

/*
**fdf.c
*/
void	ft_fdf(t_mlx *mlx);

/*
**printmap.c
*/
void	ft_printmap(t_mlx *mlx);
#endif
