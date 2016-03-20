/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_rights.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 22:04:13 by ibouchla          #+#    #+#             */
/*   Updated: 2016/03/13 22:04:16 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static void	define_gid_exec(mode_t mode)
{
	if (!(mode & S_IXGRP) & S_ISGID)
		ft_putchar('S');
	else if ((mode & S_IXGRP) & S_ISGID)
		ft_putchar('s');
	else if (mode & S_IXGRP)
		ft_putchar('x');
	else
		ft_putchar('-');
}

static void	define_uid_exec(mode_t mode)
{
	if (!(mode & S_IXUSR) & S_ISUID)
		ft_putchar('S');
	else if ((mode & S_IXUSR) & S_ISUID)
		ft_putchar('s');
	else if (mode & S_IXUSR)
		ft_putchar('x');
	else
		ft_putchar('-');
}

static void	define_type(mode_t mode)
{
	if (S_ISDIR(mode))
		ft_putchar('d');
	else if (S_ISREG(mode))
		ft_putchar('-');
	else if (S_ISCHR(mode))
		ft_putchar('c');
	else if (S_ISBLK(mode))
		ft_putchar('b');
	else if (S_ISFIFO(mode))
		ft_putchar('p');
	else if (S_ISLNK(mode))
		ft_putchar('l');
	else if (S_ISSOCK(mode))
		ft_putchar('s');
}

void		convert_rights(mode_t mode)
{
	define_type(mode);
	ft_putchar(((mode & S_IRUSR) ? 'r' : '-'));
	ft_putchar(((mode & S_IWUSR) ? 'w' : '-'));
	define_uid_exec(mode);
	ft_putchar(((mode & S_IRGRP) ? 'r' : '-'));
	ft_putchar(((mode & S_IWGRP) ? 'w' : '-'));
	define_gid_exec(mode);
	ft_putchar(((mode & S_IROTH) ? 'r' : '-'));
	ft_putchar(((mode & S_IWOTH) ? 'w' : '-'));
	ft_putchar(((mode & S_IXOTH) ? 'x' : '-'));
}
