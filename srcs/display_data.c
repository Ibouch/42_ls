
#include <ft_ls.h>

void	display_data(t_file *lst, char *path)
{
	blkcnt_t	nb;

	nb = 0;
	while (lst != NULL)
	{
		nb += (*lst).blocks;
		lst = lst->next;
	}
	ft_putstr(path);
	ft_putendl(":");
	ft_putstr("total ");
	ft_putnbr_endl(nb);
}
