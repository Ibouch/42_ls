/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delimit_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 00:52:11 by ibouchla          #+#    #+#             */
/*   Updated: 2016/02/19 00:52:18 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	delimit_flags(t_env *e)
{
	int		i;
	t_dir	*tmp;

	i = 0;
	if ((*e).file != NULL)
	{
		print_file_lst(e, FALSE);
		file_lstdel(&((*e).file));
		(*e).display_data = TRUE;
		if (e->dir != NULL)
			ft_putchar('\n');
	}
	while (e->dir != NULL)
	{
		if ((myopendir(e->dir->path, e)) == 0)
		{
			if (((*e).display_data == TRUE || i > 0) || e->dir->next != NULL)
			{
				display_data((*e).file, e->dir->path, 0);
				(*e).display_data = TRUE;
			}
			if ((*e).file != NULL)
				print_file_lst(e, TRUE);
			if ((*e).display_data == TRUE && e->dir->next != NULL)
				ft_putchar('\n');
		}
		tmp = e->dir->rec;
		if (tmp != NULL)
		{
			while (e->dir->rec->next != NULL)
				e->dir->rec = e->dir->rec->next;
			e->dir->rec->next = e->dir->next;
			e->dir->next = tmp;
		}
		e->dir = e->dir->next;
		file_lstdel(&((*e).file));
		++i;
	}
	dir_lstdel(&(e->dir));
}
