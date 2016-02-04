/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <ibouchla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 12:21:30 by ibouchla          #+#    #+#             */
/*   Updated: 2016/02/05 00:57:25 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <libft.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <errno.h>
# include <stdio.h>

typedef struct dirent	t_dir;
typedef struct stat		t_st;

typedef struct			s_flags
{
	char				aff;
	unsigned int		rec_val;
	unsigned int		a_val;
	unsigned int		r_val;
	unsigned int		t_val;
}						t_flags;

typedef struct			s_env
{
	DIR					*dir;
	int					x;
	int					err;
}						t_env;

#endif
