/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myopendir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 04:30:08 by ibouchla          #+#    #+#             */
/*   Updated: 2016/02/24 04:30:12 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

int	myopendir(char *path, t_env *e)
{
	DIR				*directory;
	struct dirent	*e_dir;

	if ((directory = opendir(path)) == NULL)
	{
		perror("ft_ls: ");
		return (-1);
	}
	if ((*e).flg->all == TRUE)
		while ((e_dir = readdir(directory)) != NULL)
			file_lstadd(&(*e).file, path, e_dir->d_name, 1);
	else
		while ((e_dir = readdir(directory)) != NULL)
			if (e_dir->d_name[0] != '.')
				file_lstadd(&(*e).file, path, e_dir->d_name, 1);
	if ((closedir(directory)) == (-1))
		exit(EXIT_FAILURE);
	return (0);
}
