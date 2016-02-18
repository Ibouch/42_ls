/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lst_err.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 00:45:49 by ibouchla          #+#    #+#             */
/*   Updated: 2016/02/19 00:46:04 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	print_lst_err(t_list *lst)
{
	while (lst != NULL)
	{
		ft_putstr("ft_ls: ");
		ft_putstr((char *)lst->content);
		ft_putendl(": No such file or directory");
		lst = lst->next;
	}
}
