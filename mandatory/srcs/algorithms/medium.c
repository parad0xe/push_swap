/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 15:01:27 by ldecavel          #+#    #+#             */
/*   Updated: 2025/12/15 14:13:10 by nlallema         ###   ########lyon.fr   */
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

static void	pushb_next_bucket(t_stack *stack, t_info *info, int bucket_size)
{
	t_node	*root;
	int		range_min;
	int		range_max;
	int		stack_size;

	bucket_range(stack, bucket_size, &range_min, &range_max);
	stack_size = stack->size_a;
	root = stack->a->previous;
	while (stack_size-- >= 0)
	{
		if (root->value >= range_min && root->value <= range_max)
			break ;
		root = root->previous;
	}
	while (stack_size-- >= 0)
	{
		if (stack->a->value >= range_min && stack->a->value <= range_max)
			pb(stack, info);
		else if (stack->size_b > 1 && stack->b->value < stack->b->next->value)
			rr(stack, info);
		else
			ra(stack, info);
	}
}

extern void	medium(t_stack *stack, t_info *info)
{
	int		num_buckets;
	int		bucket_size;

	num_buckets = ft_approximate_sqrt(stack->size);
	bucket_size = ft_ceil((double)stack->size / num_buckets);
	while (num_buckets--)
	{
		pushb_next_bucket(stack, info, bucket_size);
		//print_stack(stack);
		//exit(1);
	}
	//print_stack(stack);
	while (stack->size_b)
		pusha_max(stack, info);
	//print_stack(stack);
}
