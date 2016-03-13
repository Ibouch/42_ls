
#include <ft_ls.h>

static void	print_path(char *path, char *lnk_name, t_stat st)
{
	if ((S_ISLNK(st.st_mode)) == TRUE)
	{
		ft_putstr(path);
		ft_putstr(" -> ");
		ft_putendl(lnk_name);
	}
	else
		ft_putendl(path);
}

static void	print_name(char *name, char *lnk_name, t_stat st)
{
	if ((S_ISLNK(st.st_mode)) == TRUE)
	{
		ft_putstr(name);
		ft_putstr(" -> ");
		ft_putendl(lnk_name);
	}
	else
		ft_putendl(name);
}

void		print_end_part(t_env *e, t_stat st, t_bool is_dir)
{
	char	*lnk_name;

	if ((S_ISLNK(st.st_mode)) == TRUE)
		if ((lnk_name = ft_readlink(e->file->path, st.st_size)) == NULL)
			return ;
	if (is_dir == 1)
		print_name(e->file->name, lnk_name, st);
	else
		print_path(e->file->path, lnk_name, st);
	if ((S_ISLNK(st.st_mode)) == TRUE)
		ft_strdel(&lnk_name);
	if (((S_ISDIR(st.st_mode)) && e->flg->rec == TRUE) && e->flg->d == FALSE)
	{
		if ((ft_strcmp(".", e->file->name)) != 0 &&
			(ft_strcmp("..", e->file->name)) != 0)
		{
			dir_addback(&e->dir->rec, e->file->path);
		}
	}
}
