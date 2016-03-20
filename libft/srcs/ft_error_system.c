/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_system.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 23:49:27 by ibouchla          #+#    #+#             */
/*   Updated: 2016/03/19 14:47:18 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_error_system(void)
{
	ft_putendl_fd("Critical Error: A memory allocation error has occurred.", 2);
	exit(EXIT_FAILURE);
}
