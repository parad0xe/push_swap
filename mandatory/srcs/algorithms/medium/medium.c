/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 15:01:27 by ldecavel          #+#    #+#             */
/*   Updated: 2026/01/01 18:24:46 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "algorithms.h"

static void	apply_rot_step(t_stack *stack, t_info *info, int bi, int bs)
{
	t_node	*target;
	int		rt;

	rt = target_bucket(stack->a, stack->size_a, bi, bs);
	target = get_node_at(stack->a, rt);
	if (rt == 1 && stack->size_b > 1 && target->index > stack->b->index \
&& stack->b->index < stack->b->next->index \
&& stack->b->next->index / bs == bi)
		ss(stack, info);
	else if (stack->size_b > 1 && target->index > stack->b->index \
&& stack->b->index < stack->b->next->index \
&& stack->b->next->index / bs == bi)
		rr(stack, info);
	else if (stack->size_b > 1 && target->index < stack->b->next->index \
&& stack->b->index < stack->b->previous->index \
&& stack->b->next->index / bs == bi)
		rr(stack, info);
	else
		ra(stack, info);
}

static void	pushb_bucket(t_stack *stack, t_info *info, int bi, int bs)
{
	int		rt;

	while (stack->size_a)
	{
		rt = target_bucket(stack->a, stack->size_a, bi, bs);
		if (rt == INT_MAX)
			break ;
		if (rt > 0)
			apply_rot_step(stack, info, bi, bs);
		else if (rt < 0)
			rra(stack, info);
		else
			pb(stack, info);
	}
}

extern void	medium(t_stack *stack, t_info *info)
{
	int	bucket_size;
	int	current_bucket;

	bucket_size = ((double)approximate_sqrt(stack->size) * 1.8);
	if (bucket_size == 0)
		bucket_size = 1;
	current_bucket = -1;
	while (++current_bucket <= stack->size / bucket_size)
		pushb_bucket(stack, info, current_bucket, bucket_size);
	while (stack->size_b)
		pusha_max(stack, info);
}
