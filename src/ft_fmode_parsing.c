/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fmode_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 00:07:53 by ibouchla          #+#    #+#             */
/*   Updated: 2016/02/16 00:08:01 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	ft_fmode_parsing(const char *s, t_env *e)
{
	t_stat	st;

	stat(s, &st);
	if (S_ISDIR(st.st_mode))
		ft_lstadd((t_list **)&e->path, ft_lstnew(s, ft_strlen(s) + 1));
	else if (S_ISREG(st.st_mode))
		ft_lstadd(&e->file, ft_lstnew(s, ft_strlen(s) + 1));
	else if (S_ISCHR(st.st_mode))
		ft_lstadd(&e->file, ft_lstnew(s, ft_strlen(s) + 1));
	else if (S_ISBLK(st.st_mode))
		ft_lstadd(&e->file, ft_lstnew(s, ft_strlen(s) + 1));
	else if (S_ISFIFO(st.st_mode))
		ft_lstadd(&e->file, ft_lstnew(s, ft_strlen(s) + 1));
	else if (S_ISLNK(st.st_mode))
		ft_lstadd(&e->file, ft_lstnew(s, ft_strlen(s) + 1));
	else if (S_ISSOCK(st.st_mode))
		ft_lstadd(&e->file, ft_lstnew(s, ft_strlen(s) + 1));
	else
		ft_lstadd((t_list **)&e->err, ft_lstnew(s, ft_strlen(s) + 1));
}
