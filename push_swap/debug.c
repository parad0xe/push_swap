/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:57:23 by nlallema          #+#    #+#             */
/*   Updated: 2025/12/10 16:23:59 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print_stack(t_stack *stack)
{
	t_node	*a_current;
	t_node	*b_current;
	int		i;

	i = -1;
	a_current = stack->a;
	b_current = stack->b;
	printf("+-----------------------+\n");
	printf("|      a    |     b     |\n");
	printf("+-----------------------+\n");
	while (++i < stack->size)
	{
		if (a_current && (a_current != stack->a || i == 0))
		{
			printf("|%11d|", a_current->value);
			a_current = a_current->next;
		}
		else
			printf("|%11s|", " ");
		if (b_current && (b_current != stack->b || i == 0))
		{
			printf("%11d|", b_current->value);
			b_current = b_current->next;
		}
		else
			printf("%11s|", " ");
		printf("\n");
	}
	printf("+-----------------------+\n");
}
