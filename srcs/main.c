/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 04:29:51 by ibouchla          #+#    #+#             */
/*   Updated: 2016/02/24 04:30:00 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static void	del_env(t_env **alst)
{
	if (*alst != NULL)
	{
		if ((*alst)->flg != NULL)
			free((*alst)->flg);
		if ((*alst)->err != NULL)
			free((*alst)->err);
		if ((*alst)->file != NULL)
			free((*alst)->file);
		if ((*alst)->dir != NULL)
			free((*alst)->dir);
		if ((*alst)->len != NULL)
			free((*alst)->len);
		free(*alst);
	}
}

int			main(int ac, char **av)
{
    t_env   *e;

    if ((e = (t_env *)ft_memalloc(sizeof(t_env))) == NULL)
		error_system();
	params_parsing(ac, av, e);
	if (e->err == NULL && (e->dir == NULL && e->file == NULL))
	{
		if (e->flg->d == TRUE)
			file_lstadd(e, ".", FALSE);
		else
			dir_lstadd(&e->dir, e->flg, ".");
	}
	print_file_lst(e);
	print_dir_lst(e);
	del_env(&e);
	exit(EXIT_SUCCESS);
}
