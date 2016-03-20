/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_fstat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 22:03:04 by ibouchla          #+#    #+#             */
/*   Updated: 2016/03/13 22:03:09 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static void	storage_max_len(t_max_l *len, t_stat *st, t_flag *flg)
{
	size_t	m_ino;
	size_t	m_nlnk;
	size_t	m_fsize;

	m_ino = ft_nbrlen(st->st_ino);
	m_nlnk = ft_nbrlen(st->st_nlink);
	m_fsize = ft_nbrlen(st->st_size);
	if (flg->i == TRUE)
		len->ino = ((m_ino > len->ino) ? m_ino : len->ino);
	len->n_lnk = ((m_nlnk > len->n_lnk) ? m_nlnk : len->n_lnk);
	storage_m_len_id(len, st, flg->g);
	if (((S_ISBLK(st->st_mode)) == TRUE || (S_ISCHR(st->st_mode)) == TRUE))
		storage_maj_min(len, st);
	else
		len->f_size = ((m_fsize > len->f_size) ? m_fsize : len->f_size);
}

static char	*storage_name(char *path_name)
{
	char	*name;

	name = ft_strrchr(path_name, '/');
	if (name != NULL && ++name != NULL)
		return (ft_strdup(name));
	return (ft_strdup(path_name));
}

t_file		*new_fstat(t_max_l *len, char *path_name, t_flag *flg, int dir)
{
	t_file			*new_node;
	t_stat			st;

	if ((new_node = (t_file *)ft_memalloc(sizeof(t_file))) == NULL)
		ft_error_system();
	if ((lstat(path_name, &st)) != 0)
	{
		ft_putstr_fd("ft_ls: ", 2);
		perror(storage_name(path_name));
		free(new_node);
		return (NULL);
	}
	new_node->st = st;
	if ((new_node->name = storage_name(path_name)) == NULL)
		ft_error_system();
	if ((new_node->path = ft_strdup(path_name)) == NULL)
		ft_error_system();
	if (dir == TRUE)
		ft_strdel(&path_name);
	if (flg->aff == 'l')
		storage_max_len(len, &st, flg);
	new_node->next = NULL;
	return (new_node);
}
