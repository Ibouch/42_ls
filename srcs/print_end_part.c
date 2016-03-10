
#include <ft_ls.h>

void	print_end_part(t_env *e, t_stat st, t_bool is_dir)
{
	char	*lnk_name;
	ssize_t	len;

	if ((S_ISLNK(st.st_mode)) == TRUE)
	{
		if ((lnk_name = ft_strnew(st.st_size)) == NULL)
			error_system();
		if ((len = readlink(e->file->path, lnk_name, st.st_size)) == (-1))
		{
			ft_putstr_fd("ft_ls: ", 2);
			perror(e->file->path);
			return ;
		}
		lnk_name[len] = '\0';
	}
	if (is_dir == 1)
	{
		if ((S_ISLNK(st.st_mode)) == TRUE)
		{
			ft_putstr(e->file->name);
			ft_putstr(" -> ");
			ft_putendl(lnk_name);
			ft_strdel(&lnk_name);
		}
		else
			ft_putendl(e->file->name);
	}
	else
	{
		if ((S_ISLNK(st.st_mode)) == TRUE)
		{
			ft_putstr(e->file->path);
			ft_putstr(" -> ");
			ft_putendl(lnk_name);
			ft_strdel(&lnk_name);
		}
		else
			ft_putendl(e->file->path);
	}
	if ((e->file->is_dir == TRUE) && e->flg->rec == TRUE)
	{
		if ((ft_strcmp(".", e->file->name)) != 0 &&
			(ft_strcmp("..", e->file->name)) != 0)
		{
			dir_addback(&e->dir->rec, e->file->path);
		}
	}
}
