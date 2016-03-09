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
	params_parsing(ac, av, e);
	print_file_lst(e);
	print_dir_lst(e);
	return (0);
}
