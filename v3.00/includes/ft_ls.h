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
# define SIX_MONTH -15778800
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

typedef struct			s_flag
{
	char				aff;
	t_bool				all;
	t_bool				rec;
	t_bool				rev;
	t_bool				t;
	t_bool				i;
}						t_flag;

typedef struct			s_file
{
	ino_t				inoeud;
	char				*rights;
	char				*n_lnk;
	char				*uid;
	char				*gid;
	char				*f_size;
	blkcnt_t			blocks;
	struct timespec		s_spec;
	char				*name;
	char				*path;
	t_bool				is_dir;
	struct s_file		*next;
}						t_file;

typedef struct			s_dir
{
	char				*path;
	struct timespec		s_spec;
	struct s_dir		*rec;
	struct s_dir		*next;
}						t_dir;

typedef struct			s_env
{
	struct s_flag		*flg;
	struct s_list		*err;
	struct s_file		*file;
	struct s_dir		*dir;
	t_bool				display_data;
}						t_env;

void					params_parsing(int ac, char **av, t_env *e);
void					delimit_flags(t_env *e);
void					display_data(t_file *lst, char *path, char aff);
void 					dir_lstadd(t_dir **alst, t_flag *flg, char *dir_name);
void					dir_addback(t_dir **alst, char *dir_path);
void					dir_lstdel(t_dir **alst);
t_dir					*new_dirstat(char *dir_path);
void					print_file_lst(t_env *e, t_bool dir);
void					print_file_endl(t_env *e, t_bool dir);
void					file_lstadd(t_env *e, char *path_name);
void					file_lstdel(t_file **alst);
t_file					*new_fstat(char *path_name);
void					convert_rights(t_file *new_node, t_stat *st);
int						myopendir(char *path, t_env *e);

#endif
