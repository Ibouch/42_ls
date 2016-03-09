
#include <ft_ls.h>

void	display_total(t_file *lst)
{
	blkcnt_t	nb;

	nb = 0;
	if (lst != NULL)
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
