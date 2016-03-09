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
	if (path_file == NULL)
		error_system();
	return (path_file);
}

static void	determine_name(char *path_name)
{
	char	*name;

	name = ft_strrchr(path_name, '/');
	if (name != NULL && ++name != NULL)
		ft_putstr(name);
	else
		ft_putstr(path_name);
}

static void	print_error(char *path, t_env *e)
{
	if (e->display_data == TRUE)
	{
		ft_putstr(path);
		ft_putendl(":");
	}
	ft_putstr_fd("ft_ls: ", 2);
	determine_name(path);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(strerror(errno), 2);
	if (e->dir->next != NULL)
		ft_putchar('\n');
}

int			myopendir(char *path, t_env *e)
{
	DIR				*directory;
	struct dirent	*e_dir;

	if ((directory = opendir(path)) == NULL)
	{
		print_error(path, e);
		return (-1);
	}
	if ((*e).flg->all == TRUE)
		while ((e_dir = readdir(directory)) != NULL)
			file_lstadd(e, storage_path(path, e_dir->d_name), TRUE);
	else
		while ((e_dir = readdir(directory)) != NULL)
			if (e_dir->d_name[0] != '.')
				file_lstadd(e, storage_path(path, e_dir->d_name), TRUE);
	if ((closedir(directory)) == (-1))
		exit(EXIT_FAILURE);
	return (0);
}
