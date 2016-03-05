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

    e = ft_memalloc(sizeof(t_env));
	params_parsing(ac, av, e);
	delimit_flags(e);
    return (0);
}
