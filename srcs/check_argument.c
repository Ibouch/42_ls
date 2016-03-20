/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 22:01:35 by ibouchla          #+#    #+#             */
/*   Updated: 2016/03/13 22:01:43 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static void	storage_error(t_env *e, char *path)
{
	char	*er;
	char	*tmp;

	er = ft_strjoin("ft_ls: ", path);
	tmp = ft_strjoin(er, ": ");
	ft_strdel(&er);
	er = ft_strjoin(tmp, strerror(errno));
	ft_strdel(&tmp);
	if (er == NULL)
		ft_error_system();
	if (e->flg->f == TRUE)
		ft_lstadd_back(&(e->err), (char *)er, ft_strlen(er) + 1);
	else
		ft_lstadd(&(e->err), (char *)er, ft_strlen(er) + 1);
	e->global_err = TRUE;
}

static void	storage_link(t_env *e, char *path)
{
	DIR		*dir;

	if ((dir = opendir(path)) == NULL)
		file_lstadd(e, path, FALSE);
	else
	{
		if (e->flg->d == TRUE)
			file_lstadd(e, path, FALSE);
		else
			dir_lstadd(&e->dir, e->flg, path);
		if ((closedir(dir)) == (-1))
			exit(EXIT_FAILURE);
	}
}

void		check_argument(char *path, t_env *e, t_bool *end_opt)
{
	t_stat	st;

	*end_opt = TRUE;
	if ((lstat(path, &st)) == 0)
	{
		if ((S_ISLNK(st.st_mode)) == TRUE && e->flg->aff != 'l')
			storage_link(e, path);
		else if (S_ISDIR(st.st_mode))
		{
			if (e->flg->d == TRUE)
				file_lstadd(e, path, FALSE);
			else
				dir_lstadd(&e->dir, e->flg, path);
		}
		else
			file_lstadd(e, path, FALSE);
	}
	else
		storage_error(e, path);
}
