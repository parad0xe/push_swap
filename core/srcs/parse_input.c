/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 10:11:51 by ldecavel          #+#    #+#             */
/*   Updated: 2025/12/16 14:33:38 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parse_input.h"

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
		if (current == table[index])
			break ;
	}
	if (!list_push_back_new(value, &table[index]))
		return (ERR_ALLOC);
	return (NOERR);
}

static void	parse_stack(char *s, t_stack *stack, t_node **table)
{
	size_t	i;
	long	value;
	int		errcode;

	i = -1;
	while (s[++i])
	{
		while (s[i] && ft_isspace(s[i]))
			i++;
		if (!s[i])
			break ;
		if (!ft_isdigit(s[i]) && !(ft_isdigit(s[i + 1]) && ft_issign(s[i])))
			handle_error(ERR_STRING, stack, table);
		value = ft_atol(&s[i]);
		while (s[i + 1] && (ft_issign(s[i]) || ft_isdigit(s[i])))
			i++;
		if (value < INT_MIN || value > INT_MAX)
			handle_error(ERR_NOT_INT, stack, table);
		if (!list_push_back_new(value, &stack->a))
			handle_error(ERR_ALLOC, stack, table);
		errcode = has_duplicata(value, table);
		if (errcode != NOERR)
			handle_error(errcode, stack, table);
		stack->size++;
	}
}

static bool	parse_strategy(char *s, t_info *info)
{
	if (((!ft_strcmp(s, "--simple") && (info->flags & 15) == 0)
			|| (!ft_strcmp(s, "--simple") && info->flags & SIMPLE))
		&& PARSE_STRATEGY == true)
		info->flags |= SIMPLE;
	else if (((!ft_strcmp(s, "--medium") && (info->flags & 15) == 0)
			|| (!ft_strcmp(s, "--medium") && info->flags & MEDIUM))
		&& PARSE_STRATEGY == true)
		info->flags |= MEDIUM;
	else if (((!ft_strcmp(s, "--complex") && (info->flags & 15) == 0)
			|| (!ft_strcmp(s, "--complex") && info->flags & COMPLEX))
		&& PARSE_STRATEGY == true)
		info->flags |= COMPLEX;
	else if (((!ft_strcmp(s, "--adaptive") && (info->flags & 15) == 0)
			|| (!ft_strcmp(s, "--adaptive") && info->flags & ADAPTIVE))
		&& PARSE_STRATEGY == true)
		info->flags |= ADAPTIVE;
	else if (!ft_strcmp(s, "--bench")
		&& PARSE_STRATEGY == true)
		info->flags |= BENCH;
	else
		return (false);
	return (true);
}

extern void	parse_input(size_t ac, char **av, t_info *info, t_stack *stack)
{
	t_node		*table[HASH_SIZE];
	size_t		i;

	if (ac < 2)
		handle_error(ERR_AC, stack, table);
	ft_memset(table, 0, sizeof(table));
	*info = (t_info){0};
	*stack = (t_stack){0};
	i = 0;
	while (++i < ac)
		if (parse_strategy(av[i], info) == false)
			parse_stack(av[i], stack, table);
	if ((info->flags & 15) == 0)
		info->flags |= ADAPTIVE;
	i = -1;
	while (++i < HASH_SIZE)
		list_clear(&table[i]);
	stack->size_a = stack->size;
}
