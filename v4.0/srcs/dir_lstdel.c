/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_lstdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 22:02:03 by ibouchla          #+#    #+#             */
/*   Updated: 2016/03/13 22:02:09 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	dir_lstdel(t_dir **alst)
{
	t_dir	*begin;

	begin = *alst;
	if (begin != NULL)
	{
		ft_strdel(&(begin->path));
		ft_memdel((void **)alst);
	}
}
