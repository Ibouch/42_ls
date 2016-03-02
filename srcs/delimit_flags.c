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
	if (e->file != NULL)
	{
		print_file_lst(e->file, 0);
		file_lstdel(&(e->file));
	}
	while (e->arg)
	{
		if ((myopendir((char *)e->arg->content, e)) == 0)
			print_file_lst(e->file, 1);
		file_lstdel(&(e->file));
		e->arg = e->arg->next;
	}
}
