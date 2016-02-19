
#include <ft_ls.h>

void	file_lstadd(t_file **alst, t_file *new)
{
	new->next = *alst;
	*alst = new;
}