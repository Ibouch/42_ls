#include <ft_ls.h>

t_list * ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_node;

	if ((new_node = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if (content == NULL)
	{
		new_node->content = NULL;
		new_node->content_size = 0;
	}
	else
	{
		if ((new_node->content = malloc(content_size)) == NULL)
			return (NULL);
		new_node->content = content;
		new_node->content_size = content_size;
	}
	new_node->next = NULL;
	return (new_node);
}
