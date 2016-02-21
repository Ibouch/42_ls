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
/*
void	listing_flag(t_file *file)
{
	while (file != NULL)
	{
	//	print_rights(file->rights);
		ft_putnbr_long(file->n_lnk);
	//	print_uid(file->uid);
	//	print_gid(file->gid);
		ft_putnbr_long(file->f_size);
		ft_putendl(file->name);
		file = file->next;
	}
}

void	print_total(t_file *file)
{
	long long total;

	total = 0;
	while (file != NULL)
	{
		total += file->blocks;
		file = file->next;
	}
	ft_putstr("total ");
	ft_putendl(ft_itoa(total));
}
*/

void	delimit_flags(t_env *e)
{/*
	while (e->path != NULL)
	{
		mystat(e->path->name, e);
		e->path = e->path->next;
	}
*/
//	if (e->file == NULL)
		mystat(".", e);
//		fonction de trie reverse
		/*while (e->file)
		{
			ft_putendl(e->file->name);
			e->file = e->file->next;
		}*/
/*
	if (e->flg->aff == 'l')
		listing_flag(e);
*/
}
