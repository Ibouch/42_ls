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
}

static void	storage_argument(t_env *e, char *path, t_stat *st)
{
	if (e->flg->d == TRUE)
	{
		path = ((S_ISLNK(st->st_mode)) ? ft_strjoin(path, "/") : path);
		file_lstadd(e, path, FALSE);
	}
	else
	{
		path = ((S_ISLNK(st->st_mode)) ? ft_strjoin(path, "/") : path);
		dir_lstadd(&e->dir, e->flg, path);
	}
	if ((S_ISLNK(st->st_mode)) == TRUE && path != NULL)
		ft_strdel(&path);
}

void		check_argument(char *path, t_env *e, t_bool *end_opt)
{
	t_stat	st;

	*end_opt = TRUE;
	if ((lstat(path, &st)) == 0)
	{
		if ((S_ISDIR(st.st_mode)) || ((S_ISLNK(st.st_mode)) == TRUE &&
			e->flg->aff != 'l'))
			storage_argument(e, path, &st);
		else
			file_lstadd(e, path, FALSE);
	}
	else
		storage_error(e, path);
}
