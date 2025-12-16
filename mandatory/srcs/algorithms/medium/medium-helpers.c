/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium-helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 13:58:34 by nlallema          #+#    #+#             */
/*   Updated: 2025/12/16 14:39:57 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "algorithms.h"

extern int	list_get_min_greater_than(t_node *root, int size, int gt)
{
	int		min;

	min = INT_MAX;
	while (size--)
	{
		if (root->value < min && root->value > gt)
			min = root->value;
		root = root->next;
	}
	return (min);
}

extern void	target_max(t_node *root, int size, t_node **target, bool *direction)
{
	long	max;
	int		stack_size;

	max = INT_MIN;
	stack_size = size;
	while (stack_size--)
	{
		if ((long)root->value > max)
		{
			if (size - stack_size <= size / 2)
				*direction = RIGHT;
			else
				*direction = LEFT;
			max = root->value;
			*target = root;
		}
		root = root->next;
	}
}

extern void	pusha_max(t_stack *stack, t_info *info)
{
	t_node	*max_node;
	bool	direction;

	target_max(stack->b, stack->size_b, &max_node, &direction);
	while (stack->b != max_node)
	{
		if (direction == RIGHT)
			rb(stack, info);
		else if (direction == LEFT)
			rrb(stack, info);
	}
	pa(stack, info);
}

extern int	target_first_in_range(t_stack *stack, int min, int max)
{
	t_node	*root;
	int		distance;
	int		stack_size;

	stack_size = stack->size_a;
	distance = INT_MAX;
	root = stack->a;
	while (root && stack_size-- >= 0)
	{
		if (root->value >= min && root->value <= max)
		{
			if (stack_size < stack->size_a - stack_size)
			{
				if (ft_abs(distance) > stack_size)
					distance = -stack_size - 1;
			}
			else
			{
				if (ft_abs(distance) > stack->size_a - stack_size)
					distance = stack->size_a - stack_size - 1;
			}
		}
		root = root->next;
	}
	return (distance);
}
