/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 13:06:22 by ldecavel          #+#    #+#             */
/*   Updated: 2025/12/10 18:51:52 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "parser.h"

#include "operations.h" // to remove
#include "debug.h" // to remove

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
