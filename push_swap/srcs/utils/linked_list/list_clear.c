/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 14:50:34 by nlallema          #+#    #+#             */
/*   Updated: 2025/12/10 17:38:12 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

extern void	list_clear(t_node **root)
{
	t_node	*current;
	t_node	*next;

	if (*root == NULL)
		return ;
	next = (*root)->next;
	while (next && next != *root)
	{
		current = next;
		next = current->next;
		free(current);
	}
	free(*root);
}
