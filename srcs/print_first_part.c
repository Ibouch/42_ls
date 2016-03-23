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

static int	determine_xattr(char *path)
{
	acl_t	acl;

	if ((listxattr(path, NULL, 4096, XATTR_NOFOLLOW)) > 0)
	{
		ft_putchar('@');
		return (1);
	}
	else
	{
		if ((acl = acl_get_link_np(path, ACL_TYPE_EXTENDED))
			|| (acl = acl_get_file(path, ACL_TYPE_EXTENDED)))
		{
			ft_putchar('+');
			acl_free((void *)acl);
			return (1);
		}
	}
	return (0);
}

void		print_first_part(t_env *e, t_bool inoeud_opt)
{
	int	ret;

	if (inoeud_opt == TRUE)
	{
		print_sp(ft_nbrlen(e->file->st.st_ino), e->len->ino, FALSE);
		ft_putnbr(e->file->st.st_ino);
		ft_putchar(' ');
	}
	convert_rights(e->file->st.st_mode);
	ret = determine_xattr(e->file->path);
	print_sp(ft_nbrlen(e->file->st.st_nlink) + ret, e->len->n_lnk, TRUE);
	ft_putnbr(e->file->st.st_nlink);
	ft_putchar(' ');
}
