/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_end_part.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 22:06:01 by ibouchla          #+#    #+#             */
/*   Updated: 2016/03/22 01:14:35 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static void	print_path(char *path, char *lnk_name, t_stat *st, int opt)
{
	if ((S_ISLNK(st->st_mode)) == TRUE)
	{
		print_color(path, st->st_mode, FALSE, opt);
		ft_putstr(" -> ");
		ft_putendl(lnk_name);
	}
	else
		print_color(path, st->st_mode, TRUE, opt);
}

static void	print_name(char *name, char *lnk_name, t_stat *st, int opt)
{
	if ((S_ISLNK(st->st_mode)) == TRUE)
	{
		print_color(name, st->st_mode, FALSE, opt);
		ft_putstr(" -> ");
		ft_putendl(lnk_name);
	}
	else
		print_color(name, st->st_mode, TRUE, opt);
}

void		print_end_part(t_env *e, t_stat *st, t_bool is_dir)
{
	off_t	to_rd;
	char	*lnk_name;

	if ((S_ISLNK(st->st_mode)) == TRUE)
	{
		to_rd = ((st->st_size == 0) ? 1024 : st->st_size);
		if ((lnk_name = ft_readlink(e->file->path, to_rd)) == NULL)
			return ;
	}
	if (is_dir == 1)
		print_name(e->file->name, lnk_name, st, e->flg->col);
	else
		print_path(e->file->path, lnk_name, st, e->flg->col);
	if ((S_ISLNK(st->st_mode)) == TRUE)
		ft_strdel(&lnk_name);
	if (((S_ISDIR(st->st_mode)) && e->flg->rec == TRUE) && e->flg->d == FALSE)
	{
		if ((ft_strcmp(".", e->file->name)) != 0 &&
			(ft_strcmp("..", e->file->name)) != 0)
		{
			dir_addback(&e->dir->rec, e->file->path);
		}
	}
}
