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

void	myopendir(char *path, t_env *e)
{
	DIR				*directory;
	struct dirent	*e_dir;

	if ((directory = opendir(path)) == NULL)
	{
		perror("ft_ls: ");
		return ;
	}
	if ((*e).flg->all == TRUE)
		while ((e_dir = readdir(directory)) != NULL)
			file_addback(&(*e).path->l, path, e_dir->d_name);
	else
		while ((e_dir = readdir(directory)) != NULL)
			if (e_dir->d_name[0] != '.')
				file_addback(&(*e).path->l, path, e_dir->d_name);
	if ((closedir(directory)) == (-1))
		exit(EXIT_FAILURE);
}
