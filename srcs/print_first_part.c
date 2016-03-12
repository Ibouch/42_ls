
#include <ft_ls.h>

/*
	We need to remove all space comment by appropriate
	length of space.
*/

void		print_first_part(t_env *e, t_bool inoeud_opt)
{
	if (inoeud_opt == TRUE)
	{
		print_sp(ft_nbrlen(e->file->st.st_ino), e->len->ino, FALSE);
		ft_putnbr(e->file->st.st_ino);
		ft_putchar(' ');
	}
	convert_rights(&(e->file->st));
	print_sp(ft_nbrlen(e->file->st.st_nlink), e->len->n_lnk, TRUE);
	ft_putnbr(e->file->st.st_nlink);
	ft_putchar(' ');
}
