/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <ibouchla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 22:59:33 by ibouchla          #+#    #+#             */
/*   Updated: 2016/02/04 21:17:41 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>
#include <stdio.h>

int	main(void)
{
	DIR*	dir;
	t_dir	*e_dir;
	t_st	s;

	dir = opendir("."); // Ouvre le dir
	while ((e_dir = readdir(dir))) // readdir renvoi NULL si erreur ou si end
		//ft_putendl(e_dir->d_name); // Voir man pour la struct DIR
	stat(".", &s);
	printf("Mode : %ho (octal)\n", s.st_mode);
	closedir(dir);
	return (0);
}
