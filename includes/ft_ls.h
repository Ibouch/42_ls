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
# include <time.h>
# include <grp.h>
# include <pwd.h>

typedef struct stat		t_stat;

typedef struct			s_file
{
	long				inoeud;
	char				*rights;
	char				*n_lnk;
	long				num_uid;
	long				num_gid;
	char				*uid;
	char				*gid;
	char				*f_size;
	long long			blocks;
	char				*etime;
	char				*mtime;
	char				*name;
	char				*path;
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

typedef struct			s_dir
{
	struct s_file		*l;
	struct s_dir		*next;
}						t_dir;

typedef struct			s_env
{
	struct s_flg		*flg;
	struct s_list		*err;
	struct s_list		*arg;
	struct s_file		*file;
	struct s_dir		*path;
}						t_env;

void					params_parsing(int ac, char **av, t_env *e);
void					delimit_flags(t_env *e);
void					file_lstadd(t_file **alst, char *p, char *n, int dir);
void					file_sort(t_file **alst, char *field, int (*f_cmp)());
void					file_lstdel(t_file **alst);
t_file					*new_fstat(char *path, char *name, int dir);
void					convert_rights(t_file *new_node, t_stat *st);
int						myopendir(char *path, t_env *e);

#endif
