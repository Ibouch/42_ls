/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <ibouchla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 22:59:33 by ibouchla          #+#    #+#             */
/*   Updated: 2016/02/06 07:20:19 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

int	ft_print_error(char *str, char c, int type_error)
{
	if (!str || (ft_isprint(c)) == 0)
		return (-1);
	if (type_error == 0)
	{
		ft_putstr("ft_ls: illegal option -- ");
		ft_putchar(c);
		ft_putchar('\n');
		ft_putendl("usage: ft_ls [-Ralrt1] [file ...]");
		exit(1);
	}
	else if (type_error == 1)
	{
		ft_putstr("ft_ls: ");
		ft_putstr(str);
		ft_putendl(": No such file or directory");
	}
	else if (type_error == 2)
	{
		ft_putstr("ft_ls: ");
		ft_putstr(str);
		ft_putendl(": File name too long");
	}
	return (0);
}
