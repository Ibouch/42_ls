#include <ft_ls.h>

void 	dir_lstadd(t_dir **alst, char *path, char *name)
{
	t_dir	*new;

	new = dir_lstnew(path, "NULL", 0);
	new->next = *alst;
	*alst  = new;
}
