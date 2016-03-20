/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_lstadd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 22:04:51 by ibouchla          #+#    #+#             */
/*   Updated: 2016/03/13 22:04:54 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static void		sort_lexico(t_file **alst, t_file *new, int rev)
{
	t_file	*begin;
	t_file	*tmp;

	begin = *alst;
	tmp = NULL;
	while ((begin != NULL) && (((ft_strcmp(new->path, begin->path)) * rev) > 0))
	{
		tmp = begin;
		begin = begin->next;
	}
	new->next = begin;
	if (tmp != NULL)
		tmp->next = new;
	else
		*alst = new;
}

static int		sort_nano_sec(t_file *new, t_file *begin, int rev)
{
	return ((new->st.st_mtimespec.tv_sec == begin->st.st_mtimespec.tv_sec
		&& ((new->st.st_mtimespec.tv_nsec * rev)
		< (begin->st.st_mtimespec.tv_nsec * rev)
		|| (new->st.st_mtimespec.tv_nsec == begin->st.st_mtimespec.tv_nsec
		&& (ft_strcmp(new->path, begin->path)) > 0))) ? 1 : 0);
}

static int		sort_bysec(t_file *new, t_file *begin, int rev)
{
	return (((new->st.st_mtimespec.tv_sec * rev)
		< (begin->st.st_mtimespec.tv_sec * rev)
		|| (new->st.st_mtimespec.tv_sec == begin->st.st_mtimespec.tv_sec &&
		(ft_strcmp(new->path, begin->path) > 0))) ? 1 : 0);
}

static void		sort_time(t_file **alst, t_file *new, int rev)
{
	t_file	*begin;
	t_file	*tmp;

	begin = *alst;
	tmp = NULL;
	while ((begin != NULL) && (sort_bysec(new, begin, rev)) == TRUE)
	{
		tmp = begin;
		begin = begin->next;
	}
	while ((begin != NULL) && (sort_nano_sec(new, begin, rev)) == TRUE)
	{
		tmp = begin;
		begin = begin->next;
	}
	new->next = begin;
	if (tmp != NULL)
		tmp->next = new;
	else
		*alst = new;
}

void			file_lstadd(t_env *e, char *path_name, int dir)
{
	t_file	*new;

	if ((new = new_fstat(e->len, path_name, e->flg, dir)) == NULL)
		return ;
	if (e->flg->f == TRUE)
		file_addback(&(e->file), new);
	else
	{
		if (e->flg->t == TRUE)
			sort_time(&(e->file), new, ((e->flg->rev == TRUE) ? (-1) : 1));
		else
			sort_lexico(&(e->file), new, ((e->flg->rev == TRUE) ? (-1) : 1));
	}
}
