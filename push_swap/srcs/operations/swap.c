/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 19:23:46 by nlallema          #+#    #+#             */
/*   Updated: 2025/12/10 16:37:02 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	sa(t_stack *stack)
{
	int		tmp;

	ft_printf("sa\n");
	if (stack->a != NULL && stack->a != stack->a->next)
	{
		tmp = stack->a->value;
		stack->a->value = stack->a->next->value;
		stack->a->next->value = tmp;
	}
}

void	sb(t_stack *stack)
{
	int		tmp;

	ft_printf("sb\n");
	if (stack->b != NULL && stack->b != stack->b->next)
	{
		tmp = stack->b->value;
		stack->b->value = stack->b->next->value;
		stack->b->next->value = tmp;
	}
}

void	ss(t_stack *stack)
{
	int	tmp;

	ft_printf("ss\n");
	if (stack->a != NULL && stack->a != stack->a->next)
	{
		tmp = stack->a->value;
		stack->a->value = stack->a->next->value;
		stack->a->next->value = tmp;
	}
	if (stack->b != NULL && stack->b != stack->b->next)
	{
		tmp = stack->b->value;
		stack->b->value = stack->b->next->value;
		stack->b->next->value = tmp;
	}
}
