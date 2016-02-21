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
	char				*name;
	struct s_err		*next;
}						t_err;

typedef struct			s_path
{
	char				*name;
	struct s_path		*next;
}						t_path;

typedef struct			s_file
{
	long				inoeud;
	unsigned long		rights;
	long				n_lnk;
	long				uid;
	long				gid;
	long long			f_size;
	long long			blocks;
	char				*name;
	struct s_file		*next;
}						t_file;

typedef struct			s_flg
{
	char				aff;
	t_bool				all;
	t_bool				rec;
	t_bool				rev;
	t_bool				t;
	t_bool				i;
}						t_flg;

typedef struct			s_env
{
	DIR					*dir;
	struct s_flg		*flg;
	struct s_err		*err;
	struct s_path		*path;
	struct s_file		*file;
}						t_env;

void					params_parsing(int ac, char **av, t_env *e);
int						file_lst_rev(t_file **alst);
void					delimit_flags(t_env *e);
void					mystat(char *path, t_env *e);
void					myopendir(char *path, t_env *e);
void					file_lstadd(t_file **alst, char *path, t_stat *st);
void					file_addback(t_file **alst, char *path, t_stat *st);
t_file					*new_fstat(char *name, t_stat *st);

#endif
