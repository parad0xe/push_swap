/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_stdin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 18:39:55 by ldecavel          #+#    #+#             */
/*   Updated: 2025/12/12 18:41:35 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" // maybe some of them are useless
#include "operations.h"
#include "checker.h"
#include "utils.h"
#include "parse_input.h" //pour les errcodes

static void	handle_error(int errcode, t_stack *stack, t_node **instructions)
{
	ft_dprintf(2, "Error\n");
	list_clear(&stack->a);
	list_clear(instructions);
	exit(errcode);
}

static int	get_instruction(char buffer[BUFFER_SIZE])
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
		return (NOP);
}

extern void	parse_stdin(t_node **instructions, t_stack *stack)
{
	int		nread;
	char	buffer[BUFFER_SIZE];
	int		operation;

	operation = 0;
	while (true)
	{
		nread = read(0, buffer, BUFFER_SIZE);
		if (nread < 1)
			break ;
		while (nread < BUFFER_SIZE)
			buffer[nread++] = 0;
		buffer[nread] = 0;
		operation = get_instruction(buffer);
		if (operation == NOP)
			handle_error(ERR_INSTRUCTION, stack, instructions);
		if (!list_push_back_new(operation, instructions))
			handle_error(ERR_ALLOC, stack, instructions);
	}
}
