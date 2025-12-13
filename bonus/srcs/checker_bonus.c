/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 14:17:19 by ldecavel          #+#    #+#             */
/*   Updated: 2025/12/13 20:35:20 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" // maybe some of them are useless
#include "operations.h"
#include "checker_bonus.h"
#include "parse_input.h"
#include "parse_stdin_bonus.h"
#include "utils.h"

#include <limits.h> // vraiment on doit ranger

static bool	is_sorted(t_stack *stack)
{
	t_node	*start;
	int		last_value;

	if (stack->b)
		return (false);
	last_value = INT_MIN;
	start = stack->a;
	while (true)
	{
		if (last_value > stack->a->value)
			return (false);
		last_value = stack->a->value;
		stack->a = stack->a->next;
		if (stack->a == start)
			break ;
	}
	return (true);
}

static void run_instructions(t_stack *stack, t_info *info, t_node *instructions)
{
	t_node						*start;
	static t_operation_function	operations[] = {
		sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr
	};

	start = instructions;
	while (true)
	{
		operations[instructions->value](stack, info);
		instructions = instructions->next;
		if (instructions == start)
			break ;
	}
}

int	main(int ac, char **av)
{
	t_info	info;
	t_stack	stack;
	t_node	*instructions;
	int		return_value;

	info = (t_info){0};
	stack = (t_stack){0};
	instructions = 0;
	parse_input(ac, av, &info, &stack);
	parse_stdin(&instructions, &stack);
	run_instructions(&stack, &info, instructions);
	list_clear(&instructions);
	if (is_sorted(&stack))
	{
		ft_dprintf(1, "OK\n");
		return_value = 0;
	}
	else
	{
		ft_dprintf(1, "KO\n");
		return_value = 1;
	}
	list_clear(&stack.a);
	list_clear(&stack.b);
	return (return_value);
}
