#include <libft.h>

size_t	ft_strtablen(char **tab)
{
	size_t	len;

	len = 0;
	while (tab && tab[len])
		len++;
	return (len);
}

char	**ft_strtabadd(char **res, char *line)
{
	int		len;
	char	**ret;

	len = 0;
	if (!res && !(ret = ft_memalloc(sizeof(char*) * 2)))
		return (NULL);
	else if (res && ((len = (int)ft_strtablen(res)) <= 0
					|| !(ret = ft_memalloc(sizeof(char*) * (len + 2)))))
		return (NULL);
	ret[len] = line;
	while (--len >= 0)
		ret[len] = res[len];
	return (ret);
}

char	**ft_strtabadd_free(char **res, char *line)
{
	char	**kill;

	kill = res;
	res = ft_strtabadd(res, line);
	ft_freesafe((void**)&kill, 1);
	return (res);
}
