/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:44:16 by ldecavel          #+#    #+#             */
/*   Updated: 2025/12/09 17:09:48 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef enum e_flag
{
	SIMPLE = 1 << 0,
	MEDIUM = 1 << 1,
	COMPLEX = 1 << 2,
	ADAPTATIVE = 1 << 3,
	BENCH = 1 << 4,
}	t_flag;

typedef enum e_operation
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
}	t_operation;

typedef struct s_stack
{
	int	*a;
	int	*b;
	int	size;
}		t_stack;

typedef struct s_info
{
	int		operation_count[11];
	double	disorder;
	int		total_count;
	short	flags;
}			t_info;

#endif
