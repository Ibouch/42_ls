#include <ft_ls.h>

void	print_sp(size_t min, max_len max, int print)
{
	max_len	sp;

	sp = (max - min) + ((print == 1) ? 2 : 0);
	while (sp-- > 0)
		write(1, " ", 1);
}
