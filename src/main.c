#include <ft_ls.h>

int	main(int ac, char **av)
{
	int x = 0;

	ft_strsort(av, ac);
	while (++x < ac)
		ft_putendl(av[x]);
	return (0);
}
