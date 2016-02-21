
#include <ft_ls.h>

void	file_lstadd(t_file **alst, char *path, t_stat *st)
{
	t_file	*new;

	new = new_fstat(path, st);
	if (*alst != NULL)
	{
		new->next = *alst;
		*alst = new;
	}
	else
		*alst = new;
}
