/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_iusage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 22:03:46 by ibouchla          #+#    #+#             */
/*   Updated: 2016/03/13 22:03:48 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	print_iusage(char c)
{
	ft_putstr_fd("ft_ls: illegal option -- ", 2);
	ft_putchar_fd(c, 2);
	ft_putchar_fd('\n', 2);
	ft_putendl_fd("usage: ft_ls [-Radfgilrt1] [file ...]", 2);
	exit(EXIT_FAILURE);
}
