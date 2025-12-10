/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_pop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlallema <nlallema@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 14:50:03 by nlallema          #+#    #+#             */
/*   Updated: 2025/12/10 16:45:28 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

t_node	*list_pop(t_node **node)
{
	t_node	*current;

	if (!node || *node == NULL)
		return (NULL);
	current = *node;
	(*node)->next->previous = (*node)->previous;
	(*node)->previous->next = (*node)->next;
	if ((*node)->next == *node)
		*node = NULL;
	else
		*node = (*node)->next;
	current->previous = current;
	current->next = current;
	return (current);
}
