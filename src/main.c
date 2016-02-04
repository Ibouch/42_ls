/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <ibouchla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 22:59:33 by ibouchla          #+#    #+#             */
/*   Updated: 2016/02/04 22:15:42 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	DIR*	dir;
	t_dir	*e_dir;
	t_st	s;

	if (ac == 42)
		return 0;
	stat(av[1], &s);
	if (S_ISDIR(s.st_mode))
	{
		dir = opendir(av[1]); // Ouvre le dir
		while ((e_dir = readdir(dir))) // readdir renvoi NULL si erreur ou si end
			ft_putendl(e_dir->d_name); // Voir man pour la struct DIR
		closedir(dir);
	}
	else if (S_ISREG(s.st_mode))
		ft_putendl("File detected !");
	return (0);
}
