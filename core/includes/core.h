/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:44:16 by ldecavel          #+#    #+#             */
/*   Updated: 2025/12/16 14:51:57 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
# define CORE_H

# include "linked_list.h"

typedef enum e_flag
{
	SIMPLE = 1 << 0,
	MEDIUM = 1 << 1,
	COMPLEX = 1 << 2,
	ADAPTIVE = 1 << 3,
	BENCH = 1 << 4,
}	t_flag;

typedef struct s_stack
{
	t_node	*a;
	t_node	*b;
	int		size;
	int		size_a;
	int		size_b;
}		t_stack;

typedef struct s_info
{
	int		operation_count[12];
	double	disorder;
	int		total_count;
	short	flags;
}			t_info;

#endif
