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

static void	convert_time(t_file *new_node, t_stat *st)
{
	(*new_node).etime = ft_strdup(ctime(&((*st).st_ctime)));
	(*new_node).mtime = ft_strdup(ctime(&((*st).st_mtime)));
}

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

static void	storage_path(char *path, char *name, t_file *new, int dir)
{
	size_t	end;
	char	*path_file;

	if (dir == 1)
	{
		end = (ft_strlen(path) - 1);
		if (path[end] == '/')
			path_file = ft_strjoin(path, name);
		else
		{
			path_file = ft_strjoin(path, "/");
			path_file = ft_strjoin(path_file, name);
		}
		(*new).name = ft_strdup(name);
		(*new).path = ft_strdup(path_file);
	}
	else
	{
		(*new).name = ft_strdup(path);
		(*new).path = ft_strdup(path);
	}
}

t_file		*new_fstat(char *path, char *name, int dir)
{
	t_file			*new_node;
	t_stat			st;

	if ((new_node = (t_file *)malloc(sizeof(t_file))) == NULL)
 		return (NULL);
	storage_path(path, name, new_node, dir);
	if ((lstat((*new_node).path, &st)) != 0)
		exit(EXIT_FAILURE);
	convert_rights(new_node, &st);
	convert_id(new_node, &st);
	convert_time(new_node, &st);
	(*new_node).inoeud = st.st_ino;
	(*new_node).n_lnk = st.st_nlink;
	(*new_node).f_size = st.st_size;
	(*new_node).blocks = st.st_blocks;
	(*new_node).next = NULL;
	return (new_node);
}
