/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_stdin_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 18:39:55 by ldecavel          #+#    #+#             */
/*   Updated: 2025/12/16 14:43:41 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parse_stdin_bonus.h"

static void	handle_error(int errcode, t_stack *stack, t_node **instructions)
{
	ft_dprintf(2, "Error\n");
	list_clear(&stack->a);
	list_clear(instructions);
	exit(errcode);
}

static int	get_instruction(char *buffer)
{
	if (!ft_strcmp("sa\n", buffer))
		return (SA);
	else if (!ft_strcmp("sb\n", buffer))
		return (SB);
	else if (!ft_strcmp("ss\n", buffer))
		return (SS);
	else if (!ft_strcmp("pa\n", buffer))
		return (PA);
	else if (!ft_strcmp("pb\n", buffer))
		return (PB);
	else if (!ft_strcmp("ra\n", buffer))
		return (RA);
	else if (!ft_strcmp("rb\n", buffer))
		return (RB);
	else if (!ft_strcmp("rr\n", buffer))
		return (RR);
	else if (!ft_strcmp("rra\n", buffer))
		return (RRA);
	else if (!ft_strcmp("rrb\n", buffer))
		return (RRB);
	else if (!ft_strcmp("rrr\n", buffer))
		return (RRR);
	else
		return (-1);
}

extern void	parse_stdin(t_node **instructions, t_stack *stack)
{
	char	*buffer;
	int		operation;

	operation = 0;
	while (true)
	{
		if (!get_next_line(0, &buffer))
			handle_error(ERR_ALLOC, stack, instructions);
		if (buffer == NULL)
			break ;
		operation = get_instruction(buffer);
		free(buffer);
		if (operation == -1)
			handle_error(ERR_INSTRUCTION, stack, instructions);
		if (!list_push_back_new(operation, instructions))
			handle_error(ERR_ALLOC, stack, instructions);
	}
}
