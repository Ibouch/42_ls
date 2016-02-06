/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <ibouchla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 22:59:33 by ibouchla          #+#    #+#             */
/*   Updated: 2016/02/06 06:18:01 by ibouchla         ###   ########.fr       */
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

static	int	ft_print_error(char *str, char c, int type_error)
{
	if (!str || (ft_isprint(c)) == 0)
		return (-1);
	if (type_error == 0)
	{
		ft_putstr("ft_ls: illegal option -- ");
		ft_putchar(c);
		ft_putchar('\n');
		ft_putendl("usage: ft_ls [-Ralrt1] [file ...]");
		exit(1);
	}
	else if (type_error == 1)
	{
		ft_putstr("ft_ls: ");
		ft_putstr(str);
		ft_putendl(": No such file or directory");
	}
	else if (type_error == 2)
	{
		ft_putstr("ft_ls: ");
		ft_putstr(str);
		ft_putendl(": File name too long");
	}
	return (0);
}

static void	ft_check_flags(char *av, t_flags *flg)
{
	int	id;

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
		else
			ft_print_error("not recognized", av[id], 0);
	}
}

int	main(int ac, char **av)
{
	t_flags	flg;
	t_env	*e;
	t_dir	*elem_dir;
	t_st	s;

	ft_init_struct(&flg);
	e = ft_memalloc(sizeof(e));
	while (++e->x < ac)
	{
		if (av[e->x][0] == '-')
		{
			if (av[e->x][1] == '-' && e->error == FALSE)
			{
				if ((ft_isprint(av[e->x][2])) == 1)
					ft_print_error(av[e->x], '-', 0);
				e->error = TRUE;
			}
			else if (e->error == TRUE)
				ft_print_error(av[e->x], ' ', 1);
			else
				ft_check_flags(av[e->x], &flg);
		}
		else if ((ft_strlen(av[e->x])) > 255)
			ft_print_error(av[e->x], ' ', 2);
		if (av[e->x][0] != '-')
		{
			stat(av[e->x], &s);
			//ft_list_type();
			if (S_ISDIR(s.st_mode))
			{
				if (!(e->dir = opendir(av[e->x]))) // Ouvre le dir
				{
					ft_putstr("ft_ls: ");
					perror(elem_dir->d_name);
					exit(1);
				}
				while ((elem_dir = readdir(e->dir))) // readdir renvoi NULL si erreur ou si end
					ft_putendl(elem_dir->d_name); // Voir man pour la struct DIR
				if ((closedir(e->dir)) == (-1))
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
