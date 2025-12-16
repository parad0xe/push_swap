/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 15:01:27 by ldecavel          #+#    #+#             */
/*   Updated: 2025/12/16 13:31:05 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "algorithms.h"
#include "debug.h" // to remove

static void	bucket_range(t_stack *stack, int bucket_size, int *min, int *max)
{
	t_node	*current;
	int		value;

	if (stack->size == 0)
		return ;
	value = list_get_min_greater_than(stack->a, stack->size_a, INT_MIN);
	*min = value;
	current = stack->a;
	while (--bucket_size)
	{
		value = list_get_min_greater_than(stack->a, stack->size_a, value);
		current = current->next;
		if (current == stack->a)
			break ;
	}
	*max = value;
}

static int	target_first_in_range(t_stack *stack, int min, int max)
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

static void	pushb_next_bucket(t_stack *stack, t_info *info, int bucket_size)
{
	int		rt;
	int		range_min;
	int		range_max;

	bucket_range(stack, bucket_size, &range_min, &range_max);
	rt = 0;
	while (rt != INT_MAX && bucket_size--)
	{
		rt = target_first_in_range(stack, range_min, range_max);
		while (rt != INT_MAX && rt > 0)
		{
			if (stack->size_b > 1 && stack->b->value < stack->b->next->value)
				rr(stack, info);
			else
				ra(stack, info);
			rt--;
		}
		while (rt != INT_MAX && rt < 0)
		{
			rra(stack, info);
			rt++;
		}
		pb(stack, info);
	}
}

extern void	medium(t_stack *stack, t_info *info)
{
	int		num_buckets;
	int		bucket_size;

	num_buckets = ft_approximate_sqrt(stack->size);
	bucket_size = ft_ceil((double)stack->size / num_buckets);
	while (num_buckets--)
		pushb_next_bucket(stack, info, bucket_size);
	while (stack->size_b)
		pusha_max(stack, info);
}
