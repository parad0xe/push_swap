/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 14:57:44 by ldecavel          #+#    #+#             */
/*   Updated: 2025/12/16 14:52:45 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHMS_H
# define ALGORITHMS_H

# include <limits.h>
# include "core.h"
# include "operations.h"

# define LEFT	0
# define RIGHT	1

// Algorithms
void	simple(t_stack *stack, t_info *info);
void	medium(t_stack *stack, t_info *info);
void	complex(t_stack *stack, t_info *info);

// Simple
void	target(t_stack *stack, int *rta, int *rtb);
int		target_rotation(t_node *stack, int size, int target_index);

// Medium
int		list_get_min_greater_than(t_node *root, int size, int gt);
void	target_max(t_node *root, int size, t_node **target, bool *direction);
void	pusha_max(t_stack *stack, t_info *info);
int		target_first_in_range(t_stack *stack, int min, int max);

#endif
