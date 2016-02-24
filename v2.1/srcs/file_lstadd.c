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

void	file_lstadd(t_file **alst, char *path_file)
{
	t_file	*new;

	new = new_fstat(path_file, "NULL", 0);
	if (*alst != NULL)
	{
		new->next = *alst;
		*alst = new;
	}
	else
		*alst = new;
}
