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
	char	*date;

	date = ft_strsub(ctime(&mtime), 4, 12);
	ft_putstr(date);
	ft_strdel(&date);
}

void			print_file_lst(t_file *lst, int dir)
{
	size_t	max_l[4];

	max_l[0] = ft_strlen(lst->n_lnk);
	max_l[1] = ft_strlen(lst->uid);
	max_l[2] = ft_strlen(lst->gid);
	max_l[3] = ft_strlen(lst->f_size);
	while (lst != NULL)
	{
		ft_putstr(lst->rights);
		max_l[0] = len_nlnk(lst, max_l[0]);
		ft_putstr(lst->n_lnk);
		ft_putchar(' ');
		ft_putstr(lst->uid);
		max_l[1] = len_uid(lst, max_l[1]);
		ft_putstr(lst->gid);
		max_l[2] = len_gid(lst, max_l[2]);
		max_l[3] = len_fsize(lst, max_l[3]);
		ft_putstr(lst->f_size);
		ft_putchar(' ');
		print_date(lst->s_spec.tv_sec);
		ft_putchar(' ');
		if (dir == 1)
			ft_putendl(lst->name);
		else
			ft_putendl(lst->path);
		lst = lst->next;
	}
}
