#include <fdf.h>

static int		ft_checklineformat(char *line)
{
	while (line && *line && ft_isprint(*line))
		line++;
	return (*line);
}

static int		ft_dots(char *line)
{
	int	res;

	res = 0;
	while (*line && ft_isspace(*line))
		line++;
	if (*line)
		res = 1;
	while (*line && !ft_isspace(*line))
		line++;
	return *line ? (res + ft_dots(line)) : (res);
}

static t_dot	*ft_fillmap(char *line, int y)
{
	t_dot	*dots;
	int		dots_number;
	int		i;

	dots_number = ft_dots(line);
	i = 0;
	if (!(dots = ft_memalloc(sizeof(t_dot) * (dots_number + 1))))
		return NULL;
	while (++i < dots_number)
	{
		while (*line && ft_isspace(*line))
			line++;
		if (*line)
		{
			(dots + i)->z = ft_atoi(line);
			(dots + i)->x = i;
			(dots + i)->y = y;
		}
		while (*line && !ft_isspace(*line))
			line++;
		i++;
	}
	return (dots);
}

static int		ft_config_map(char **tab, t_mlx *mlx)
{
	size_t	len;
	size_t	i;

	len = ft_strtablen(tab);
	i = 0;
	if (!(mlx->map = (t_dot*)ft_memalloc(sizeof(t_dot*) * len)))
		return (-1);
	while (i < len)
	{
		if (!((mlx->map)[i] = ft_fillmap(tab[i], i)))
		{
			ft_freesafe((void**)mlx->map, i);
			ft_freesafe((void**)&(mlx->map), 1);
			return (-1);
		}
		i++;
	}
	mlx->lines = len;
	return (1);
}

int				ft_parse(int fd, t_mlx *mlx)
{
	char	*line;
	char	**tab;
	int		ret;
	int		i;

	tab = NULL;
	i = 0;
	while ((ret = get_next_line(fd, &line)))
	{
		if ((-1 == ret || -1 == ft_checklineformat(line)))
		{
			ft_freesafe((void**)&line, 1);
			ft_freesafe((void**)tab, ft_strtablen(tab));
			ft_freesafe((void**)&tab, 1);
			return (-1);
		}
		tab = ft_strtabadd_free(tab, line);
		i++;
	}
	ret = ft_config_map(tab, mlx);
	ft_freesafe((void**)tab, 1);
	ft_freesafe((void**)&tab, 1);
	return (ret);
}
