

#include <ft_ls.h>

void 	mystat(char *path, t_env *e)
{
	t_stat	*st;
	char	*er;

	st = ft_memalloc(sizeof(t_stat));
	stat(path, st);
	if ((st->st_mode) > 0)
	{
		if ((S_ISDIR(st->st_mode)) || (e->flg->rec == TRUE && (S_ISDIR(st->st_mode))))
		{
			//ft_putendl("Je rentre condition myopendir == directory");
			myopendir(path, e);
		}
		else
		{
			//file_lstadd(&e->file , path, st); // On add au debut tout ce qui n'est pas un DIR
			ft_putendl("Je rentre condition myopendir == autre chose mais pas error");
		}
	}
	else
	{
		er = "ft_ls: ";
		er = ft_strjoin(er, path);
		er = ft_strjoin(er, ": ");
		er = ft_strjoin(er, strerror(errno));
		ft_lstadd((t_list **)&e->err, (char *)er, ft_strlen(er) + 1); // Et j'ai ici ma liste d'erreur
	}
	free(st);
}
