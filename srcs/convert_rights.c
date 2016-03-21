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

static void	define_oth_exec(mode_t mode)
{
	if (S_ISVTX & mode)
		ft_putchar(((mode & S_IXOTH) ? 't' : 'T'));
	else
		ft_putchar(((mode & S_IXOTH) ? 'x' : '-'));
}

static void	define_gid_exec(mode_t mode)
{
	if (S_ISGID & mode)
		ft_putchar(((mode & S_IXGRP) ? 's' : 'S'));
	else
		ft_putchar(((mode & S_IXGRP) ? 'x' : '-'));
}

static void	define_uid_exec(mode_t mode)
{
	if (S_ISUID & mode)
		ft_putchar(((mode & S_IXUSR) ? 's' : 'S'));
	else
		ft_putchar(((mode & S_IXUSR) ? 'x' : '-'));
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
	define_oth_exec(mode);
}
