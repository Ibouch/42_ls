/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_rights.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 04:29:25 by ibouchla          #+#    #+#             */
/*   Updated: 2016/02/24 04:29:31 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static void	define_type(t_stat *st)
{
	if (S_ISDIR(st->st_mode))
		ft_putchar('d');
	else if (S_ISREG(st->st_mode))
		ft_putchar('-');
	else if (S_ISCHR(st->st_mode))
		ft_putchar('c');
	else if (S_ISBLK(st->st_mode))
		ft_putchar('b');
	else if (S_ISFIFO(st->st_mode))
		ft_putchar('p');
	else if (S_ISLNK(st->st_mode))
		ft_putchar('l');
	else if (S_ISSOCK(st->st_mode))
		ft_putchar('s');
}

void		convert_rights(t_stat *st)
{
	define_type(st);
	ft_putchar(((st->st_mode & S_IRUSR) ? 'r' : '-'));
	ft_putchar(((st->st_mode & S_IWUSR) ? 'w' : '-'));
	ft_putchar(((st->st_mode & S_IXUSR) ? 'x' : '-'));
	ft_putchar(((st->st_mode & S_IRGRP) ? 'r' : '-'));
	ft_putchar(((st->st_mode & S_IWGRP) ? 'w' : '-'));
	ft_putchar(((st->st_mode & S_IXGRP) ? 'x' : '-'));
	ft_putchar(((st->st_mode & S_IROTH) ? 'r' : '-'));
	ft_putchar(((st->st_mode & S_IWOTH) ? 'w' : '-'));
	ft_putchar(((st->st_mode & S_IXOTH) ? 'x' : '-'));
}
