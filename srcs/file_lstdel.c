/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_lstdel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 22:02:24 by ibouchla          #+#    #+#             */
/*   Updated: 2016/03/13 22:02:28 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	file_lstdel(t_file **alst)
{
	t_file	*begin;
	t_file	*to_free;

	begin = *alst;
	if (begin != NULL)
	{
		while (begin != NULL)
		{
			ft_strdel(&(begin->name));
			ft_strdel(&(begin->path));
			to_free = begin;
			begin = begin->next;
			free(to_free);
		}
		*alst = NULL;
	}
}
