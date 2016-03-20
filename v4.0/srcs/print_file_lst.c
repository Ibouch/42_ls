/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_file_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 22:03:38 by ibouchla          #+#    #+#             */
/*   Updated: 2016/03/13 22:03:41 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	print_file_lst(t_env *e)
{
	t_file	*f_free;

	if (e->file != NULL)
	{
		f_free = e->file;
		print_data(e, FALSE);
		file_lstdel(&(f_free));
		e->display_data = TRUE;
		if (e->dir != NULL)
			ft_putchar('\n');
	}
}
