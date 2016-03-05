#include <ft_ls.h>

static void	print_sp(size_t min, size_t max, int print)
{
	size_t	sp;

	sp = (max - min) + ((print == 1) ? 2 : 0);
	while (sp-- > 0)
		ft_putchar(' ');
}

static size_t	len_nlnk(t_file *file, size_t max_l)
{
	size_t		s_val;
	size_t		max;
	size_t		len;

	s_val = ft_strlen(file->n_lnk);
	max = ft_strlen(file->n_lnk);
	while (file != NULL)
	{
		len = ft_strlen(file->n_lnk);
		len = ((max_l > len) ? max_l : len);
		max = ((len >= max) ? len : max);
		file = file->next;
	}
	print_sp(s_val, max, 1);
	return (max);
}

static size_t	len_uid(t_file *file, size_t max_l)
{
	size_t		s_val;
	size_t		max;
	size_t		len;

	s_val = ft_strlen(file->uid);
	max = ft_strlen(file->uid);
	while (file != NULL)
	{
		len = ft_strlen(file->uid);
		len = ((max_l > len) ? max_l : len);
		max = ((len >= max) ? len : max);
		file = file->next;
	}
	print_sp(s_val, max, 1);
	return (max);
}

static size_t	len_gid(t_file *file, size_t max_l)
{
	size_t		s_val;
	size_t		max;
	size_t		len;

	s_val = ft_strlen(file->gid);
	max = ft_strlen(file->gid);
	while (file != NULL)
	{
		len = ft_strlen(file->gid);
		len = ((max_l > len) ? max_l : len);
		max = ((len >= max) ? len : max);
		file = file->next;
	}
	print_sp(s_val, max, 0);
	return (max);
}

static size_t	len_fsize(t_file *file, size_t max_l)
{
	size_t		s_val;
	size_t		max;
	size_t		len;

	s_val = ft_strlen(file->f_size);
	max = ft_strlen(file->f_size);
	while (file != NULL)
	{
		len = ft_strlen(file->f_size);
		len = ((max_l > len) ? max_l : len);
		max = ((len >= max) ? len : max);
		file = file->next;
	}
	print_sp(s_val, max, 1);
	return (max);
}

void 			print_date(time_t mtime)
{
	char	*tmp;
	char	*date;

	if ((mtime - time(NULL)) > 0 || (mtime - time(NULL)) < SIX_MONTH)
	{
		date = ft_strnew(12);
		tmp = ft_strsub(ctime(&mtime), 4, 20);
		ft_strncpy(date, tmp, 7);
		date = ft_strjoin(date, ft_strsub(tmp, 15, 5));
		date[12] = '\0';
	}
	else
		date = ft_strsub(ctime(&mtime), 4, 12);
	ft_putstr(date);
	ft_strdel(&date);
}

void			print_file_lst(t_env *e, t_bool dir)
{
	size_t	max_l[4];

	dir_lstdel(&e->dir->rec);
	if ((*e).flg->aff == 'l')
	{
		max_l[0] = ft_strlen((*e).file->n_lnk);
		max_l[1] = ft_strlen((*e).file->uid);
		max_l[2] = ft_strlen((*e).file->gid);
		max_l[3] = ft_strlen((*e).file->f_size);
		if (dir == 1)
			display_data(e->file, NULL, 'l');
		while (e->file != NULL)
		{
			if ((*e).flg->i == TRUE)
			{
				ft_putnbr((*e).file->inoeud);
				ft_putchar(' ');
			}
			ft_putstr((*e).file->rights);
			max_l[0] = len_nlnk(e->file, max_l[0]);
			ft_putstr((*e).file->n_lnk);
			ft_putchar(' ');
			ft_putstr((*e).file->uid);
			max_l[1] = len_uid(e->file, max_l[1]);
			ft_putstr((*e).file->gid);
			max_l[2] = len_gid(e->file, max_l[2]);
			max_l[3] = len_fsize(e->file, max_l[3]);
			ft_putstr((*e).file->f_size);
			ft_putchar(' ');
			print_date((*e).file->s_spec.tv_sec);
			ft_putchar(' ');
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
	else
		print_file_endl(e, dir);
}
