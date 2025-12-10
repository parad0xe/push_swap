/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 19:46:09 by nlallema          #+#    #+#             */
/*   Updated: 2025/12/10 18:13:40 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

extern void	pa(t_stack *stack)
{
	t_node	*node;

	ft_dprintf(stdout, "pa\n");
	if (stack->b != NULL)
	{
		node = list_pop(&stack->b);
		list_push(node, &stack->a);
	}
}

extern void	pb(t_stack *stack)
{
	t_node	*node;

	ft_dprintf(stdout, "pb\n");
	if (stack->a != NULL)
	{
		node = list_pop(&stack->a);
		list_push(node, &stack->b);
	}
}
