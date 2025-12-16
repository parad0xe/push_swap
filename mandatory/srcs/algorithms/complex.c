/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 13:49:17 by nlallema          #+#    #+#             */
/*   Updated: 2025/12/16 21:45:53 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithms.h"

static void	target_min(t_stack *stack, t_node **target, bool *direction)
{
	t_node	*current;
	long	min;
	int		target_index;
	int		index;

	min = LONG_MAX;
	target_index = 0;
	index = 0;
	current = stack->a;
	while (current != stack->a || index == 0)
	{
		if ((long)current->value < min)
		{
			target_index = index;
			min = current->value;
			*target = current;
		}
		current = current->next;
		index++;
	}
	if (stack->size_a - target_index > target_index)
		*direction = RIGHT;
	else
		*direction = LEFT;
}

extern void	complex(t_stack *stack, t_info *info)
{
	t_node	*target;
	bool	direction;

	while (stack->size_a)
	{
		target_min(stack, &target, &direction);
		while (stack->a != target)
		{
			if (direction == RIGHT)
				ra(stack, info);
			else if (direction == LEFT)
				rra(stack, info);
		}
		pb(stack, info);
	}
	while (stack->b)
		pa(stack, info);
}
