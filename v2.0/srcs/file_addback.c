/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_addback.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 23:36:28 by ibouchla          #+#    #+#             */
/*   Updated: 2016/02/20 23:36:42 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	file_addback(t_file **alst, char *path, t_stat *st)
{
	t_file	*tmp;
	t_file	*new;

	new = new_fstat(path, st);
	if (*alst != NULL)
	{
		tmp = *alst;
		while ((*alst)->next != NULL)
			*alst = (*alst)->next;
		(*alst)->next = new;
		*alst = tmp;
	}
	else
		*alst = new;
}
