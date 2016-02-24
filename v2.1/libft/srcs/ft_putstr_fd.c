/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <ibouchla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:13:49 by ibouchla          #+#    #+#             */
/*   Updated: 2016/02/03 19:44:18 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putstr_fd(char const *s, int fd)
{
	int	i;

	i = ft_strlen(s);
	while (i--)
		ft_putchar_fd(*s++, fd);
}
