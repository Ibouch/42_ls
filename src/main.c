/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <ibouchla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 22:59:33 by ibouchla          #+#    #+#             */
/*   Updated: 2016/02/04 00:47:25 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

int	main(void)
{
	DIR*	dir;
	t_dir	*e_dir;

	dir = opendir("/nfs/zfs-student-2/users/ibouchla/42_project/42_ls");
	while ((e_dir = readdir(dir)))
		ft_putendl(e_dir->d_name);
	return (0);
}
