/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_data_endl.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 22:05:49 by ibouchla          #+#    #+#             */
/*   Updated: 2016/03/13 22:05:52 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	print_data_endl(t_env *e, t_bool dir)
{
	while (e->file != NULL)
	{
		if (e->flg->i == TRUE)
		{
			ft_putnbr(e->file->st.st_ino);
			ft_putchar(' ');
		}
		if (dir == TRUE)
			ft_putendl(e->file->name);
		else
			ft_putendl(e->file->path);
		if (((S_ISDIR(e->file->st.st_mode)) && e->flg->rec == TRUE) &&
			e->flg->d == FALSE)
			if ((ft_strcmp(".", e->file->name)) != 0 &&
				(ft_strcmp("..", e->file->name)) != 0)
				dir_addback(&e->dir->rec, e->file->path);
		e->file = e->file->next;
	}
}
