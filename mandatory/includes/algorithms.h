/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 14:57:44 by ldecavel          #+#    #+#             */
/*   Updated: 2025/12/11 14:59:58 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHMS_H
# define ALGORITHMS_H

# include "push_swap.h"
# include "operations.h"
# include <limits.h>

# define LEFT	0
# define RIGHT	1

void	simple(t_stack *stack, t_info *info);
void	medium(t_stack *stack, t_info *info);
void	complex(t_stack *stack, t_info *info);

#endif
