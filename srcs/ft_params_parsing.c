/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_params_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 18:29:23 by ibouchla          #+#    #+#             */
/*   Updated: 2016/02/16 03:18:32 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static void	ft_print_iusage(char c)
{
	ft_putstr_fd("ft_ls: illegal option -- ", 2);
	ft_putchar_fd(c, 2);
	ft_putchar_fd('\n', 2);
	ft_putendl_fd("usage: ft_ls [-Ralrt1] [file ...]", 2);
	exit(EXIT_FAILURE);
}

static void	ft_check_flags(char *av, t_env *e)
{
	int		id;
	t_flg	*flg;

	id = 0;
	flg = ft_memalloc(sizeof(t_flg));
	while (av[++id] != '\0')
	{
		if (av[id] == '1')
			flg->aff = '1';
		else if (av[id] == 'l')
			flg->aff = 'l';
		else if (av[id] == 'R')
			flg->rec = TRUE;
		else if (av[id] == 'a')
			flg->all = TRUE;
		else if (av[id] == 'r')
			flg->rev = TRUE;
		else if (av[id] == 't')
			flg->t = TRUE;
		else
			ft_print_iusage(av[id]);
	}
	e->flg = flg;
}

static void	ft_flags_parsing(char *av, t_env *e, t_bool *end_opt)
{
	if (av[1] == '-' && *end_opt == FALSE)
	{
		if ((ft_isprint(av[2])) == 1)
			ft_print_iusage('-');
		*end_opt = TRUE;
	}
	else if (*end_opt == TRUE || av[1] == '\0')
	{
		ft_lstadd((t_list **)&e->err, ft_lstnew(av, ft_strlen(av) + 1));
		*end_opt = TRUE;
	}
	else if (*end_opt == FALSE)
		ft_check_flags(av, e);
}

static void	ft_print_list_err(t_list *lst)
{
	while (lst != NULL)
	{
		ft_putstr("ft_ls: ");
		ft_putstr((char *)lst->content);
		ft_putendl(": No such file or directory");
		lst = lst->next;
	}
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
	ft_lst_sort((t_list **)&e->err, &ft_strcmp);
	ft_lst_sort((t_list **)&e->file, &ft_strcmp);
	ft_lst_sort((t_list **)&e->path, &ft_strcmp);
	ft_print_list_err((t_list *)e->err);
	ft_print_lst((t_list *)e->file);
	ft_print_lst((t_list *)e->dir);
}
