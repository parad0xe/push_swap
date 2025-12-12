/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:31:30 by nlallema          #+#    #+#             */
/*   Updated: 2025/12/11 16:38:37 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

extern void	ra(t_stack *stack, t_info *info)
{
	info->operation_count[RA]++;
	if (PRINT_OPERATION == true)
		ft_dprintf(STDOUT_FILENO, "ra\n");
	if (stack->a != NULL)
		stack->a = stack->a->next;
}

extern void	rb(t_stack *stack, t_info *info)
{
	info->operation_count[RB]++;
	if (PRINT_OPERATION == true)
		ft_dprintf(STDOUT_FILENO, "rb\n");
	if (stack->b != NULL)
		stack->b = stack->b->next;
}

extern void	rr(t_stack *stack, t_info *info)
{
	info->operation_count[RR]++;
	if (PRINT_OPERATION == true)
		ft_dprintf(STDOUT_FILENO, "rr\n");
	if (stack->a != NULL)
		stack->a = stack->a->next;
	if (stack->b != NULL)
		stack->b = stack->b->next;
}
