
#include <ft_ls.h>

void	myopendir(char *path, t_env *e)
{
	DIR		*directory;
	t_dir	*e_dir;
	t_stat	st;

	if ((directory = opendir(path)) == NULL)
	{
		ft_putstr("ft_ls: ");
		perror(path);
		return ;
	}
	if (e->flg->all == TRUE)
	{
		while ((e_dir = readdir(directory)) != NULL)
			file_addback(&e->file , e_dir->d_name, &st);
	}
	else
		while ((e_dir = readdir(directory)) != NULL)
			if (e_dir->d_name[0] != '.')
				file_addback(&e->file , e_dir->d_name, &st);
}
