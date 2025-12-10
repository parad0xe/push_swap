/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 13:06:22 by ldecavel          #+#    #+#             */
/*   Updated: 2025/12/10 20:27:21 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "parser.h"

#include "operations.h" // to remove
#include "debug.h" // to remove

static double	_compute_disorder(t_stack *stack)
{
	int		mistakes;
	int		total_pairs;
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
		while (sub_current->next != stack->a)
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
	print_stack(&stack); // to del
	pa(&stack);
	print_stack(&stack);
	sa(&stack);
	print_stack(&stack);
	pa(&stack);
	print_stack(&stack);
	pa(&stack);
	print_stack(&stack);
	pa(&stack);
	print_stack(&stack);
	pb(&stack);
	print_stack(&stack);
	ra(&stack);
	print_stack(&stack);
	pb(&stack);
	print_stack(&stack);
	rb(&stack);
	print_stack(&stack);
	rr(&stack);
	print_stack(&stack);
	rrr(&stack);
	print_stack(&stack);
	list_clear(&stack.a);
	list_clear(&stack.b);
	return (0);
}
