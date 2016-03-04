
#include <ft_ls.h>

void	display_data(t_file *lst, char *path, char aff)
{
	blkcnt_t	nb;

	nb = 0;
	ft_putstr(path);
	ft_putendl(":");
	if (aff == 'l')
	{
		while (lst != NULL)
		{
			nb += (*lst).blocks;
			lst = lst->next;
		}
		ft_putstr("total ");
		ft_putnbr_endl(nb);
	}
}
