/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 21:09:29 by ldecavel          #+#    #+#             */
/*   Updated: 2025/12/16 14:55:22 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>
# include <stddef.h>
# include <stdbool.h>
# include <stdlib.h>
# include <limits.h>
# include "core.h"

typedef struct s_dprintf
{
	va_list	param;
	int		n;
	int		current;
}			t_dprintf;

# define FD_MAX			1024
# define BUFFER_SIZE	4096

typedef struct s_rest
{
	char	b[BUFFER_SIZE];
	size_t	len;
	size_t	i;
}			t_rest;

typedef struct s_gnl
{
	char	*l;
	char	*dup;
	ssize_t	nread;
	size_t	cur;
	size_t	max;
}			t_gnl;

bool	get_next_line(int fd, char **s);
int		approximate_sqrt(int value);
int		ft_ceil(double value);
int		ft_dprintf(int fd, const char *s, ...);
long	ft_atol(const char *s);
bool	ft_isdigit(int c);
bool	ft_issign(int c);
bool	ft_isspace(int c);
int		ft_strcmp(const char *s1, const char *s2);
void	*ft_memset(void *s, int c, size_t n);
int		max(int a, int b);
int		ft_abs(int x);

#endif
