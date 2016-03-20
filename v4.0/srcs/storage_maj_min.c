/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   storage_maj_min.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 22:04:05 by ibouchla          #+#    #+#             */
/*   Updated: 2016/03/13 22:04:07 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	storage_maj_min(t_max_l *len, t_stat *st)
{
	size_t	maj;
	size_t	min;

	maj = ft_nbrlen(major(st->st_rdev));
	min = ft_nbrlen(minor(st->st_rdev));
	len->major = ((maj > len->major) ? maj : len->major);
	len->minor = ((min > len->minor) ? min : len->minor);
}
