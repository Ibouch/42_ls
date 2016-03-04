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
	int	i;

	i = 0;
	if (e->file != NULL)
	{
		print_file_lst(e->file, e->flg, 0);
		file_lstdel(&(e->file));
		(*e).display_data = TRUE;
		if (e->arg != NULL)
			ft_putchar('\n');
	}
	while (e->arg != NULL)
	{
		if ((myopendir((char *)e->arg->content, e)) == 0)
		{
			if (((*e).display_data == TRUE || i > 0) || e->arg->next != NULL)
			{
				display_data(e->file, e->arg->content, 0);
				(*e).display_data = TRUE;
			}
			if (e->file != NULL)
				print_file_lst(e->file, e->flg, 1);
			if ((*e).display_data == TRUE && e->arg->next != NULL)
				ft_putchar('\n');
		}
		file_lstdel(&(e->file));
		e->arg = e->arg->next;
		++i;
	}
}
