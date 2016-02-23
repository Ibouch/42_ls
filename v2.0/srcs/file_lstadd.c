
#include <ft_ls.h>

void	file_lstadd(t_file **alst, char *path_file)
{
	t_file	*new;

	new = new_fstat(path_file, "NULL", 0);
	if (*alst != NULL)
	{
		new->next = *alst;
		*alst = new;
	}
	else
		*alst = new;
}
