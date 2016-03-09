/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_fstat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 04:30:38 by ibouchla          #+#    #+#             */
/*   Updated: 2016/02/24 04:30:42 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static char	*storage_name(char *path_name)
{
	char	*name;

	name = ft_strrchr(path_name, '/');
	if (name != NULL && ++name != NULL)
		return (ft_strdup(name));
	return (ft_strdup(path_name));
}

t_file		*new_fstat(char *path_name, int dir)
{
	t_file			*new_node;
	t_stat			st;

	if ((new_node = (t_file *)ft_memalloc(sizeof(t_file))) == NULL)
 		error_system();
	if ((lstat(path_name, &st)) != 0)
	{
		ft_putstr_fd("ft_ls: ", 2);
		perror(storage_name(path_name));
		free(new_node);
		return (NULL);
	}
	if ((new_node->name = storage_name(path_name)) == NULL)
		error_system();
	if ((new_node->path = ft_strdup(path_name)) == NULL)
		error_system();
	if (dir == TRUE)
		ft_strdel(&path_name);
	new_node->blocks = st.st_blocks;
	new_node->is_dir = S_ISDIR(st.st_mode);
	new_node->next = NULL;
	return (new_node);
}
