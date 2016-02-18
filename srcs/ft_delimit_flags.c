/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delimit_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 05:46:53 by ibouchla          #+#    #+#             */
/*   Updated: 2016/02/16 05:47:16 by ibouchla         ###   ########.fr       */
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


int		ft_listing_flag(t_env *e)
{
	t_stat	st;

	stat(e->file->content, &st);
if (!e)
	;
	printf("%o\n", S_IFMT);
	ft_print_modes(e);
	ft_print_guid(e);
	ft_print_uid(e);
	ft_print_date(e);

	return 0;
}

*/

void	ft_delimit_flags(t_env *e)
{
	if (e->flg->aff == 'l')
	{
		ft_lst_sort(e->file);
		ft_listing_flag(e);
	}
}
