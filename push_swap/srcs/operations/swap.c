/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 19:23:46 by nlallema          #+#    #+#             */
/*   Updated: 2025/12/10 18:14:48 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

extern void	sa(t_stack *stack)
{
	int		tmp;

	ft_dprintf(stdout, "sa\n");
	if (stack->a != NULL && stack->a != stack->a->next)
	{
		tmp = stack->a->value;
		stack->a->value = stack->a->next->value;
		stack->a->next->value = tmp;
	}
}

extern void	sb(t_stack *stack)
{
	int		tmp;

	ft_dprintf(stdout, "sb\n");
	if (stack->b != NULL && stack->b != stack->b->next)
	{
		tmp = stack->b->value;
		stack->b->value = stack->b->next->value;
		stack->b->next->value = tmp;
	}
}

extern void	ss(t_stack *stack)
{
	int	tmp;

	ft_dprintf(stdout, "ss\n");
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
