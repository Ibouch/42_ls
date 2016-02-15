/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_params_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 18:29:23 by ibouchla          #+#    #+#             */
/*   Updated: 2016/02/15 18:30:23 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static void	ft_print_iusage(char c)
{
	ft_putstr("ft_ls: illegal option -- ");
	ft_putchar(c);
	ft_putchar('\n');
	ft_putendl("usage: ft_ls [-Ralrt1] [file ...]");
	exit(1);
}

static void	ft_check_flags(char *av, t_env *e)
{
	int	id;

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
		else
			ft_print_iusage(av[id]);
	}
}

static void	ft_flags_parsing(char *av, t_env *e, t_bool *end_opt)
{
	if (av[1] == '-' && *end_opt == FALSE)
	{
		if ((ft_isprint(av[2])) == 1)
			ft_print_iusage('-');
		*end_opt = TRUE;
	}
	else if (*end_opt == TRUE)
		ft_lstadd((t_list **)&e->err, ft_lstnew(av, ft_strlen(av) + 1));
	else if (*end_opt == FALSE)
		ft_check_flags(av, e);
}

void		ft_params_parsing(int ac, char **av, t_env *e)
{
	int		x;
	t_bool	end_opt;

	x = 0;
	end_opt = FALSE;
	while (++x < ac)
	{
		if (av[x][0] == '-')
			ft_flags_parsing(av[x], e, &end_opt);
		else
		{
			end_opt = TRUE;
			ft_fmode_parsing(av[x], e);
		}
	}
}
