

#include <ft_ls.h>

void 	mystat(char *path, t_env *e)
{
	t_stat	*st;
	char	*er;

	st = (t_stat *)ft_memalloc(sizeof(t_stat));
	if ((lstat(path, st)) == 0)
	{
		if ((S_ISDIR(st->st_mode)) || (e->flg->rec == TRUE && (S_ISDIR(st->st_mode))))
			myopendir(path, e);
		else
			file_lstadd(&e->file, path); // On add au debut tout != DIR
	}
	else
	{
		er = ft_strjoin("ft_ls: ", path);
		er = ft_strjoin(er, ": ");
		er = ft_strjoin(er, strerror(errno));
		ft_lstadd(&e->err, (char *)er, ft_strlen(er) + 1);
	}
}
