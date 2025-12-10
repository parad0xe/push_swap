/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:31:30 by nlallema          #+#    #+#             */
/*   Updated: 2025/12/10 18:14:43 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

extern void	ra(t_stack *stack)
{
	ft_dprintf(stdout, "ra\n");
	if (stack->a != NULL)
		stack->a = stack->a->next;
}

extern void	rb(t_stack *stack)
{
	ft_dprintf(stdout, "rb\n");
	if (stack->b != NULL)
		stack->b = stack->b->next;
}

extern void	rr(t_stack *stack)
{
	ft_dprintf(stdout, "rr\n");
	if (stack->a != NULL)
		stack->a = stack->a->next;
	if (stack->b != NULL)
		stack->b = stack->b->next;
}
