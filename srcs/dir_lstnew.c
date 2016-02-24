#include <ft_ls.h>

t_dir	*dir_lstnew(char *path, char *name, int dir)
{
	t_dir	*new_node;

	if ((new_node = (t_dir *)malloc(sizeof(t_dir))) == NULL)
		return (NULL);
	(*new_node).l = new_fstat(path, name, dir);
	new_node->next = NULL;
}
