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

DIR		*ft_myopendir(const char *path)
{
	if ((e->dir = opendir(path)) == NULL)
	{
		ft_putstr("ft_ls: ");
		perror(av[e->x]);
		return ;
	}
	while ((elem_dir = readdir(e->dir)))
		ft_putendl(elem_dir->d_name);
	if ((closedir(e->dir)) == (-1))
		exit(-1);
	if (e->flg->all == FALSE)
}

void	ft_delimit_flags(t_env *e)
{
	ft_listing_flag(e);
}
