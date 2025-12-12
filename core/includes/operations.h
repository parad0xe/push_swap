/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 19:26:10 by nlallema          #+#    #+#             */
/*   Updated: 2025/12/11 16:44:50 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include <unistd.h>
# include "push_swap.h"
# include "utils.h"
# include "linked_list.h"

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
	NOP,
}	t_operation;

void	sa(t_stack *stack, t_info *info);
void	sb(t_stack *stack, t_info *info);
void	ss(t_stack *stack, t_info *info);

void	pa(t_stack *stack, t_info *info);
void	pb(t_stack *stack, t_info *info);

void	ra(t_stack *stack, t_info *info);
void	rb(t_stack *stack, t_info *info);
void	rr(t_stack *stack, t_info *info);

void	rra(t_stack *stack, t_info *info);
void	rrb(t_stack *stack, t_info *info);
void	rrr(t_stack *stack, t_info *info);

#endif
