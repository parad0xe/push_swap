/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 11:34:04 by nlallema          #+#    #+#             */
/*   Updated: 2025/12/11 12:11:16 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "bench.h"

static void	_print_disorder(t_info info)
{
	double	disorder;
	int		decimal;

	disorder = 100. - (info.disorder * 100.);
	decimal = (int)((disorder - (int)disorder) * 100);
	ft_dprintf(2, "[bench] disorder: %d.", (int)disorder);
	if (decimal < 10)
		ft_dprintf(2, "0");
	ft_dprintf(2, "%d%%\n", decimal);
}

static void	_print_strategy(t_info info)
{
	ft_dprintf(2, "[bench] strategy: ");
	if (info.flags & ADAPTIVE && info.flags & SIMPLE)
		ft_dprintf(2, "Adaptive / O(n²)");
	else if (info.flags & ADAPTIVE && info.flags & MEDIUM)
		ft_dprintf(2, "Adaptive / O(n√n)");
	else if (info.flags & ADAPTIVE && info.flags & COMPLEX)
		ft_dprintf(2, "Adaptive / O(n log n)");
	else if (info.flags & SIMPLE)
		ft_dprintf(2, "Simple / O(n²)");
	else if (info.flags & MEDIUM)
		ft_dprintf(2, "Medium / O(n√n)");
	else if (info.flags & COMPLEX)
		ft_dprintf(2, "Complex / O(n log n)");
	ft_dprintf(2, "\n");
}

static void	_print_operation_count(t_info info)
{
	ft_dprintf(2, "[bench] total_ops: %d\n", info.total_count);
	ft_dprintf(2, "[bench] sa: %d ", info.operation_count[SA]);
	ft_dprintf(2, "sb: %d ", info.operation_count[SB]);
	ft_dprintf(2, "ss: %d ", info.operation_count[SS]);
	ft_dprintf(2, "pa: %d ", info.operation_count[PA]);
	ft_dprintf(2, "pb: %d\n", info.operation_count[PB]);
	ft_dprintf(2, "[bench] ra: %d ", info.operation_count[RA]);
	ft_dprintf(2, "rb: %d ", info.operation_count[RB]);
	ft_dprintf(2, "rr: %d ", info.operation_count[RR]);
	ft_dprintf(2, "rra: %d ", info.operation_count[RRA]);
	ft_dprintf(2, "rrb: %d ", info.operation_count[RRB]);
	ft_dprintf(2, "rrr: %d\n", info.operation_count[RRR]);
}

extern void	bench(t_info info)
{
	_print_disorder(info);
	_print_strategy(info);
	_print_operation_count(info);
}
