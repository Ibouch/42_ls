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

int main(int ac, char **av)
{
    t_env   *e;

    if ((e = (t_env *)ft_memalloc(sizeof(t_env))) == NULL)
		error_system();
	if ((e->len = (t_max_l *)ft_memalloc(sizeof(t_max_l))) == NULL)
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
	free(e->len);
	free(e->flg);
	exit(EXIT_SUCCESS);
}
