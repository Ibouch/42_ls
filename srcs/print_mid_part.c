
#include <ft_ls.h>

/*
	We need to remove all space comment by appropriate
	length of space.
*/

static void	print_date(time_t mtime)
{
	char	*tmp;
	char	*date;

	if ((mtime - time(NULL)) > 0 || (mtime - time(NULL)) < SIX_MONTH)
	{
		if ((tmp = ft_strsub(ctime(&mtime), 4, 20)) == NULL)
			error_system();
		if ((date = ft_strsub(tmp, 0, 7)) == NULL)
			error_system();
		if ((date = ft_strjoin(date, ft_strsub(tmp, 15, 5))) == NULL)
			error_system();
		ft_strdel(&tmp);
		date[12] = '\0';
	}
	else
		if ((date = ft_strsub(ctime(&mtime), 4, 12)) == NULL)
			error_system();
	ft_putstr(date);
	ft_strdel(&date);
}

void		print_mid_part(t_stat st)
{
	ft_putnbr(st.st_size);
	ft_putchar(' ');
	print_date(st.st_mtimespec.tv_sec);
	ft_putchar(' ');
}
