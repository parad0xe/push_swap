/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 13:06:22 by ldecavel          #+#    #+#             */
/*   Updated: 2025/12/11 12:11:25 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "parser.h"

#include "utils.h"
#include "bench.h"

#include "operations.h" // to remove
#include "debug.h" // to remove

static void	adapt_complexity(t_info *info)
{
	if (info->disorder < 0.2)
		info->flags |= SIMPLE;
	else if (info->disorder < 0.5)
		info->flags |= MEDIUM;
	else
		info->flags |= COMPLEX;
}

static double	_compute_disorder(t_stack *stack)
{
	double	mistakes;
	double	total_pairs;
	t_node	*current;
	t_node	*sub_current;

	if (!stack || stack->a == NULL)
		return (0.);
	total_pairs = 0;
	mistakes = 0;
	current = stack->a;
	while (current->next != stack->a)
	{
		sub_current = current->next;
		while (sub_current != stack->a)
		{
			total_pairs++;
			if (current->value > sub_current->value)
				mistakes++;
			sub_current = sub_current->next;
		}
		current = current->next;
	}
	if (total_pairs == 0)
		return (0.);
	return (mistakes / total_pairs);
}

int	main(int ac, char **av)
{
	t_info	info;
	t_stack	stack;

	parse(ac, av, &info, &stack);
	if (info.flags & (BENCH | ADAPTIVE))
		info.disorder = _compute_disorder(&stack);
	if (info.flags & ADAPTIVE)
		adapt_complexity(&info);
	// choose and run algorithm
	if (info.flags & BENCH)
		bench(info);
	print_stack(&stack);
	list_clear(&stack.a);
	list_clear(&stack.b);
	return (0);
}
