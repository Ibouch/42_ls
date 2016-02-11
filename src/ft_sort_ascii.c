#include <ft_ls.h>

int	ft_sort_ascii(char **as, int len)
{
	int	i;
	int x;
	char *tmp;

	i = 0;
	if (!(*as))
		return (-1);
	while (i++ < (len - 1))
	{
		while (x < (len - 1))
		{
			if ((ft_strcmp(as[x], as[x + 1])) > 0)
			{	ft_swap_str
				tmp = as[x];
				as[x] = as[x + 1];
				as[x + 1] = tmp;
			}
			++x;
		}
		x = 0;
	}
	return (0);
}

/*
fonction de cmp : lexico
ft_list_sort() trie une liste en place avec une function de cmp.
*/
