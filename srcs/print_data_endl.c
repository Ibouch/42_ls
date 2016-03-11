#include <ft_ls.h>

/*
	We need to remove all space comment by appropriate
	length of space.
*/

void	print_data_endl(t_env *e, t_bool dir)
{
	t_stat	st;

	while (e->file != NULL)
	{
		if ((lstat(e->file->path, &st)) != 0)
		{
			ft_putstr_fd("ft_ls: ", 2);
			perror(e->file->path);
		}
		else
		{
			if (e->flg->i == TRUE)
			{
				ft_putnbr(st.st_ino);
				ft_putchar(' '); /* space */
			}
			if (dir == 1)
				ft_putendl(e->file->name);
			else
				ft_putendl(e->file->path);
			if (((S_ISDIR(st.st_mode)) && e->flg->rec == TRUE) &&
				e->flg->d == FALSE)
				if ((ft_strcmp(".", e->file->name)) != 0 &&
					(ft_strcmp("..", e->file->name)) != 0)
					dir_addback(&e->dir->rec, e->file->path);
		/*
			Il faudra rajouter l'insertion des char * renvoyer par
			readlink dans la liste chainee
		*/
		}
		e->file = e->file->next;
	}
}
