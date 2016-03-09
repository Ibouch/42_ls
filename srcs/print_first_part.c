
#include <ft_ls.h>

/*
	We need to remove all space comment by appropriate
	length of space.
*/

int			print_first_part(t_stat st, t_bool inoeud_opt)
{
	struct passwd	*uid;
	struct group	*gid;

	if ((uid = getpwuid(st.st_uid)) == NULL)
		return (-1);
	if ((gid = getgrgid(st.st_gid)) == NULL)
		return (-1);
	if (inoeud_opt == TRUE)
	{
		ft_putnbr(st.st_ino);
		ft_putchar(' '); /* space */
	}
	convert_rights(&st);
	ft_putchar(' '); /* space */
	ft_putnbr(st.st_nlink);
	ft_putchar(' ');
	ft_putstr(uid->pw_name);
	ft_putchar(' '); /* space */
	ft_putstr(gid->gr_name);
	ft_putchar(' '); /* space */
	return (0);
}
