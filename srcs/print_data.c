
#include <ft_ls.h>

void		print_data(t_env *e, t_bool dir)
{
	if (e->flg->aff == 'l')
	{
		if (dir == TRUE)
			display_total(e->file);
		while (e->file != NULL)
		{
			print_first_part(e, e->flg->i);
			print_mid_part(e->len, e->file->st, e->flg->g);
			print_end_part(e, e->file->st, dir);
			e->file = e->file->next;
		}
		ft_bzero(e->len, sizeof(struct s_max_l));
	}
	else
		print_data_endl(e, dir);
}
