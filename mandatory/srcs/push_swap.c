/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 13:06:22 by ldecavel          #+#    #+#             */
/*   Updated: 2025/12/16 14:37:30 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "algorithms.h"
#include "bench.h"
#include "core.h"
#include "parse_input.h"

static void	get_indexes(t_stack *stack)
{
	t_node	*i;
	t_node	*j;
	int		n;
	int		k;

	if (!stack || !stack->a)
		return ;
	n = stack->size_a;
	i = stack->a;
	while (n--)
	{
		j = stack->a;
		k = stack->size_a;
		while (k--)
		{
			if (j->value < i->value)
				i->index++;
			j = j->next;
		}
		i = i->next;
	}
}

static void	adapt_complexity(t_info *info)
{
	if (info->disorder < 0.2)
		info->flags |= SIMPLE;
	else if (info->disorder < 0.5)
		info->flags |= MEDIUM;
	else
		info->flags |= COMPLEX;
}

static double	compute_disorder(t_stack *stack)
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

	parse_input(ac, av, &info, &stack);
	if (info.flags & (BENCH | ADAPTIVE))
		info.disorder = compute_disorder(&stack);
	get_indexes(&stack);
	if (info.flags & ADAPTIVE)
		adapt_complexity(&info);
	if (info.flags & SIMPLE)
		simple(&stack, &info);
	else if (info.flags & MEDIUM)
		medium(&stack, &info);
	else if (info.flags & COMPLEX)
		complex(&stack, &info);
	if (info.flags & BENCH)
		bench(info);
	list_clear(&stack.a);
	list_clear(&stack.b);
	return (0);
}
