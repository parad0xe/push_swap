/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 19:53:05 by ldecavel          #+#    #+#             */
/*   Updated: 2025/12/14 23:10:30 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithms.h"
#include "utils.h"

static void	min_target(t_stack *stack, t_node **target)
{
	t_node	*a;
	int		min;

	min = INT_MAX;
	a = stack->a;
	while (a)
	{
		if (a->index < min)
		{
			min = a->index;
			*target = a;
		}
		a = a->next;
		if (a == stack->a)
			break ;
	}
}

static void	get_target(t_stack *stack, t_node **target, int b_index)
{
	t_node	*a;
	int		best;

	best = INT_MAX;
	a = stack->a;
	while (a)
	{
		if (a->index > b_index && a->index < best)
		{
			best = a->index;
			*target = a;
		}
		a = a->next;
		if (a == stack->a)
			break ;
	}
	if (!*target)
		min_target(stack, target);
}

static int	alternative_score(int size, int *r, int r2, int score)
{
	int	tmp;
	int	alternative_score;

	tmp = *r;
	if (*r > 0)
		tmp -= size;
	else if (*r < 0)
		tmp += size;
	if ((tmp <= 0 && r2 <= 0) || (tmp >= 0 && r2 >= 0))
		alternative_score = max(ft_abs(tmp), ft_abs(r2));
	else
		alternative_score = ft_abs(tmp) + ft_abs(r2);
	if (alternative_score < score)
	{
		*r = tmp;
		return (alternative_score);
	}
	return (score);
}

static int	get_score(t_stack *stack, int b_index, int *rta, int *rtb)
{
	t_node	*target;
	int		score;

	target = NULL;
	get_target(stack, &target, b_index);
	*rta = target_rotation(stack->a, stack->size_a, target->index);
	*rtb = target_rotation(stack->b, stack->size_b, b_index);
	if ((*rta <= 0 && *rtb <= 0) || (*rta >= 0 && *rtb >= 0))
		score = max(ft_abs(*rta), ft_abs(*rtb));
	else
		score = ft_abs(*rta) + ft_abs(*rtb);
	score = alternative_score(stack->size_a, rta, *rtb, score);
	score = alternative_score(stack->size_b, rtb, *rta, score);
	return (score);
}

extern void	target(t_stack *stack, int *rta, int *rtb)
{
	t_node	*current;
	int		score;
	int		min;
	int		min_index;

	min = INT_MAX;
	current = stack->b;
	while (current)
	{
		score = get_score(stack, current->index, rta, rtb);
		if (score < min)
		{
			min = score;
			min_index = current->index;
		}
		current = current->next;
		if (current == stack->b)
			break ;
	}
	get_score(stack, min_index, rta, rtb);
}
