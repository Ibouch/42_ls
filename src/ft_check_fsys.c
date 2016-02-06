/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_fsys.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <ibouchla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 22:59:33 by ibouchla          #+#    #+#             */
/*   Updated: 2016/02/06 08:39:16 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

int	ft_check_fsys(t_flags *flg, t_env *e, char *str)
{
	t_dir	*elem_dir;
	t_st	s;

	stat(str, &s);
	if (S_ISREG(s.st_mode))
		flg->is_file = 1;
	else if (S_ISDIR(s.st_mode))
	{
		/* Les lignes qui suivent sont un comportement indesirable
		   Je prefere juste une fnt qui me dise a quoi j'ai a faire plutot que de traiter
		   la recup des donner et en meme temps gerer le cas defini.
		*/
		flg->is_dir = 1;
		if (!(e->dir = opendir(str))) // Ouvre le dir
		{
			ft_putstr("ft_ls: ");
			perror(str);
			return (-1);
		}
		/*
		if (e->display_path == TRUE)
		{
			ft_putstr(str);
			ft_putendl(":");
		}
		*/
		while ((elem_dir = readdir(e->dir))) // readdir renvoi NULL si erreur ou si end
			ft_putendl(elem_dir->d_name); // Voir man pour la struct DIR
		if ((closedir(e->dir)) == (-1))
			exit(-1);
	}
	else if (S_ISCHR(s.st_mode))
		flg->is_chr = 1;
	else if (S_ISBLK(s.st_mode))
		flg->is_blk = 1;
	else if (S_ISFIFO(s.st_mode))
		flg->is_fifo = 1;
	else if (S_ISLNK(s.st_mode))
		flg->is_lnk = 1;
	else if (S_ISSOCK(s.st_mode))
		flg->is_sock = 1;
	else
		ft_print_error(str, ' ', 1);
	if (e->x == 1)
		e->error = TRUE;
	return (0);
}
