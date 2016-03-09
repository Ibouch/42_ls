
#include <ft_ls.h>

void	print_file_lst(t_env *e)
{
	t_file	*f_free;

	if (e->file != NULL)
	{
		f_free = e->file;
		print_data(e, FALSE);
		file_lstdel(&(f_free));
		e->display_data = TRUE;
		if (e->dir != NULL)
			ft_putchar('\n');
	}
}
