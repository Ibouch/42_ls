/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 17:21:21 by ibouchla          #+#    #+#             */
/*   Updated: 2016/03/14 17:40:50 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	print_color(char *s, mode_t type, t_bool endl, int opt)
{
	if (opt == TRUE)
	{
		if (S_ISDIR(type))
			ft_putstr(H_BLUE);
		else if (S_ISREG(type))
		{
			ft_putstr(((type & S_IXUSR) || (type & S_IXGRP) || (type & S_IXOTH))
			? H_RED : H_WHITE);
		}
		else if (S_ISCHR(type))
			ft_putstr(H_GREEN);
		else if (S_ISBLK(type))
			ft_putstr(H_CYAN);
		else if (S_ISFIFO(type))
			ft_putstr(H_BLACK);
		else if (S_ISLNK(type))
			ft_putstr(H_YELLOW);
		else if (S_ISSOCK(type))
			ft_putstr(H_PURPLE);
	}
	ft_putstr(s);
	if (opt == TRUE)
		ft_putstr(INIT);
	if (endl == TRUE)
		ft_putchar('\n');
}
