/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 19:46:09 by nlallema          #+#    #+#             */
/*   Updated: 2025/12/11 16:41:09 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

extern void	pa(t_stack *stack, t_info *info)
{
	t_node	*node;

	info->operation_count[PA]++;
	ft_dprintf(STDOUT_FILENO, "pa\n");
	if (stack->b != NULL)
	{
		node = list_pop(&stack->b);
		list_push_front(node, &stack->a);
		stack->size_a++;
		stack->size_b--;
	}
}

extern void	pb(t_stack *stack, t_info *info)
{
	t_node	*node;

	info->operation_count[PB]++;
	ft_dprintf(STDOUT_FILENO, "pb\n");
	if (stack->a != NULL)
	{
		node = list_pop(&stack->a);
		list_push_front(node, &stack->b);
		stack->size_a--;
		stack->size_b++;
	}
}
