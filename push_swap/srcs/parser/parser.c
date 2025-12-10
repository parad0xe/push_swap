/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 10:11:51 by ldecavel          #+#    #+#             */
/*   Updated: 2025/12/10 13:09:52 by ldecavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "parser.h"
#include "utils.h"
#include "linked_list.h"

static void	handle_error(int errcode, t_stack *stack, t_node **table)
{
	size_t	i;

	if (errcode == ERR_AC)
		exit(errcode);
	ft_dprintf(2, "Error\n");
	list_clear(&stack->a);
	i = -1;
	while (++i < HASH_SIZE)
		list_clear(&table[i]);
	exit(errcode);
}

static int	has_duplicata(int value, t_node **table)
{
	t_node	*current;
	int		index;

	index = value & (HASH_SIZE - 1);
	current = table[index];
	while (current)
	{
		if (current->value == value)
			return (ERR_DUPLICATA);
		current = current->next;
	}
	if (!table[index] && !list_push_new(value, &table[index]))
		return (ERR_ALLOC);
	return (NOERR);
}

static void	parse_stack(char *s, t_info *info, t_stack *stack, t_node **table)
{
	size_t	i;
	long	value;
	int		errcode;

	i = -1;
	while (s[++i])
	{
		while (s[i] && is_space(s[i]))
			i++;
		if (!ft_isdigit(s[i]))
			handle_error(ERR_STRING, stack, table);
		value = ft_atol(&s[i]);
		if (value < INT_MIN || value > INT_MAX)
			handle_error(ERR_NOT_INT, stack, table);
		if (!list_push_new(value, &stack->a))
			handle_error(ERR_ALLOC, stack, table);
		errcode = has_duplicata(value, table);
		if (errcode != NOERR)
			handle_error(errcode, stack, table);
		stack->size++;
	}
}

static bool	parse_strategy(char *s, t_info *info)
{
	if (!ft_strcmp(s, "--simple"))
		if ((info->flags & 15) == 0)
			info->flags |= SIMPLE;
	else if (!ft_strcmp(s, "--medium"))
		if ((info->flags & 15) == 0)
			info->flags |= MEDIUM;
	else if (!ft_strcmp(s, "--complex"))
		if ((info->flags & 15) == 0)
			info->flags |= COMPLEX;
	else if (!ft_strcmp(s, "--adaptive"))
		if ((!info->flags & 15))
			info->flags |= ADAPTIVE;
	else if (!ft_strcmp(s, "--bench"))
		info->flags |= BENCH;
	else
		return (false);
	return (true);
}

extern void	parse(int ac, char **av, t_info *info, t_stack *stack)
{
	t_node		*table[HASH_SIZE];
	size_t		i;

	if (ac < 2)
		handle_error(ERR_AC, stack, table);
	ft_memset(table, 0, sizeof(t_table));
	*info = (t_info){0};
	*stack = (t_stack){0};
	i = 0;
	while (++i < ac)
		if (parse_strategy(av[i], info) == false)
			parse_stack(av[i], info, stack, table);
	if ((info->flags & 15) == 0)
		info->flags |= ADAPTIVE;
	i = 0;
	while (++i < HASH_SIZE)
		list_clear(&table[i]);
}
