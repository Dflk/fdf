#include <libft.h>

int		ft_freesafe(void **kill, size_t n)
{
	if (kill && *kill)
	{
		while (n--)
		{
			free(*kill);
			*kill = NULL;
			if (n)
				kill++;
		}
	}
	return (1);
}
