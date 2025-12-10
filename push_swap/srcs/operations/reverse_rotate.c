/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:31:30 by nlallema          #+#    #+#             */
/*   Updated: 2025/12/10 17:05:40 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	rra(t_stack *stack)
{
	ft_printf("rra\n");
	if (stack->a != NULL)
		stack->a = stack->a->previous;
}

void	rrb(t_stack *stack)
{
	ft_printf("rrb\n");
	if (stack->b != NULL)
		stack->b = stack->b->previous;
}

void	rrr(t_stack *stack)
{
	ft_printf("rrr\n");
	if (stack->a != NULL)
		stack->a = stack->a->previous;
	if (stack->b != NULL)
		stack->b = stack->b->previous;
}
