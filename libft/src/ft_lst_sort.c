/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 04:45:34 by ibouchla          #+#    #+#             */
/*   Updated: 2016/02/15 04:50:20 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lst_sort(t_list **alist, int (*f_cmp)())
{
	t_list	*begin_list;
	t_list	*tmp;
	void	*swap;

	begin_list = *alist;
	while (*alist != NULL)
	{
		tmp = begin_list;
		while (tmp->next != NULL)
		{
			if ((f_cmp(tmp->content, tmp->next->content)) > 0)
			{
				swap = tmp->content;
				tmp->content = tmp->next->content;
				tmp->next->content = swap;
			}
			tmp = tmp->next;
		}
		*alist = (*alist)->next;
	}
	*alist = begin_list;
}
