

#include <ft_ls.h>

void	file_addback(t_file **alst, t_file *new)
{
	t_file	*tmp;

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
