/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_total.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 22:04:34 by ibouchla          #+#    #+#             */
/*   Updated: 2016/03/13 22:04:37 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	display_total(t_file *lst)
{
	blkcnt_t	nb;

	nb = 0;
	if (lst != NULL)
	{
		while (lst != NULL)
		{
			nb += lst->st.st_blocks;
			lst = lst->next;
		}
		ft_putstr("total ");
		ft_putnbr_endl(nb);
	}
}
