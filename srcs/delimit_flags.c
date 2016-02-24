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
	size_t	sp;

	while (lst != NULL)
	{
		ft_putstr(lst->rights);
		sp = 3 - ft_strlen(ft_itoa(lst->n_lnk));
		while (sp-- != 0)
			ft_putchar(' ');
		sp = 0;
		ft_putnbr_long(lst->n_lnk);
		ft_putchar(' ');
		ft_putstr(lst->uid);
		sp = 10 - ft_strlen(lst->uid);
		while (sp-- != 0)
			ft_putchar(' ');
		sp = 0;
		ft_putstr(lst->gid);
		sp = 11 - ft_strlen(ft_itoa(lst->f_size));
		while (sp-- != 0)
			ft_putchar(' ');
		ft_putchar(' ');
		ft_putnbr_long(lst->f_size);
		ft_putchar(' ');
		//ft_putstr(lst->mtime);
		//ft_putchar(' ');
		ft_putendl(lst->name);
		lst = lst->next;
	}
}

void	delimit_flags(t_env *e)
{
	/*
	if ((e->arg == NULL && e->err == NULL) && e->file == NULL)
		mystat(".", e);
	else
		while (e->arg != NULL)
		{
			mystat((char *)e->arg->content, e);
			print_file_lst(e->dir->l);
		}
	*/
	print_file_lst(e->file);
}
