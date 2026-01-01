/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 19:23:46 by nlallema          #+#    #+#             */
/*   Updated: 2026/01/01 16:14:16 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

extern void	sa(t_stack *stack, t_info *info)
{
	int		tmp;

	info->operation_count[SA]++;
	if (PRINT_OPERATION == true)
		ft_dprintf(STDOUT_FILENO, "sa\n");
	if (stack->a != NULL && stack->a != stack->a->next)
	{
		tmp = stack->a->value;
		stack->a->value = stack->a->next->value;
		stack->a->next->value = tmp;
		tmp = stack->a->index;
		stack->a->index = stack->a->next->index;
		stack->a->next->index = tmp;
	}
}

extern void	sb(t_stack *stack, t_info *info)
{
	int		tmp;

	info->operation_count[SB]++;
	if (PRINT_OPERATION == true)
		ft_dprintf(STDOUT_FILENO, "sb\n");
	if (stack->b != NULL && stack->b != stack->b->next)
	{
		tmp = stack->b->value;
		stack->b->value = stack->b->next->value;
		stack->b->next->value = tmp;
		tmp = stack->b->index;
		stack->b->index = stack->b->next->index;
		stack->b->next->index = tmp;
	}
}

extern void	ss(t_stack *stack, t_info *info)
{
	int	tmp;

	info->operation_count[SS]++;
	if (PRINT_OPERATION == true)
		ft_dprintf(STDOUT_FILENO, "ss\n");
	if (stack->a != NULL && stack->a != stack->a->next)
	{
		tmp = stack->a->value;
		stack->a->value = stack->a->next->value;
		stack->a->next->value = tmp;
		tmp = stack->a->index;
		stack->a->index = stack->a->next->index;
		stack->a->next->index = tmp;
	}
	if (stack->b != NULL && stack->b != stack->b->next)
	{
		tmp = stack->b->value;
		stack->b->value = stack->b->next->value;
		stack->b->next->value = tmp;
		tmp = stack->b->index;
		stack->b->index = stack->b->next->index;
		stack->b->next->index = tmp;
	}
}
