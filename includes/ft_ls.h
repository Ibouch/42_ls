/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <ibouchla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 12:21:30 by ibouchla          #+#    #+#             */
/*   Updated: 2016/02/11 03:27:22 by ibouchla         ###   ########.fr       */
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
typedef struct stat		t_stat;

typedef struct			s_err
{
	char				*str;
	struct s_err		*next;
}						t_err;

typedef struct 			s_path
{
	char				*str;
	struct s_path		*next;
}						t_path;

typedef struct			s_flg
{
	char				aff;
	t_bool				all;
	t_bool				rec;
	t_bool				rev;
	t_bool				t;
}						t_flg;

typedef struct 			s_fmode
{
	t_bool				is_file;
	t_bool				is_dir;
	t_bool				is_chr;
	t_bool				is_blk;
	t_bool				is_fifo;
	t_bool				is_lnk;
	t_bool				is_sock;
}						t_fmode;
typedef struct			s_env
{
	t_bool				display_path;
	DIR					*dir;
	struct s_err		*err;
	struct s_path		*path;
	struct s_flg		*flg;
	struct s_fmode		*fmode;
}						t_env;

int						ft_params_parsing(int ac, char **av);
int						ft_print_error(char *str, char c, int type_error);

#endif
