#include <fdf.h>

int	ft_open(char *path)
{
	char	*str;

	if (!path || !(str = ft_strrchr(path, '.')) || ft_strcmp(str, ".fdf"))
		return (-1);
	return (open(path, O_RDONLY));
}
