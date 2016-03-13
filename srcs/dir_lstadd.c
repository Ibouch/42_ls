/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_lstadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 22:04:21 by ibouchla          #+#    #+#             */
/*   Updated: 2016/03/13 22:04:24 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static void		sort_lexico(t_dir **alst, t_dir *new, int rev)
{
	t_dir	*begin;
	t_dir	*tmp;

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

static void		sort_time(t_dir **alst, t_dir *new)
{
	t_dir	*begin;
	t_dir	*tmp;

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

void			dir_lstadd(t_dir **alst, t_flag *flg, char *dir_path)
{
	t_dir	*new;

	if (flg->f == TRUE)
		dir_addback(alst, dir_path);
	else
	{
		if ((new = new_dirstat(dir_path)) == NULL)
			return ;
		if (flg->t == TRUE)
			sort_time(alst, new);
		else
			sort_lexico(alst, new, ((flg->rev == TRUE) ? (-1) : 1));
	}
}
