
#include <ft_ls.h>

void	dir_addback(t_dir **alst, char *dir_path)
{
	t_dir	*new;
	t_dir	*tmp;

	if ((new = (t_dir *)ft_memalloc(sizeof(t_dir))) == NULL)
		return ;
	(*new).path = ft_strdup(dir_path);
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
