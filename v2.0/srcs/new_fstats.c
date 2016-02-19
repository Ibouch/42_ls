
#include <ft_ls.h>

t_file	*new_fstats(char *name, t_stat *st)
{
	t_file	*new_node;

	if ((new_node = (t_file *)malloc(sizeof(t_file))) == NULL)
		return (NULL);
	new_node->inoeud = st->st_ino;
	new_node->rights = st->st_mode;
	new_node->n_lnk = st->st_nlink;
	new_node->uid = st->st_uid;
	new_node->gid = st->st_gid;
	new_node->f_size = st->st_size;
	new_node->blocks = st->st_blocks;
	new_node->name = name;
	new_node->next = NULL;
	return (new_node);
}