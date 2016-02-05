/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <ibouchla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 22:59:33 by ibouchla          #+#    #+#             */
/*   Updated: 2016/02/05 23:30:38 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static void	ft_init_struct(t_flags *flg)
{
	flg->opt_all = 0;
	flg->opt_rec = 0;
	flg->opt_rev = 0;
	flg->opt_time = 0;
	flg->is_file = 0;
	flg->is_dir = 0;
	flg->is_chr = 0;
	flg->is_blk = 0;
	flg->is_fifo = 0;
	flg->is_lnk = 0;
	flg->is_sock = 0;
	flg->opt_aff = '1';
}

static void	ft_check_flags(char *av, t_bool error, t_flags *flg)
{
	int	id;

	if (error == TRUE)
	{
		ft_putendl("ft_ls: No such file or directory");
		return (1);
	}
	id = 0;
	while (av[++id] != '\0')
	{
		if (av[id] == '1')
			flg->opt_aff = '1';
		else if (av[id] == 'l')
			flg->opt_aff = 'l';
		else if (av[id] == 'R')
			flg->opt_rec = TRUE;
		else if (av[id] == 'a')
			flg->opt_all = TRUE;
		else if (av[id] == 'r')
			flg->opt_rev = TRUE;
		else if (av[id] == 't')
			flg->opt_time = TRUE;
	}
}
static	void	ft_print_error(void)
{
	ft_putendl("ft_ls: illegal option -- -");
	ft_putendl("usage: ft_ls [-Ralrt1] [file ...]");
	exit(1);
}
int	main(int ac, char **av)
{
	t_flags	flg;
	t_env	*e;
/*
	t_dir	*elem_dir;
	t_st	s;
*/
	ft_init_struct(&flg);
	e = ft_memalloc(sizeof(e));
	while (++e->x < ac)
	{
		if (av[e->x][0] == '-')
		{
			if (av[e->x][1] == '-' && e->error == TRUE)
				ft_putstr("ft_ls: --x No such file or directory");
			else if (av[e->x][1] == '-' && e->error == FALSE)
			{
				if (av[e->x][2] est ascii)
					ft_print_error();
				e->error = TRUE;
			}
			ft_check_flags(av[e->x], e->error, &flg);
		}
		else
		{
			stat(av[x], &s);
			if (S_ISDIR(s.st_mode))
			{
				if (!(e.dir = opendir(av[x]))) // Ouvre le dir
				{
					perror("ft_ls");
					exit(1);
				}
				while ((elem_dir = readdir(e.dir))) // readdir renvoi NULL si erreur ou si end
					ft_putendl(elem_dir->d_name); // Voir man pour la struct DIR
				if ((closedir(e.dir)) == (-1))
					exit(-1);
			}
			else if (S_ISREG(s.st_mode))
				ft_putendl("File detected !");
			if (e->x == 1)
				e->error = TRUE;
		}
	}
	return (0);
}
