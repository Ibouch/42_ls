/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_lstadd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 04:31:17 by ibouchla          #+#    #+#             */
/*   Updated: 2016/02/24 04:31:20 by ibouchla         ###   ########.fr       */
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

static void		sort_time(t_file **alst, t_file *new)
{
	t_file	*begin;
	t_file	*tmp;

	begin = *alst;
	tmp = NULL;
	while ((begin != NULL) && (new->s_spec.tv_sec < begin->s_spec.tv_sec))
	{
		tmp = begin;
		begin = begin->next;
	}
	while ((begin != NULL) && ((new->s_spec.tv_sec == begin->s_spec.tv_sec) &&
		(new->s_spec.tv_nsec <= begin->s_spec.tv_nsec)))
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

	if ((new = new_fstat(path_name, dir)) == NULL)
		return ;
	if (e->flg->f == TRUE)
		file_addback(&(e->file), new);
	else
	{
		if (e->flg->t == TRUE)
			sort_time(&(e->file), new);
		else
			sort_lexico(&(e->file), new, ((e->flg->rev == TRUE) ? (-1) : 1));
	}
}
