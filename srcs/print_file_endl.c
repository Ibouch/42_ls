#include <ft_ls.h>

void	print_file_endl(t_file *lst, t_flag *flg, int dir)
{
	while (lst != NULL)
	{
		if ((*flg).i == TRUE)
		{
			ft_putnbr((*lst).inoeud);
			ft_putchar(' ');
		}
		if (dir == 1)
			ft_putendl((*lst).name);
		else
			ft_putendl((*lst).path);
		lst = (*lst).next;
	}
}
