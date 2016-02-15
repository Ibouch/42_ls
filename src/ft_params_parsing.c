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

static int	ft_flags_parsing(char *av, t_bool *end_opt)
{
	t_err	*err;
	int		i;

	err = NULL;
	i = 0;
	if (av[1] == '-' && *end_opt == FALSE)
	{
		if ((ft_isprint(av[2])) == 1)
			ft_print_error("Illegal usage", '-', 0);
		*end_opt = TRUE;
	}
	else if (*end_opt == TRUE)
	{
		ft_print_error(av, ' ', 1); /* ft_ls . -l : no such */
		ft_lstadd((t_list **)&err, ft_lstnew(av, ft_strlen(av) + 1));
	}
	else if (*end_opt == FALSE)
	{
		while (++i < (int)ft_strlen(av))
			if ((ft_strchr("Ralrt1", av[i])) == NULL)
				ft_print_error("Illegal usage", av[i], 0);
			i = 0;
	}
	/* A cette etape desormais on check le flag rencontrer */
	//ft_check_flags(av);
	return (0);
}

static int	ft_fmode_parsing(char *av)
{
	if ((ft_strlen(av)) > 255)
	{
		ft_print_error(av, ' ', 2); /* File name too long */
		return (-1);
	}
	//ft_check_fmode(av[x]);
	return (0);
}

int			ft_params_parsing(int ac, char **av)
{
	int		x;
	t_bool	end_opt;

	x = 0;
	end_opt = FALSE;
	while (++x < ac)
	{
		if (av[x][0] == '-') // potential option
			ft_flags_parsing(av[x], &end_opt);
		else
		{
			end_opt = TRUE;
			ft_fmode_parsing(av[x]);
		}
	}
	return (0);
}
