/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myopendir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 04:30:08 by ibouchla          #+#    #+#             */
/*   Updated: 2016/02/24 04:30:12 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static char	*storage_path(char *path, char *name)
{
	size_t	end;
	char	*path_file;

	end = (ft_strlen(path) - 1);
	if (path[end] == '/')
		path_file = ft_strjoin(path, name);
	else
	{
		path_file = ft_strjoin(path, "/");
		path_file = ft_strjoin(path_file, name);
	}
	return (path_file);
}

int	myopendir(char *path, t_env *e)
{
	DIR				*directory;
	struct dirent	*e_dir;
	char			*er;

	if ((directory = opendir(path)) == NULL)
	{
		er = ft_strjoin("ft_ls: ", path);
		er = ft_strjoin(er, ": ");
		ft_putendl(ft_strjoin(er, strerror(errno)));
		return (-1);
	}
	if ((*e).flg->all == TRUE)
		while ((e_dir = readdir(directory)) != NULL)
			file_lstadd(e, storage_path(path, e_dir->d_name));
	else
		while ((e_dir = readdir(directory)) != NULL)
			if (e_dir->d_name[0] != '.')
				file_lstadd(e, storage_path(path, e_dir->d_name));
	if ((closedir(directory)) == (-1))
		exit(EXIT_FAILURE);
	return (0);
}
