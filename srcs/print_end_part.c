
#include <ft_ls.h>

void	print_end_part(t_env *e, t_bool is_dir)
{
	if (is_dir == 1)
		ft_putendl(e->file->name);
	else
		ft_putendl(e->file->path);
	if ((e->file->is_dir == TRUE) && e->flg->rec == TRUE)
	{
		if ((ft_strcmp(".", e->file->name)) != 0 &&
			(ft_strcmp("..", e->file->name)) != 0)
		{
			dir_addback(&e->dir->rec, e->file->path);
		}
	}
}
