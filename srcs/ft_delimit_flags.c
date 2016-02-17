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

DIR		*ft_myopendir(const char *path, t_env *e)
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
		if (e_dir->d_name[0] != '.')
			return (directory);
	return (NULL);
}
/*
int		ft_search_recursive()
{

}
*/

int		ft_listing_flag(e)
{
	
}

void	ft_delimit_flags(t_env *e)
{
	ft_listing_flag(e);
}
