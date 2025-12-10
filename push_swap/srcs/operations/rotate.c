/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:31:30 by nlallema          #+#    #+#             */
/*   Updated: 2025/12/10 17:05:32 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	ra(t_stack *stack)
{
	ft_printf("ra\n");
	if (stack->a != NULL)
		stack->a = stack->a->next;
}

void	rb(t_stack *stack)
{
	ft_printf("rb\n");
	if (stack->b != NULL)
		stack->b = stack->b->next;
}

void	rr(t_stack *stack)
{
	ft_printf("rr\n");
	if (stack->a != NULL)
		stack->a = stack->a->next;
	if (stack->b != NULL)
		stack->b = stack->b->next;
}
