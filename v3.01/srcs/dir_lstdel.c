

#include <ft_ls.h>

void	dir_lstdel(t_dir **alst)
{
	t_dir	*begin;

	begin = *alst;
	if (begin != NULL)
	{
		ft_strdel(&(begin->path));
		ft_memdel((void **)alst);
	}
}
