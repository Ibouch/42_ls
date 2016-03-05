

#include <ft_ls.h>

void	dir_lstdel(t_dir **alst)
{
	t_dir	*begin;
	t_dir	*to_free;

	begin = *alst;
	if (begin != NULL)
	{
		while (begin != NULL)
		{
			ft_strdel(&(begin->path));
			to_free = begin;
			begin = begin->next;
			free(to_free);
		}
		*alst = NULL;
	}
}
