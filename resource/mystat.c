/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mystat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 04:30:23 by ibouchla          #+#    #+#             */
/*   Updated: 2016/02/24 04:30:29 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void 	mystat(char *path, t_env *e)
{
	if (e)
		;
	//t_stat	st;

/*	if ((e->path->l = (t_file *)malloc(sizeof(t_file))) == NULL)
		exit(EXIT_FAILURE);
*//*	if ((lstat(path, &st)) == 0)
	{
		if ((S_ISDIR(st.st_mode)) == TRUE)
			myopendir(path, e);
		else
			file_lstadd(&e->path->l, path); // On add au debut tout != DIR
	}
	else
		exit(EXIT_FAILURE);
*/
ft_putendl(path);
ft_putendl("c'est cii ??");
}
