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
//include avec ft_strcmp
//include avec ft_isspace
//include avec ft_isdigit
//include avec ft_atol
//include avec ft_dprintf

static void	handle_error(int errcode, t_stack *stack)
{
	if (errcode == ERR_STRING || errcode == ERR_NOT_INT || errcode == ERR_ALLOC)
	{
		ft_dprintf(2, "Error\n");
		list_clear(&stack->a);
	}
	exit(errcode);
}

static void	parse_stack(char *s, t_info *info, t_stack *stack)
{
	size_t	i;
	long	value;

	i = -1;
	while (s[++i])
	{
		while (s[i] && s[i] == is_space(s[i]))
			i++;
		if (!ft_isdigit(s[i]))
			handle_error(ERR_STRING, &stack);
		value = ft_atol(s[i]);
		if (value < INT_MIN || value > INT_MAX)
			handle_error(ERR_NOT_INT, &stack);
		if (!list_front(value, &stack->a))
			handle_error(ERR_ALLOC, &stack);
		//add to hashmap to check duplicatas
		stack->size++;
	}
	return (true);
}

static bool	parse_strategy(char *s, t_info *info)
{
	if (!ft_strcmp(s, "--simple"))
		if (!info->flags & 15)
			info->flags |= SIMPLE;
	else if (!ft_strcmp(s, "--medium"))
		if (!info->flags & 15)
			info->flags |= MEDIUM;
	else if (!ft_strcmp(s, "--complex"))
		if (!info->flags & 15)
			info->flags |= COMPLEX;
	else if (!ft_strcmp(s, "--adaptive"))
		if (!info->flags & 15)
			info->flags |= ADAPTIVE;
	else if (!ft_strcmp(s, "--bench"))
		info->flags |= BENCH;
	else
		return (false);
	return (true);
}

extern void	parse(int ac, char **av, &info, &stack)
{
	size_t	i;

	*info = {0};
	*stack = {0};
	if (ac < 2)
		handle_error(ERR_AC, stack);
	i = 0;
	while (++i < ac)
		if (parse_strategy(av[i], info) == false)
			parse_stack(av[i], info, stack);
	if (!info->flags & 15)
		info->flags |= ADAPTIVE;
}
