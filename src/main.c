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


static int 	ft_check_flags(char *av, t_bool *end_opt)
{
	int i;

	i = 0;
	if (av[1] == '-' && *end_opt == FALSE)
	{
		if ((ft_isprint(av[2])) == 1)
			ft_print_error("Illegal usage", '-', 0);
		*end_opt = TRUE;
	}
	else if (*end_opt == TRUE)
		ft_print_error(av, ' ', 1); /* ft_ls . -l : no such */
	else if (*end_opt == FALSE)
	{
		while (++i < (int)ft_strlen(av))
			if ((ft_strchr("Ralrt1", av[i])) == NULL)
				ft_print_error("Illegal usage", av[i], 0);
			i = 0;
	}
	/* A cette etape desormais on check le flag rencontrer */
//	ft_check_flags(av);
	return (0);
}

static int	ft_params_parsing(int ac, char **av)
{
	int x;
	int end_opt;

	x = 0;
	end_opt = FALSE;
	while (++x < ac)
	{
		if (av[x][0] == '-') // potential option
			ft_check_flags(av[x], &end_opt);
		else
		{
			if (x == 1)
				end_opt = TRUE;
			if ((ft_strlen(av[x])) > 255)
			{
				ft_print_error(av[x], ' ', 2); /* File name too long */
				return (-1);
			}
			/* A cette etape desormais on check le type de l'arg sinon on renvoi err */
			//ft_check_fsys(av[x]);
		}
	}
	return (0);
}

int			main(int ac, char **av)
{
	if ((ft_params_parsing(ac, av)) == (-1))
		return (0);
	
	/* codage ensuite de tout les options */

	return (0);
}