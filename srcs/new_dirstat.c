
#include <ft_ls.h>

t_dir	*new_dirstat(char *dir_path)
{
	t_dir			*new_node;
	t_stat			st;

	if ((new_node = (t_dir *)ft_memalloc(sizeof(t_dir))) == NULL)
		ft_error_system();
	if ((lstat(dir_path, &st)) != 0)
	{
		ft_putstr("ft_ls: ");
		perror(dir_path);
		free(new_node);
		return (NULL);
	}
	if ((new_node->path = ft_strdup(dir_path)) == NULL)
		ft_error_system();
	new_node->s_spec = st.st_mtimespec;
	new_node->rec = NULL;
	new_node->next = NULL;
	return (new_node);
}
