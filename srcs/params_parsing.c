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
	ft_putendl_fd("usage: ft_ls [-Radfilrt1] [file ...]", 2);
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
		else if (av[id] == 'd')
			e->flg->d = TRUE;
		else if (av[id] == 'f')
		{
			e->flg->f = TRUE;
			e->flg->all = TRUE;
		}
		else
			print_iusage(av[id]);
	}
}

static void	check_argument(char *path, t_env *e, t_bool *end_opt)
{
	t_stat	st;
	char	*er;

	*end_opt = TRUE;
	if ((lstat(path, &st)) == 0)
	{
		if ((S_ISDIR(st.st_mode)))
		{	if (e->flg->d == TRUE)
				file_lstadd(e, path, FALSE);
			else
				dir_lstadd(&e->dir, e->flg, path);
		}
		else
			file_lstadd(e, path, FALSE);
	}
	else
	{
		er = ft_strjoin("ft_ls: ", path);
		er = ft_strjoin(er, ": ");
		er = ft_strjoin(er, strerror(errno));
		if (er == NULL)
			error_system();
		if (e->flg->f == TRUE)
			ft_lstadd_back(&(e->err), (char *)er, ft_strlen(er) + 1);
		else
			ft_lstadd(&(e->err), (char *)er, ft_strlen(er) + 1);
	}
}

static void	flags_parsing(char *av, t_env *e, t_bool *end_opt)
{
	if (av[1] == '-' && *end_opt == FALSE)
	{
		if ((ft_isprint(av[2])) == 1)
			print_iusage('-');
		*end_opt = TRUE;
	}
	else if (*end_opt == TRUE || av[1] == '\0')
		check_argument(av, e, end_opt);
	else if (*end_opt == FALSE)
		check_flags(av, e);
}

void		params_parsing(int ac, char **av, t_env *e)
{
	int		x;
	t_bool	end_opt;

	x = 0;
	end_opt = FALSE;
	if ((e->flg = (t_flag *)ft_memalloc(sizeof(t_flag))) == NULL)
		error_system();
	while (++x < ac)
	{
		if (av[x][0] == '-' && end_opt == FALSE)
			flags_parsing(av[x], e, &end_opt);
		else
			check_argument(av[x], e, &end_opt);
	}
	if (e->err != NULL)
	{
		if (e->flg->f == FALSE)
			ft_lst_sort(&(e->err), &ft_strcmp);
		ft_print_lst(e->err, 2);
		e->display_data = TRUE;
	}
}
