/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:57:23 by nlallema          #+#    #+#             */
/*   Updated: 2025/12/09 18:56:12 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print_stack(t_stacks *stacks)
{
	int	i;

	i = -1;
	printf("+-----------------------+\n");
	printf("|      a    |     b     |\n");
	printf("+-----------------------+\n");
	while (++i < stacks->capacity)
	{
		if (i < stacks->size_a)
			printf("|%11d|", stacks->a[i]);
		else
			printf("|%11s|", " ");
		if (i < stacks->size_b)
			printf("%11d|", stacks->b[i]);
		else
			printf("%11s|", " ");
		printf("\n");
	}
	printf("+-----------------------+\n");
}
