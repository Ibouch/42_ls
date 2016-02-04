/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <ibouchla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 22:59:33 by ibouchla          #+#    #+#             */
/*   Updated: 2016/02/05 00:58:00 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static void	ft_init_struct(t_env e, t_flags opt)
{
	e.dir = NULL;
	e.x = 0;
	e.err = 0;
	opt.aff = '1';
	opt.rec_val = 0;
	opt.a_val = 0;
	opt.r_val = 0;
	opt.t_val = 0;
}

static void	ft_check_flags(t_env e, t_flags opt, char **av)
{
	int	id;

	if (e.err == 1)
	{
		ft_putstr("ft_ls: ");
		ft_putstr(av[e.x]);
		ft_putendl(": No such file or directory");
		exit(1);
	}
	id = 0;
	while (av[e.x][id] != '\0')
	{
		if (av[e.x][id] == '1')
			opt.aff = '1';
		else if (av[e.x][id] == 'l')
			opt.aff = 'l';
		else if (av[e.x][id] == 'R')
			opt.rec_val = 1;
		else if (av[e.x][id] == 'a')
			opt.a_val = 1;
		else if (av[e.x][id] == 'r')
			opt.r_val = 1;
		else if (av[e.x][id] == 't')
			opt.t_val = 1;
		++id;
	}
}

int	main(int ac, char **av)
{
	t_dir	*elem_dir;
	t_st	s;
	t_env	e;
	t_flags	opt;

	ft_init_struct(e, opt);
	while (++e.x < ac)
	{
		if (av[e.x][0] == '-')
			ft_check_flags(e, opt, av);
		else
		{
			stat(av[e.x], &s);
			if (S_ISDIR(s.st_mode))
			{
				if (!(e.dir = opendir(av[e.x]))) // Ouvre le dir
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
			if (e.x == 1)
				e.err = 1;
		}
	}
	return (0);
}
