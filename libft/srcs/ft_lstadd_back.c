/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 15:18:31 by ibouchla          #+#    #+#             */
/*   Updated: 2016/02/18 15:24:02 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstadd_back(t_list **begin_lst, t_list *lst)
{
	t_list	*tmp;

	if (*begin_lst != NULL)
	{
		tmp = *begin_lst;
		while ((*begin_lst)->next != NULL)
			*begin_lst = (*begin_lst)->next;
		(*begin_lst)->next = lst;
		*begin_lst = tmp;
	}
	else
		*begin_lst = lst;
}
