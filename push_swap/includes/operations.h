/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 19:26:10 by nlallema          #+#    #+#             */
/*   Updated: 2025/12/10 16:49:08 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "push_swap.h"
# include "utils.h"
# include "linked_list.h"

void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *stack);

void	pa(t_stack *stack);
void	pb(t_stack *stack);

void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_stack *stack);

void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	rrr(t_stack *stack);

#endif
