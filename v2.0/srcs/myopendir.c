
#include <ft_ls.h>

void	myopendir(char *path, t_env *e)
{
	DIR				*directory;
	struct dirent	*e_dir;
	char			*er;

	if ((directory = opendir(path)) == NULL)
	{
		er = ft_strjoin("ft_ls: ", path);
		er = ft_strjoin(er, ": ");
		er = ft_strjoin(er, strerror(errno));
		ft_lstadd(&e->den, (char *)er, (ft_strlen(er) + 1));
		return ;
	}
	if (e->flg->all == TRUE)
		while ((e_dir = readdir(directory)) != NULL)
			file_addback(&e->file, path, e_dir->d_name);
	else
		while ((e_dir = readdir(directory)) != NULL)
			if (e_dir->d_name[0] != '.')
				file_addback(&e->file, path, e_dir->d_name);
	if ((closedir(directory)) == (-1))
		exit(EXIT_FAILURE);
}
