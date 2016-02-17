/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 02:19:53 by ibouchla          #+#    #+#             */
/*   Updated: 2016/02/15 02:19:57 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

int	main(int ac, char **av)
{
	t_env	*e;

	e = ft_memalloc(sizeof(t_env));
	ft_params_parsing(ac, av, e);
	//ft_delimit_flags(e);
	return (0);
}
