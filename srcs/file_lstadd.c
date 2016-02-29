/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_lstadd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 04:31:17 by ibouchla          #+#    #+#             */
/*   Updated: 2016/02/24 04:31:20 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	file_lstadd(t_file **alst, char *path_name)
{
	t_file	*new;
	t_file	*begin;
	t_file	*tmp;

	new = new_fstat(path_name);
	begin = *alst;
	tmp = NULL;
	while (begin != NULL && (ft_strcmp(new->name, begin->name)) > 0)
	{
		tmp = begin;
		begin = begin->next;
	}
	new->next = begin;
	if (tmp != NULL)
		tmp->next = new;
	else
		*alst = new;
}
