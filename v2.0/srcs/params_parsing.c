/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 00:52:27 by ibouchla          #+#    #+#             */
/*   Updated: 2016/02/19 00:52:31 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static void	print_iusage(char c)
{
	ft_putstr_fd("ft_ls: illegal option -- ", 2);
	ft_putchar_fd(c, 2);
	ft_putchar_fd('\n', 2);
	ft_putendl_fd("usage: ft_ls [-Railrt1] [file ...]", 2);
	exit(EXIT_FAILURE);
}

static void	check_flags(char *av, t_env *e)
{
	int		id;

	id = 0;
	while (av[++id] != '\0')
	{
		if (av[id] == '1')
			e->flg->aff = '1';
		else if (av[id] == 'l')
			e->flg->aff = 'l';
		else if (av[id] == 'R')
			e->flg->rec = TRUE;
		else if (av[id] == 'a')
			e->flg->all = TRUE;
		else if (av[id] == 'r')
			e->flg->rev = TRUE;
		else if (av[id] == 't')
			e->flg->t = TRUE;
		else if (av[id] == 'i')
			e->flg->i = TRUE;
		else
			print_iusage(av[id]);
	}
}
/*
static void	fmode_parsing(char *s, t_env *e)
{
	t_stat	st;
	char	*er;

	stat(s, &st);
	if ((st.st_mode) > 0)
		file_lstadd(&e->file , new_fstats(s, &st));
	else
	{
		er = "ft_ls: ";
		er = ft_strjoin(er, s);
		er = ft_strjoin(er, ": ");
		er = ft_strjoin(er, strerror(errno));
		ft_lstadd((t_list **)&e->err, ft_lstnew(er, ft_strlen(er) + 1));
	}
	ft_bzero(&st, sizeof(t_stat));
}
*/
static void	flags_parsing(char *av, t_env *e, t_bool *end_opt)
{
	if (av[1] == '-' && *end_opt == FALSE)
	{
		if ((ft_isprint(av[2])) == 1)
			print_iusage('-');
		*end_opt = TRUE;
	}
	else if (*end_opt == TRUE || av[1] == '\0')
	{
		ft_lstadd((t_list **)&e->path, (char *)av, (ft_strlen(av) + 1));
		*end_opt = TRUE;
	}
	else if (*end_opt == FALSE)
		check_flags(av, e);
}

void		params_parsing(int ac, char **av, t_env *e)
{
	int		x;
	t_bool	end_opt;

	x = 0;
	end_opt = FALSE;
	while (++x < ac)
	{
		if (av[x][0] == '-' && end_opt == FALSE)
			flags_parsing(av[x], e, &end_opt);
		else
		{
			end_opt = TRUE;
			ft_lstadd((t_list **)&e->path, (char *)av[x], ft_strlen(av[x]) + 1);
		}
	}
	ft_lst_sort((t_list **)&e->path, &ft_strcmp);
}
