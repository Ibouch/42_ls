/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 00:52:27 by ibouchla          #+#    #+#             */
/*   Updated: 2016/03/13 22:05:38 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static void	check_flags_bonus(char c, t_flag *flg)
{
	if (c == 'f')
	{
		flg->f = TRUE;
		flg->all = TRUE;
	}
	else if (c == 'g')
		flg->g = TRUE;
	else
		print_iusage(c);
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
		else
			check_flags_bonus(av[id], e->flg);
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
		ft_error_system();
	if ((e->len = (t_max_l *)ft_memalloc(sizeof(t_max_l))) == NULL)
		ft_error_system();
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
