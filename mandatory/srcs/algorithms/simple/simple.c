/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 18:32:55 by ldecavel          #+#    #+#             */
/*   Updated: 2025/12/16 21:46:09 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithms.h"

static void	merge_rotate(t_stack *stack, t_info *info, int *rta, int *rtb)
{
	while (*rta > 0 && *rtb > 0)
	{
		rr(stack, info);
		(*rta)--;
		(*rtb)--;
	}
	while (*rta < 0 && *rtb < 0)
	{
		rrr(stack, info);
		(*rta)++;
		(*rtb)++;
	}
}

static void	rotate(t_stack *stack, t_info *info, int rta, int rtb)
{
	merge_rotate(stack, info, &rta, &rtb);
	while (rta > 0)
	{
		ra(stack, info);
		rta--;
	}
	while (rta++ < 0)
		rra(stack, info);
	while (rtb > 0)
	{
		rb(stack, info);
		rtb--;
	}
	while (rtb++ < 0)
		rrb(stack, info);
}

extern int	target_rotation(t_node *stack, int size, int target_index)
{
	t_node	*current;
	int		r;

	r = 0;
	current = stack;
	while (current->index != target_index)
	{
		current = current->next;
		r++;
	}
	if (size - r > r)
		return (r);
	else
		return (0 - (size - r));
}

extern void	simple(t_stack *stack, t_info *info)
{
	int	n;
	int	rta;
	int	rtb;

	n = stack->size_a;
	while (n-- > 2)
	{
		pb(stack, info);
		if (stack->b->index <= stack->size / 2)
			rb(stack, info);
	}
	if (stack->a->index > stack->a->next->index)
		ra(stack, info);
	while (stack->size_b)
	{
		target(stack, &rta, &rtb);
		rotate(stack, info, rta, rtb);
		pa(stack, info);
	}
	rta = target_rotation(stack->a, stack->size_a, 0);
	rotate(stack, info, rta, 0);
}
