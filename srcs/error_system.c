
#include <ft_ls.h>

void	error_system(void)
{
	ft_putendl_fd("ft_ls: A memory allocation error has occurred.", 2);
	exit(EXIT_FAILURE);
}
