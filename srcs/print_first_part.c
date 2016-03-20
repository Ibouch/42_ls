/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_first_part.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 22:06:11 by ibouchla          #+#    #+#             */
/*   Updated: 2016/03/13 22:06:31 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void		print_first_part(t_env *e, t_bool inoeud_opt)
{
	if (inoeud_opt == TRUE)
	{
		print_sp(ft_nbrlen(e->file->st.st_ino), e->len->ino, FALSE);
		ft_putnbr(e->file->st.st_ino);
		ft_putchar(' ');
	}
	convert_rights(e->file->st.st_mode);
	print_sp(ft_nbrlen(e->file->st.st_nlink), e->len->n_lnk, TRUE);
	ft_putnbr(e->file->st.st_nlink);
	ft_putchar(' ');
}
