
#include <ft_ls.h>

void	dir_addback(t_dir **alst, char *dir_path)
{
	t_dir	*new;
	t_dir	*tmp;

	new = new_dirstat(dir_path);
	if (*alst != NULL)
	{
		tmp = *alst;
		while ((*alst)->next != NULL)
			*alst = (*alst)->next;
		(*alst)->next = new;
		*alst = tmp;
	}
	else
		*alst = new;
}
