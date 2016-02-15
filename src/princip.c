/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <ibouchla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 20:24:48 by ibouchla          #+#    #+#             */
/*   Updated: 2016/02/10 22:10:23 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	ft_parsing(int ac, char	**av)
{
	int x;
	int	parse_error;

	x = 0;
	parse_error = FALSE;
	while (++x < ac)
	{
		if (av[x][0] == '-')
		{
			if (av[x][1] == '-' && parse_error == FALSE)
			{
				if ((ft_isprint(av[x][2])) == 1)
					ft_print_error(av[x], '-', 0); /* illegal usage */
				parse_error = TRUE;	/* [--] fin des flags */
			}
			else if ((ft_strlen(av[x])) > 255)
				ft_print_error(av[x], ' ', 2); /* File name too long */
			else if (e->error == TRUE)
				ft_print_error(av[x], ' ', 1); /* ft_ls . -l : no such */
			else
				ft_check_flags(av[x], &flg);
		}
		else if ((ft_strlen(av[x])) > 255)
			ft_print_error(av[x], ' ', 2); /* File name too long */
		else
		{
			if (x == 1)
				parse_error = TRUE;
			/* Opendir av[x] */
		}
	}
}

int main(int ac, char **av)
{
	t_env	e;

	e = ft_memalloc(sizeof(t_env));
	ft_parsing(ac, av, e)
	return (0);
}
