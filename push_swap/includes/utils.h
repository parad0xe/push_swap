/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 21:09:29 by ldecavel          #+#    #+#             */
/*   Updated: 2025/12/10 14:38:57 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>

typedef struct s_dprintf
{
	va_list	param;
	int		n;
	int		current;
}			t_dprintf;

int		ft_dprintf(const char *s, ...) __attribute__((format(printf, 1, 2)));
void	print_stack(t_stack *stack);

#endif
