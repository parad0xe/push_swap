/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 10:27:10 by ldecavel          #+#    #+#             */
/*   Updated: 2025/12/16 14:31:59 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	prep(t_gnl *gnl, t_rest *rest)
{
	*gnl = (t_gnl){0};
	gnl->nread = rest->len;
	if (!rest->len)
		rest->i = 0;
	rest->len = 0;
}

static bool	alloc_l(t_gnl *gnl)
{
	char	*tmp;
	size_t	i;

	if (gnl->nread && !gnl->l)
	{
		gnl->max = gnl->nread;
		gnl->l = malloc(gnl->max + 1);
		if (!gnl->l)
			return (0);
		return (1);
	}
	while (gnl->max <= gnl->nread + gnl->cur + 1)
		gnl->max <<= 1;
	tmp = malloc(gnl->max + 1);
	if (!tmp)
	{
		free(gnl->l);
		return (0);
	}
	i = -1;
	while (++i < gnl->cur)
		tmp[i] = gnl->l[i];
	free(gnl->l);
	gnl->l = tmp;
	return (1);
}

static bool	btol(t_gnl *gnl, t_rest *rest)
{
	bool	f_eol;
	size_t	i;

	f_eol = 0;
	i = 0;
	while (!f_eol && i < (size_t)gnl->nread)
	{
		gnl->l[gnl->cur++] = rest->b[rest->i + i];
		if (rest->b[rest->i + i++] == '\n')
			f_eol = 1;
	}
	if (i < (size_t)gnl->nread)
	{
		rest->len = gnl->nread - i;
		rest->i += i;
	}
	else
	{
		rest->len = 0;
		rest->i = 0;
	}
	gnl->l[gnl->cur] = 0;
	gnl->nread = 0;
	return (f_eol);
}

extern bool	get_next_line(int fd, char **s)
{
	static t_rest	rest[FD_MAX] = {0};
	t_gnl			gnl;

	prep(&gnl, &rest[fd]);
	if (BUFFER_SIZE < 1 || fd < 0 || fd > FD_MAX - 1)
		return (false);
	while (1)
	{
		if (gnl.nread && gnl.max <= gnl.cur + gnl.nread + 1 && !alloc_l(&gnl))
			return (false);
		if (gnl.nread && btol(&gnl, &rest[fd]))
			break ;
		gnl.nread = read(fd, rest[fd].b, BUFFER_SIZE);
		if (gnl.nread < 1)
			break ;
	}
	if ((!gnl.cur && !gnl.nread) || gnl.nread < 0)
		gnl.dup = NULL;
	else
		gnl.dup = malloc(++gnl.cur);
	while (gnl.dup && gnl.cur--)
		gnl.dup[gnl.cur] = gnl.l[gnl.cur];
	free(gnl.l);
	*s = gnl.dup;
	return (true);
}
