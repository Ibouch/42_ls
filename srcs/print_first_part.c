
#include <ft_ls.h>

/*
	We need to remove all space comment by appropriate
	length of space.
*/

void	print_first_part(t_stat st, t_bool inoeud_opt)
{
	if (inoeud_opt == TRUE)
	{
		ft_putnbr(st.st_ino);
		ft_putchar(' '); /* space */
	}
	convert_rights(&st);
	ft_putchar(' '); /* space */
	ft_putnbr(st.st_nlink);
	ft_putchar(' ');
}
