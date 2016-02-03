/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <ibouchla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 18:08:35 by ibouchla          #+#    #+#             */
/*   Updated: 2016/02/03 19:48:38 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_swap(void *a, void *b, size_t type_a, size_t type_b)
{
	int				i;
	unsigned char	*bytes_tmp;
	unsigned char	*bytes_a;
	unsigned char	*bytes_b;

	i = 0;
	bytes_a = (unsigned char *)a;
	bytes_b = (unsigned char *)b;
	if (type_a == type_b)
	{
		bytes_tmp = malloc(type_a);
		while ((((bytes_tmp) && (i < (int)type_a))
			|| ((bytes_a[i] != '\0') && (bytes_b[i] != '\0')))
			&& (i < (int)type_a))
		{
			bytes_tmp[i] = bytes_a[i];
			bytes_a[i] = bytes_b[i];
			bytes_b[i] = bytes_tmp[i];
			i++;
		}
		free(bytes_tmp);
	}
}
