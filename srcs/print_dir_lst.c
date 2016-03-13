
#include <ft_ls.h>

static void	listing_contents(t_env *e, int i)
{
	t_file	*f_free;
	t_dir	*tmp;

	if ((e->display_data == TRUE || i > 0) || e->dir->next != NULL)
		e->display_data = TRUE;
	if (e->file != NULL)
	{
		f_free = e->file;
		print_data(e, TRUE);
		file_lstdel(&(f_free));
		e->display_data = TRUE;
	}
	if (e->display_data == TRUE && (e->dir->next != NULL ||
		(e->flg->rec == TRUE && e->dir->rec != NULL)))
		ft_putchar('\n');
	tmp = e->dir->rec;
	if (tmp != NULL)
	{
		while (e->dir->rec->next != NULL)
			e->dir->rec = e->dir->rec->next;
		e->dir->rec->next = e->dir->next;
		e->dir->next = tmp;
	}
}

void		print_dir_lst(t_env *e)
{
	int		i;
	t_dir	*d_free;

	i = 0;
	while (e->dir != NULL)
	{
		if ((myopendir(e, e->dir->path, i)) == (-1))
			e->display_data = TRUE;
		else
			listing_contents(e, i);
		d_free = e->dir;
		e->dir = e->dir->next;
		dir_lstdel(&d_free);
		++i;
	}
}
