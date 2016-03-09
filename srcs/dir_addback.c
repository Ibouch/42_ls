
#include <ft_ls.h>

void	dir_addback(t_dir **alst, char *dir_path)
{
	t_dir	*new;
	t_dir	*tmp;

	if ((new = (t_dir *)ft_memalloc(sizeof(t_dir))) == NULL)
		error_system();
	if ((new->path = ft_strdup(dir_path)) == NULL)
		error_system();
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
