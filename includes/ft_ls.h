/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <ibouchla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 12:21:30 by ibouchla          #+#    #+#             */
/*   Updated: 2016/02/10 20:29:15 by ibouchla         ###   ########.fr       */
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

typedef struct			s_err
{
	char				*str;
	t_err				*next;
}						t_err;

typedef struct			s_env
{
	DIR					*dir;
	t_bool				error;
	t_bool				display_path;
	int					x;
	char				*path;
	char				opt_aff;
	t_bool				opt_all;
	t_bool				opt_rec;
	t_bool				opt_rev;
	t_bool				opt_time;
	t_bool				is_file;
	t_bool				is_dir;
	t_bool				is_chr;
	t_bool				is_blk;
	t_bool				is_fifo;
	t_bool				is_lnk;
	t_bool				is_sock;
}						t_env;

int						ft_print_error(char *str, char c, int type_error);

#endif
