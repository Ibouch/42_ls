/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   storage_m_len_id.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouchla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 22:06:49 by ibouchla          #+#    #+#             */
/*   Updated: 2016/03/13 22:06:53 by ibouchla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static void	storage_gid_len(t_max_l *len, t_stat *st)
{
	struct group	*gid;
	size_t			m_gid;

	if ((gid = getgrgid(st->st_gid)) == NULL)
	{
		m_gid = ft_nbrlen(st->st_gid);
		len->gid = ((m_gid > len->gid) ? m_gid : len->gid);
	}
	else
	{
		m_gid = ft_strlen(gid->gr_name);
		len->gid = ((m_gid > len->gid) ? m_gid : len->gid);
	}
	gid = NULL;
}

void		storage_m_len_id(t_max_l *len, t_stat *st, t_bool g_opt)
{
	struct passwd	*uid;
	size_t			m_uid;

	if (g_opt == FALSE)
	{
		if ((uid = getpwuid(st->st_uid)) == NULL)
		{
			m_uid = ft_nbrlen(st->st_uid);
			len->uid = ((m_uid > len->uid) ? m_uid : len->uid);
		}
		else
		{
			m_uid = ft_strlen(uid->pw_name);
			len->uid = ((m_uid > len->uid) ? m_uid : len->uid);
		}
	}
	storage_gid_len(len, st);
	uid = NULL;
}
