
#include <ft_ls.h>

void	print_data(t_env *e, t_bool dir)
{
	t_stat	st;

	if (e->flg->aff == 'l')
	{
		if (dir == TRUE)
			display_total(e->file);
		while (e->file != NULL)
		{
			if ((lstat(e->file->path, &st)) != 0)
			{
				ft_putstr_fd("ft_ls: ", 2);
				perror(e->file->path);
			}
			else
			{
				print_first_part(st, e->flg->i);
				print_mid_part(st);
				print_end_part(e, dir);
			}
			e->file = e->file->next;
		}
	}
	else
		print_data_endl(e, dir);
}
