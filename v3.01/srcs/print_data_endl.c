#include <ft_ls.h>

void	print_data_endl(t_env *e, t_bool dir)
{
	while (e->file != NULL)
	{
		if ((*e).flg->i == TRUE)
		{
			ft_putnbr((*e).file->inoeud);
			ft_putchar(' ');
		}
		if (dir == 1)
			ft_putendl((*e).file->name);
		else
			ft_putendl((*e).file->path);
		if (((*e).file->is_dir == TRUE) && (*e).flg->rec == TRUE)
			if ((ft_strcmp(".", (*e).file->name)) != 0 &&
				(ft_strcmp("..", (*e).file->name)) != 0)
				dir_addback(&e->dir->rec, (*e).file->path);
		e->file = (*e).file->next;
	}
}
