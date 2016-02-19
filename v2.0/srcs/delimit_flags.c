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
static DIR		*ft_myopendir(const char *path, t_env *e)
{
	DIR	*directory;

	if ((directory = opendir(path)) == NULL)
	{
		ft_putstr("ft_ls: ");
		perror(path);
		return (NULL);
	}
	if (e->flg->all == TRUE)
		return (directory);
	while ((e->e_dir = readdir(directory)) != NULL)
		if (e->e_dir->d_name[0] != '.')
			return (directory);
	return (NULL);
	 si e_dir != 0 il contient alors les infos du premier directory
}

int		ft_search_recursive()
{

}
*/

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

void	delimit_flags(t_env *e, t_file *file)
{
	if (e->flg->aff == 'l')
		print_total(file);
	if (e->flg->i == TRUE)
	{
		ft_putnbr_long(file->inoeud);
		ft_putchar(' ');
	}
	if (e->flg->aff == 'l')
	{
		listing_flag(file);
	}
}