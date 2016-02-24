#include <ft_ls.h>

void 	path_lstadd(t_dir **alst, char *path, char *name)
{
	t_dir	*new;

	new = path_lstnew(path, "NULL", 0);
	new->next = *alst;
	*alst  = new;
}
