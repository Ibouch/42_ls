/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mid_part.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 22:06:39 by ibouchla          #+#    #+#             */
/*   Updated: 2016/03/13 22:06:42 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static void	print_date(time_t mtime)
{
	char	*tmp;
	char	*date;

	if ((mtime - time(NULL)) > 0 || (mtime - time(NULL)) < SIX_MONTH)
	{
		if ((tmp = ft_strsub(ctime(&mtime), 4, 20)) == NULL)
			ft_error_system();
		if ((date = ft_strsub(tmp, 0, 7)) == NULL)
			ft_error_system();
		if ((date = ft_strjoin(date, ft_strsub(tmp, 15, 5))) == NULL)
			ft_error_system();
		ft_strdel(&tmp);
		date[12] = '\0';
	}
	else if ((date = ft_strsub(ctime(&mtime), 4, 12)) == NULL)
		ft_error_system();
	ft_putstr(date);
	ft_strdel(&date);
}

static void	get_value_gid(t_max_l *len, t_stat st)
{
	struct group	*gid;
	size_t			l_gid;

	if ((gid = getgrgid(st.st_gid)) == NULL)
	{
		ft_putnbr(st.st_gid);
		l_gid = ft_nbrlen(st.st_gid);
	}
	else
	{
		ft_putstr(gid->gr_name);
		l_gid = ft_strlen(gid->gr_name);
	}
	print_sp(l_gid, len->gid, FALSE);
	gid = NULL;
}

static void	convert_id(t_max_l *len, t_stat st, t_bool g_opt)
{
	struct passwd	*uid;
	size_t			l_uid;

	if (g_opt == FALSE)
	{
		if ((uid = getpwuid(st.st_uid)) == NULL)
		{
			ft_putnbr(st.st_uid);
			l_uid = ft_nbrlen(st.st_uid);
		}
		else
		{
			ft_putstr(uid->pw_name);
			l_uid = ft_strlen(uid->pw_name);
		}
		print_sp(l_uid, len->uid, TRUE);
	}
	get_value_gid(len, st);
	uid = NULL;
}

void		print_mid_part(t_max_l *len, t_stat st, t_bool g_opt)
{
	convert_id(len, st, g_opt);
	if ((S_ISBLK(st.st_mode)) == TRUE || (S_ISCHR(st.st_mode)) == TRUE)
	{
		print_sp(ft_nbrlen(major(st.st_rdev)), len->major, TRUE);
		ft_putnbr(major(st.st_rdev));
		ft_putchar(',');
		print_sp(ft_nbrlen(minor(st.st_rdev)), len->minor, TRUE);
		ft_putnbr(minor(st.st_rdev));
	}
	else
	{
		print_sp(ft_nbrlen(st.st_size), len->f_size, TRUE);
		ft_putnbr(st.st_size);
	}
	ft_putchar(' ');
	print_date(st.st_mtimespec.tv_sec);
	ft_putchar(' ');
}
