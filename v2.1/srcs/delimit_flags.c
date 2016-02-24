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

void	print_file_lst(t_file *lst)
{
	while (lst)
	{
		ft_putnbr(lst->inoeud);
		ft_putstr(" ");
		ft_putstr(lst->rights);
		ft_putstr("   ");
		ft_putnbr_long(lst->n_lnk);
		ft_putstr(" ");
		ft_putstr(lst->uid);
		ft_putstr("   ");
		ft_putstr(lst->gid);
		ft_putstr("   ");
		ft_putendl(lst->name);
		lst = lst->next;
	}
}

void	delimit_flags(t_env *e)
{
	if (e->path == NULL && e->err == NULL)
		mystat(".", e);
	else
		while (e->path != NULL)
		{
			mystat(e->path->content, e);
			e->path = e->path->next;
		}
	print_file_lst(e->file);
}
