
#include <ft_ls.h>

static char	define_type(t_stat *st)
{
	char	type;

	type = '0';
	if (S_ISDIR((*st).st_mode))
		type = 'd';
	else if (S_ISREG((*st).st_mode))
		type = '-';
	else if (S_ISCHR((*st).st_mode))
		type = 'c';
	else if (S_ISBLK((*st).st_mode))
		type = 'b';
	else if (S_ISFIFO((*st).st_mode))
		type = 'p';
	else if (S_ISLNK((*st).st_mode))
		type = 'l';
	else if (S_ISSOCK((*st).st_mode))
		type = 's';
	return (type);
}

void		convert_rights(t_file *new_node, t_stat *st)
{
	char	*rights;

	rights = ft_strnew(10);
	rights[0] = define_type(st);
	rights[1] = (((*st).st_mode & S_IRUSR) ? 'r' : '-');
	rights[2] = (((*st).st_mode & S_IWUSR) ? 'w' : '-');
	rights[3] = (((*st).st_mode & S_IXUSR) ? 'x' : '-');
	rights[4] = (((*st).st_mode & S_IRGRP) ? 'r' : '-');
	rights[5] = (((*st).st_mode & S_IWGRP) ? 'w' : '-');
	rights[6] = (((*st).st_mode & S_IXGRP) ? 'x' : '-');
	rights[7] = (((*st).st_mode & S_IROTH) ? 'r' : '-');
	rights[8] = (((*st).st_mode & S_IWOTH) ? 'w' : '-');
	rights[9] = (((*st).st_mode & S_IXOTH) ? 'x' : '-');
	new_node->rights = rights;
}
