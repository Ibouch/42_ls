
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

static void	convert_id(t_stat st, t_bool g_opt)
{
	struct passwd	*uid;
	struct group	*gid;

	if (g_opt == FALSE)
	{
		if ((uid = getpwuid(st.st_uid)) == NULL)
			ft_putnbr(st.st_uid);
		else
			ft_putstr(uid->pw_name);
		ft_putchar(' '); /* space */
	}
	if ((gid = getgrgid(st.st_gid)) == NULL)
		ft_putnbr(st.st_gid);
	else
		ft_putstr(gid->gr_name);
	uid = NULL;
	gid = NULL;
}

void		print_mid_part(t_stat st, t_bool g_opt)
{
	convert_id(st, g_opt);
	ft_putchar(' '); /* space */
	if ((S_ISBLK(st.st_mode)) == TRUE || (S_ISCHR(st.st_mode)) == TRUE)
	{
		ft_putnbr(major(st.st_rdev));
		ft_putchar(',');
		ft_putchar(' '); /* space */
		ft_putnbr(minor(st.st_rdev));
	}
	else
		ft_putnbr(st.st_size);
	ft_putchar(' ');
	print_date(st.st_mtimespec.tv_sec);
	ft_putchar(' ');
}
