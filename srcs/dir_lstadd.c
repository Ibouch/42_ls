#include <ft_ls.h>

static void		sort_lexico(t_dir **alst, t_dir *new)
{
	t_dir	*begin;
	t_dir	*tmp;

	begin = *alst;
	tmp = NULL;
	while ((begin != NULL) && ((ft_strcmp(new->path, begin->path)) > 0))
	{
		tmp = begin;
		begin = begin->next;
	}
	new->next = begin;
	if (tmp != NULL)
		tmp->next = new;
	else
		*alst = new;
}

static void		sort_time(t_dir **alst, t_dir *new)
{
	t_dir	*begin;
	t_dir	*tmp;

	begin = *alst;
	tmp = NULL;
	while ((begin != NULL) && ((new->s_spec.tv_sec < begin->s_spec.tv_sec) ||
		(((ft_strcmp(new->path, begin->path)) > 0) &&
		(new->s_spec.tv_sec == begin->s_spec.tv_sec))))
	{
		tmp = begin;
		begin = begin->next;
	}
	while ((begin != NULL) && (((new->s_spec.tv_sec == begin->s_spec.tv_sec) &&
		(new->s_spec.tv_nsec < begin->s_spec.tv_nsec)) ||
		(((ft_strcmp(new->path, begin->path)) > 0) &&
		(new->s_spec.tv_sec == begin->s_spec.tv_sec))))
	{
		tmp = begin;
		begin = begin->next;
	}
	new->next = begin;
	if (tmp != NULL)
		tmp->next = new;
	else
		*alst = new;
}

static t_dir	*new_dir(char *dir_path)
{
	t_dir			*new_node;
	t_stat			st;

	if ((new_node = (t_dir *)ft_memalloc(sizeof(t_dir))) == NULL)
		return (NULL);
	if ((lstat(dir_path, &st)) != 0)
		exit(EXIT_FAILURE);
	(*new_node).path = ft_strdup(dir_path);
	(*new_node).s_spec = st.st_mtimespec;
	(*new_node).next = NULL;
	return (new_node);
}

void			dir_lstadd(t_env *e, char *dir_path)
{
	t_dir	*new;

	new = new_dir(dir_path);
	if (e->flg->t == TRUE)
		sort_time(&(*e).dir, new);
	else
		sort_lexico(&(*e).dir, new);
	if (e->flg->rev == TRUE)
		;//reverse_list(&(*e).dir);
}
