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

typedef struct			s_flg
{
	char				aff;
	t_bool				all;
	t_bool				rec;
	t_bool				rev;
	t_bool				t;
}						t_flg;

typedef struct			s_env
{
	DIR					*dir;
	struct s_flg		*flg;
	struct s_err		*err;
	t_list				*file;
	t_dir				*e_dir;
}						t_env;
void					params_parsing(int ac, char **av, t_env *e);
void					print_lst_err(t_list *lst);
void					delimit_flags(t_env *e);

#endif
