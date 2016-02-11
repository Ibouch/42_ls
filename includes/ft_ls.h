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
typedef struct stat		t_st;

typedef struct			s_err
{
	struct s_err		*next;
	char				*str;
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
int	ft_str_sort_ascii(char **tab, int len);
void	ft_swap_str(char *s1, char *s2);

#endif
