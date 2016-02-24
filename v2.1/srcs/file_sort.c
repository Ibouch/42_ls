
#include <ft_ls.h>

void	file_sort(t_file **alst, char *field, int (*f_cmp)())
{
	t_file	*begin_list;
	t_file	*tmp;
	char	*swap;

	begin_list = *alst;
	while (*alst != NULL)
	{
		tmp = begin_list;
		while (tmp->next != NULL)
		{
			if ((ft_strcmp(field, "-t")) == 0)
				if ((f_cmp(tmp->mtime, tmp->next->mtime)) > 0)
				{
					swap = tmp->mtime;
					tmp->mtime = tmp->next->mtime;
					tmp->next->mtime = swap;
				}
			tmp = tmp->next;
		}
		*alst = (*alst)->next;
	}
	*alst = begin_list;
}
