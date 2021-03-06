/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <ibouchla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 12:21:30 by ibouchla          #+#    #+#             */
/*   Updated: 2016/03/22 01:14:59 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# define SIX_MONTH -15778800
# include <libft.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/xattr.h>
# include <sys/acl.h>
# include <time.h>
# include <grp.h>
# include <pwd.h>

typedef struct stat		t_stat;
typedef	size_t			t_max_len;

typedef struct			s_flag
{
	char				aff;
	t_bool				all;
	t_bool				rec;
	t_bool				rev;
	t_bool				t;
	t_bool				i;
	t_bool				d;
	t_bool				f;
	t_bool				g;
	t_bool				col;
}						t_flag;

typedef struct			s_max_l
{
	t_max_len			ino;
	t_max_len			n_lnk;
	t_max_len			uid;
	t_max_len			gid;
	t_max_len			major;
	t_max_len			minor;
	t_max_len			f_size;
}						t_max_l;

typedef struct			s_file
{
	struct stat			st;
	char				*name;
	char				*path;
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
	struct s_max_l		*len;
	struct s_dir		*dir;
	t_bool				display_data;
	t_bool				global_err;
}						t_env;

void					check_argument(char *path, t_env *e, t_bool *end_opt);
void					params_parsing(int ac, char **av, t_env *e);
void					display_total(t_file *lst);
void					dir_lstadd(t_dir **alst, t_flag *flg, char *dir_name);
void					dir_addback(t_dir **alst, char *dir_path);
void					dir_lstdel(t_dir **alst);
t_dir					*new_dirstat(char *dir_path);
void					print_color(char *s, mode_t type, t_bool endl, int opt);
void					print_data(t_env *e, t_bool dir);
void					print_data_endl(t_env *e, t_bool dir);
void					print_first_part(t_env *e, t_bool inoeud_opt);
void					print_mid_part(t_max_l *len, t_stat st, t_bool g_opt);
void					print_end_part(t_env *e, t_stat *st, t_bool is_dir);
void					print_file_lst(t_env *e);
void					print_dir_lst(t_env *e);
void					print_sp(size_t min, t_max_len max, int print);
void					print_iusage(char c);
void					file_lstadd(t_env *e, char *path_name, int dir);
void					file_addback(t_file **alst, t_file *new);
void					file_lstdel(t_file **alst);
t_file					*new_fstat(t_max_l *len, char *path_name,
						t_flag *flg, int dir);
void					convert_rights(mode_t mode);
int						myopendir(t_env *e, char *path, int i);
void					storage_m_len_id(t_max_l *len, t_stat *st,
						t_bool g_opt);
void					storage_maj_min(t_max_l *len, t_stat *st);

#endif
