
#include <ft_ls.h>

t_dir	*new_dirstat(char *dir_path)
{
	t_dir			*new_node;
	t_stat			st;

	if ((new_node = (t_dir *)ft_memalloc(sizeof(t_dir))) == NULL)
		return (NULL);
	if ((lstat(dir_path, &st)) != 0)
		exit(EXIT_FAILURE);
	(*new_node).path = ft_strdup(dir_path);
	(*new_node).s_spec = st.st_mtimespec;
	(*new_node).rec = NULL;
	(*new_node).next = NULL;
	return (new_node);
}
