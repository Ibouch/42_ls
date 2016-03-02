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

static void	convert_id(t_file *new_node, t_stat *st)
{
	struct passwd	*uid;
	struct group	*gid;

	uid = getpwuid((*st).st_uid);
	gid = getgrgid((*st).st_gid);
	(*new_node).num_uid = (*st).st_uid;
	(*new_node).num_gid = (*st).st_gid;
	(*new_node).uid = ft_strdup((*uid).pw_name);
	(*new_node).gid = ft_strdup((*gid).gr_name);
}

static char	*storage_name(char *path_name)
{
	char	*name;

	name = ft_strrchr(path_name, '/');
	if (name != NULL && ++name != NULL)
		return (ft_strdup(name));
	return (ft_strdup(path_name));
}

t_file		*new_fstat(char *path_name)
{
	t_file			*new_node;
	t_stat			st;

	if ((new_node = (t_file *)malloc(sizeof(t_file))) == NULL)
 		return (NULL);
	if ((lstat(path_name, &st)) != 0)
		exit(EXIT_FAILURE);
	convert_rights(new_node, &st);
	convert_id(new_node, &st);
	(*new_node).inoeud = st.st_ino;
	(*new_node).n_lnk = ft_itoa(st.st_nlink);
	(*new_node).f_size = ft_itoa(st.st_size);
	(*new_node).blocks = st.st_blocks;
	(*new_node).mtime = st.st_mtime;
	(*new_node).s_spec = st.st_mtimespec;
	(*new_node).name = storage_name(path_name);
	(*new_node).path = ft_strdup(path_name);
	(*new_node).next = NULL;
	return (new_node);
}
