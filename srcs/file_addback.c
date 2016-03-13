/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_addback.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 22:02:15 by ibouchla          #+#    #+#             */
/*   Updated: 2016/03/13 22:02:18 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	file_addback(t_file **alst, t_file *new)
{
	t_file	*tmp;

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
