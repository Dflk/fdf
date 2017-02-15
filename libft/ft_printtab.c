#include <libft.h>

void	ft_printtab(char **tab)
{
	while (tab && *tab)
	{
		ft_putstr(*tab);
		ft_putchar('\n');
		tab++;
	}
}
